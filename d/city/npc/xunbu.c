// xunbu.c
//modify by Ronger 11/98

#include <ansi.h>

inherit NPC;

int waiting(object me,object dest);
int checking(object me, object dest);
int do_hit(object me, object dest);

nosave int time;

void create()
{
	set_name("Ѳ��", ({ "xunbu" }) );
	set("title", HIY "���ݲ���" NOR);
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 30);
	set("str", 30);
	set("con", 30);
        set("int", 20);
	set("dex", 30);
	set("no_clean_up",0);

	set("long",
		"����������ʹ������ר�����ۡ�\n" );

	set("combat_exp",500000);
	set("shen",5000);
	set("attitude", "heroism");

	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
        set("max_neili", 1000);
	set("force_factor", 120);
	set("env/wimpy", 40);
	set("jiali", 40);

	set_skill("force", 200); 
	set_skill("unarmed",120);
	set_skill("sword", 120);
	set_skill("taiji-shengong", 20);
	set_skill("dodge", 120);
	set_skill("parry", 120);

	map_skill("force","taiji-shengong");

	setup();

	set("chat_chance", 30);
	set("chat_msg", ({
		(: random_move :),
		"Ѳ��ͦ��˵��: �������ڣ�������˭������������ɱ�ˣ����ɱ���ˣ���Ҫ���Σ���\n",
		"Ѳ����������ץ��ץ�ţ�����һ�ţ�˵������ô����û��ɱ�ˣ����������ˡ���\n",
		(: random_move :)
	} ) ); 

this_object()->carry_object("/clone/weapon/changjian")->wield();
this_object()->carry_object("/d/city/obj/yayifu")->wear();
	remove_call_out("get_dead_player");
	call_out("get_dead_player",10);
}

int get_dead_player()
{
	object *all,me;
        int i;

	me=this_object();
	if ( me->query_temp("catching") && !find_player(me->query_temp("catching")))
	me->delete_temp("catching");

	all=users();
	for ( i = 0;i<sizeof(all);i++) {
                if(objectp(environment(me)))
	                if (present(all[i],environment(me)) && !me->is_fighting()
			&& !me->query_temp("catching") && all[i]->query_condition("killer")>0 ) {
				me->set_temp("catching",all[i]->query("id"));
	        		call_out("do_hit",1,me,all[i]);
				break;
			}
	}
	remove_call_out("get_dead_player");
	call_out("get_dead_player",10);
	return 1;
}

void init()
{
	object me, ob;
	me = this_object();
	ob = this_player();
	::init();
	if (me->is_fighting() || ob->is_fighting())
	return ;
   if (interactive(ob = this_player())){
	if ( ob->query_condition("killer") > 0 ) {
		if (me->query_temp("catching") && me->query_temp("catching")!=ob->query("id")) {
		message_vision(HIW "$N��$n˵������˵��ɱ���ˣ�����æ���˲ŶԸ��㡣\n" NOR, me, ob);
		return ;
	}
	me->set_temp("catching",ob->query("id"));
	command("stare " + ob->query("id"));
	message_vision(HIW "$N��$n˵������˵��ɱ���ˣ��ԣ����һ�ȥ���������ͷ��㣬"
		"�ɲ�Ҫ�ܲ�Ӵ��\n" NOR, me, ob);
	me->set_leader(ob);
	remove_call_out("do_hit");
	call_out("do_hit", 1,  me, ob);   
	}
   if (  !ob->query_temp("armor/cloth") && ob->query("race")=="����" 
                   && ((int)ob->query_temp("summon_time")+400)< time() ) {
                remove_call_out("summon_ob");
                call_out("summon_ob", 1, ob);
                                return;
        }
}
}

