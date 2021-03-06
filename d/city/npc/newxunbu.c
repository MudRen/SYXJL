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
	set_name("巡捕", ({ "xunbu" }) );
	set("title", HIY "扬州差役" NOR);
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 30);
	set("str", 30);
	set("con", 30);
        set("int", 20);
	set("dex", 30);
	set("no_clean_up",0);

	set("long",
		"这是扬州御使任命的专案捕役。\n" );

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
		"巡捕挺胸说道: “有我在，无论是谁，都不能随意杀人，如果杀了人，就要坐牢！”\n",
		"巡捕脱下袜子抓了抓脚，闻了一闻，说：“怎么今天没人杀人？闷死老子了。”\n",
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
		message_vision(HIW "$N对$n说道：听说你杀了人？等我忙完了才对付你。\n" NOR, me, ob);
		return ;
	}
	me->set_temp("catching",ob->query("id"));
	command("stare " + ob->query("id"));
	message_vision(HIW "$N对$n说道：听说你杀了人？乖，跟我回去，查个清楚就放你，"
		"可不要拒捕哟！\n" NOR, me, ob);
	me->set_leader(ob);
  	me->do_change(ob);	
	remove_call_out("do_hit");
	call_out("do_hit", 1,  me, ob);   
	}
   if (  !ob->query_temp("armor/cloth") && ob->query("race")=="人类" 
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
        message_vision("\n$N一把抓住$n，光天化日，当街裸跑，有伤风化！\n\n",this_object(),ob);
        message_vision("$N拎着$n向衙门走去！\n",this_object(),ob);
        ob->move(room);
    ob->set_temp("summon_time",time());
    message("vision",YEL+"\n\n当啷一声，一个赤条条的家伙被扔了进来。\n\n"+NOR,room,({ob}));
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
	dest->set("nickname", HIR"杀人通缉犯"NOR);
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
	message("vision", "咦，死了？算了。放过他吧。\n", environment(me),me);
	dest->apply_condition("killer",0);
	dest->set("jubu",0);
	dest->set("nickname", HIR"被杀杀人犯"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s被就地正法了。", dest->name()));
	remove_call_out("do_back");
	call_out("do_back", 0, me);
	return 1;
	}
	if (!living(dest)) {
	message("vision", "巡捕一笑，把"+dest->name()+"往背上一背，说到：还不抓住你？\n"
		"巡捕身影一闪，不见了。\n", environment(me), me );                   
	dest->remove_all_killer();
	all_inventory(environment(dest))->remove_killer(dest);
	dest->move("/d/city/lao");
	message("vision",HIY "只听牢房铁门匡地一响，一个昏昏沉沉的家伙被扔了进来！\n\n" NOR,
		environment(dest), dest);

	tell_object(dest, "狱卒嘿嘿地笑着：今儿个你可落在我手里了...！\n");
	dest->set("startroom", "/d/city/lao.c");
	dest->set("nickname", HIR"被捕杀人犯"NOR);
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
	message_vision("$N身影一闪，不见了。\n", me);
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
	message("vision", "巡捕走了过来，拍了拍身上的尘土，说道：又抓了一个，真累！\n", 
		environment(me), me );

	me->set("title",HIY "扬州差役" NOR);
	me->set("long",
		"这是扬州御使任命的专案捕役。\n" );

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
	command("say 你竟敢找官府的秽气？找死！");
	if(me->query("combat_exp")<1000 && me->query("age")<16)
	{
		me->apply_condition("jial",50);
		message("vision", "只见巡捕甩出一副锁链，把$N捆了个结结实实，$N顿时疼得昏了过去！\n",
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
	command("say 你好耶，敢跟官府为敌，你一定会死在我兄第手上的．");
	::die();
}


void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      
      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
		if(sname[i]=="literate")i++;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }

        me->set_skill("pixie-jian", temp);
        me->set_skill("unarmed",temp);
        me->set_skill("xianglong-zhang",temp);
        me->set_skill("dodge", temp);
        me->set_skill("sword", temp);
        me->set_skill("parry", temp);

        me->map_skill("sword","pixie-jian");
        me->map_skill("dodge","pixie-jian");
        me->map_skill("parry","pixie-jian");
        me->map_skill("unarmed","xianglong-zhang");

        prepare_skill("unarmed", "xianglong-zhang");



/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]+random(200000));

}