void summon_ob(object ob)
{
    object room;
    if (!ob || environment(ob)!=environment())
            return;
         if (! room=find_object("/d/city/lao"))
             room=load_object("/d/city/lao");
        message_vision("\n$Nһ��ץס$n�����컯�գ��������ܣ����˷绯��\n\n",this_object(),ob);
        message_vision("$N����$n��������ȥ��\n",this_object(),ob);
        ob->move(room);
    ob->set_temp("summon_time",time());
    message("vision",YEL+"\n\n���һ����һ���������ļһﱻ���˽�����\n\n"+NOR,room,({ob}));
        if (! room=find_object("/d/city/yamen"))
            room=load_object("/d/city/yamen");
        this_object()->move(room);
}
int do_hit(object me, object dest)
{
	if (me->query_temp("catching")!=dest->query("id")) {
	set_leader(0);
	remove_call_out("checking");
	call_out("checking",1,me,dest);
	}
	if (!objectp(dest) || !environment(dest)) {
	me->set_leader(0);
	remove_call_out("do_back");
	call_out("do_back",0,me);
	return 1;
	}
	me->set_leader(dest);           
	if(living(dest) && objectp(dest) && present(dest,environment(me))
		&& !dest->is_fighting() && !environment(me)->query("no_fight")) 
	{
	me->set("pursuer", 1);
	me->set("vendetta/authority", 1);
	me->set_leader(dest);
	me->fight_ob(dest);
	dest->kill_ob(me);
	dest->set("jubu",1);
	dest->set("nickname", HIR"ɱ��ͨ����"NOR);
	remove_call_out("checking");
	call_out("checking", 1,  me,dest);   
        }
	else  {
		remove_call_out("checking");
		call_out("checking", 1, me,dest);
	}
	return 1;
}

int checking(object me,object dest)
{
	if (!living(me)) return 1;
	if (!dest || !objectp(dest)) {
	me->delete_temp("catching");
	remove_call_out("do_back");
	call_out("do_back",0,me);
	return 1;
	}
	if (me->is_fighting()) 
	{
		remove_call_out("checking");
		call_out("checking",2,me,dest);
		return 1;
	}
	if (living(dest) && me->query_temp("catching")==dest->query("id")) {
	remove_call_out("do_hit");
	call_out("do_hit",1,me,dest);
	}
	if( dest->is_ghost() ) {
	me->delete_temp("catching");
	message("vision", "�ף����ˣ����ˡ��Ź����ɡ�\n", environment(me),me);
	dest->apply_condition("killer",0);
	dest->set("jubu",0);
	dest->set("nickname", HIR"��ɱɱ�˷�"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s���͵������ˡ�", dest->name()));
	remove_call_out("do_back");
	call_out("do_back", 0, me);
	return 1;
	}
	if (!living(dest)) {
	message("vision", "Ѳ��һЦ����"+dest->name()+"������һ����˵��������ץס�㣿\n"
		"Ѳ����Ӱһ���������ˡ�\n", environment(me), me );                   
	dest->remove_all_killer();
	all_inventory(environment(dest))->remove_killer(dest);
	dest->move("/d/city/lao");
	message("vision",HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n" NOR,
		environment(dest), dest);

	tell_object(dest, "����ٺٵ�Ц�ţ���������������������...��\n");
	dest->set("startroom", "/d/city/lao.c");
	dest->set("nickname", HIR"����ɱ�˷�"NOR);
	dest->apply_condition("jial", 60);
        dest->apply_condition("killer",0);
	dest->set("jubu",0);
	me->fight_ob(0);
	dest->fight_ob(0);
	me->delete_temp("catching");
	remove_call_out("do_back");
	call_out("do_back", 0, me);
	return 1;                       
	}               
	if (environment(dest) && !present(dest,environment(me))) {
	message_vision("$N��Ӱһ���������ˡ�\n", me);
	remove_call_out("do_hit");
	call_out("do_hit",1,me,dest);
	return 1;
	}
	remove_call_out("checking");
	call_out("checking",2,me,dest);
	return 1;
}

int do_back(object me, object dest)
{
	me->move("/d/city/xidajie1");
	message("vision", "Ѳ�����˹��������������ϵĳ�����˵������ץ��һ�������ۣ�\n", 
		environment(me), me );

	me->set("title",HIY "���ݲ���" NOR);
	me->set("long",
		"����������ʹ������ר�����ۡ�\n" );

	me->set_leader(0);
	me->delete_temp("catching");
	remove_call_out("get_dead_player");
	call_out("get_dead_player",10);
	return 1;
}

int random_move()
{
	mapping exits;
	string *dirs;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}

int accept_fight(object me)
{
	command("say �㾹���ҹٸ��Ļ�����������");
	if(me->query("combat_exp")<1000 && me->query("age")<16)
	{
		me->apply_condition("jial",50);
		message("vision", "ֻ��Ѳ��˦��һ����������$N���˸����ʵʵ��$N��ʱ�۵û��˹�ȥ��\n",
			environment(me), me );
		me->unconcious();
		me->move("/d/city/lao1.c");
	}
	else {
		me->apply_condition("killer", 100);
		kill_ob(me);
	}
	return 1;
}

void die()
{
	command("say ���Ү���Ҹ��ٸ�Ϊ�У���һ�����������ֵ����ϵģ�");
	::die();
}
