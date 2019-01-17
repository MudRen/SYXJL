// dragon.c created by aeolus ���� 5/8/99
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int ask_sword();
int ask_ball();
int ask_go();
int do_powerup();

void create()
{
        set_name(HIW"С����"NOR ,( { "dragon"} ) );

        set("nickname", HIG "���׵ĳ���" NOR );
        set("title", HIW "���Ƶ��ػ���" NOR );
        set("long", 
                "����һֻ�ػ���������������ƽʱ��ô����Ŷ����Ҫ�Ǽ�ŭ�����ɲ���������ġ�\n");              
        set("age", 10);
        set("attitude", "heroism");
	set("qi", 1000);
	set("jing", 1000);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("shen_type", 1);
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("kar", 25);
        set("per", 30);
	set_skill("dodge", 250);
	set_skill("force", 250);
	set_skill("parry", 250);
	set_skill("hand", 250);
	set_skill("claw", 250);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("yunlong-shou", 250);
	set_skill("yunlong-zhua", 250);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-zhua");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

        set("limbs", ({ "����", "��ͷ", "����", "��צ", "����", "��β" }) );

        set("inquiry", ([
	    "����"	: (: ask_go :),
	    "follow me"	: (: ask_go :),
	    "powerup"	: (: do_powerup :),
	    "����"	: (: ask_ball :), 
	    "ball"	: (: ask_ball :), 
	    "aeolus"	: "�ҵ����ˣ������ҿɺ��ˡ�������Ϊ�˸�������������֪͸֧�˶��ٷ�����\n",
	    "����"	: "�������𾴵��ˡ�\n",
	    "renee"	: "������ү���ǵ��ˡ�\n",
	    "batian"	: (: ask_sword :),
	    "����������": (: ask_sword :),
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
        
        set("combat_exp", 1000000);

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "powerup" :),
        }) );
        setup();
	add_money("gold", 10);
}

void init()
{
object ob;
ob=this_player();
::init();
remove_call_out("greeting");
call_out("greeting", 1, ob);

	add_action("do_attack","attack");
	add_action("do_stop","stop");
	add_action("do_send","gift");
	add_action("do_kill","murder");
}

int do_powerup()
{
  object me;
  string host_id;
  me=this_player();

	if(query("id")!="dragon")
	{	
		sscanf(query("id"),"%s's dragon",host_id);
		if(me->query("id")==host_id)
		{
		message_vision("$N"HIY"ͻȻ���շ���һ�������������Ա�������.\n"NOR,this_object());
		add("combat_exp",100000);
		return 1;
		}
	}
	message_vision("$N"CYN"���ӵ�˵��:��,��ƾʲô�����ң�\n"NOR, this_object());
	return 1;
}

int ask_ball()
{
	object me;
	object ball;
	me=this_player();

	set("ball_count",7);

	if(me->query("id")!=("aeolus")&&me->query("weiwang")<10000){
		message_vision("$N"CYN"˵:���������мż�������ƾʲô�ʽ��ر����飿\n"NOR, this_object());
		return 0;
	}
	if(query("ball_count")<1){
		message_vision("$N"CYN"˵:˵:�Բ���!�ر������Ѿ�ȫ��������.\n"NOR, this_object());
		return 0;
	}
	if(!present("dragon ball", me)
	&& query("ball_count") >= 1)
	{
		add("ball_count", -1);
		ball = new("/u/aeolus/dragonball");
		ball->move(me);
		message_vision(HIY"С�����ſ��ڣ�ͻȻ������䡣�ڶ�Ŀ�Ľ�������º�Ȼ��һ�Ŵ����е��ر��������顱��\n"NOR,this_player());
	return 1;
	}
}

int ask_sword()
{
	object me;
	object sword;
	me=this_player();

	if(me->query("id")!=("aeolus")&&me->query("weiwang")<10000){
		message_vision(HIY"$N˵����������ү��$n����Ҫ������������\n"NOR, this_object(),this_object());
	return 0;
	}
	else
	{
		sword = new("/u/aeolus/batian.c");
		sword->move(me);
		message_vision(HIY"$N˵����������ү�Ӱ�������������\n"NOR,this_object());
	return 1;
	}
}
int ask_go()
{
	object me;
	string new_name,new_id,host_id;
	me=this_player();

	if(query("id")!="dragon"){
		 sscanf(query("id"),"%s's dragon",host_id);
		 if(query("id")==host_id)
           {say(query("name")+"��������ɫ�Ĵ��۾�����"+me->query("name")+"��˵:��Ȼ��,�Ҷ����˾������ġ�\n");
            		return 1;
           }
	 if(me->query("id")!=host_id)
           {say(query("name")+"գ��գ����ɫ�Ĵ��۾�����"+me->query("name")+"��˵:����,�ҵ��������˵ġ�\n");
			return 1;
           }
	 }
	 if(me->query("id")=="aeolus")
	   {
	   write( HIY "С������:������ү��������С����������С�������𾴵��ˡ�\n" NOR);
	   write( HIY "����������үҪ��һͬ����������������С����������������鰡��\n" NOR);
	   command("nod");	
	   set_leader(me);
       new_name = me->query("name")+"�ĳ���С����";
       new_id=me->query("id")+"'s dragon";
       set("name",new_name);
       set("id",new_id);
	   write( "����ָ��:\nattack sb ����ĳ��.\nmurder sb ɱ��ĳ��.\nstop ֹͣս��.\ngift sb.--��С�����͸�sb.\n");
	   set("long","����"+new_name+"��\n"+
		"һֻ�����С������ƽʱ�����������Ƶ����������֮������ά���˼������;\n"+
		"����ɫ��˫��������������ֱ���������\n");
          }
         else if(present("batian",this_player())) 
	   {
	   write( HIY "С������:������ү������ͬ���㣬���Ի��Ƶ����д����\n" NOR);
	   write( HIY "������үҪ�Ҹ������˴�����������һ�����ľ�����\n" NOR);
	   command("nod");	
	   set_leader(me);
       new_name = me->query("name")+"�ĳ���С����";
       new_id=me->query("id")+"'s dragon";
       set("name",new_name);
       set("id",new_id);
	   write( "����ָ��:\nattack sb ����ĳ��.\nmurder sb ɱ��ĳ��.\nstop ֹͣս��.\ngift sb.--��С�����͸�sb.\n");
	   set("long","����"+new_name+"��\n"+
		"һֻ�����С������ƽʱ�����������Ƶ����������Ϊ"+me->query("name")+"���¡�;\n"+
		"����ɫ��˫��������������ֱ���������\n");
       }
	   else say(query("name")+"���������Ĵ��۾�����"+me->query("name")+"��˵:���е�,������үû��ͬ�⡣\n");
return 1;
}

int do_attack(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
  if(query("id")=="dragon")
   {say("����Ȩʹ�ô����\n");
    return 0;}
  sscanf(query("id"),"%s's dragon",host_id);
  if(me->query("id")!=host_id)
  return notify_fail("С�������������㣡\n");
  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("С����ɵ�����������㣬�����������˼��\n");
  if(!living(ob)) 
	 return notify_fail("С����˵:"
              +ob->query("name")+"��������: ����������\n");
  message_vision( HIY "С����������$N��ͷ��:���������ȥ��$nһ��С�ʹ�䡣\n" NOR,me,ob);
  fight_ob(ob);
  return 1;
}

int do_kill(string arg)
{
	string host_id;
	object ob;
	object me=this_player();
  if(query("id")=="dragon")
   {say("����Ȩʹ�ô����\n");
    return 0;}
  	sscanf(query("id"),"%s's dragon",host_id);
  	if(me->query("id")!=host_id)
  	 return notify_fail("С�������������㣡\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��ҪС����ɱ˭��\n");
  if(!living(ob)) 
	 return notify_fail("С����˵:"
              +ob->query("name")+"��������: ����������\n");
	if(!environment(ob)->query("no_fight"))
	{
        message_vision( HIY "С������$nǸȻһЦ��˵��:�������Ҹ�����ʲô���ڣ�ֻ����������$N֮��Ҫȡ�㾱����ͷ��\n" NOR,me,ob);
	remove_call_out("kill_ob");
  	call_out("kill_ob", 1, ob); 
	}
	return 1;
}  

int do_stop()
{
   string host_id;
  object me=this_player();
  if(query("id")=="dragon")
   return notify_fail("����Ȩʹ�ô����\n");
  sscanf(query("id"),"%s's dragon",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("С�������������㣡\n");
 if(!is_fighting())
	 return notify_fail("С��������û���˴�.\n");
 command("halt");
 message_vision( HIY "С����һ�С����ɾ��족��Ӱ���ε�Ծ������$N����ߡ�\n" NOR,me);
 return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
  if(query("id")=="dragon")
   return notify_fail("����Ȩʹ�ô����\n");
  sscanf(query("id"),"%s's dragon",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("С�������������㣡\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��Ҫ��С�����͸�˭��\n");
  if(!living(ob)) 
	 return notify_fail("��ֻ�ܰ�С����������!\n");
 message_vision( HIY "С�����ѹ�����������$N��˵:\n�����˵Ĵ����������ٱ�...С�����ʹ˱������\n" NOR,me);
 set_leader(ob);
 new_name = ob->query("name")+"������С����";
	   set("long","����"+new_name+"��\n"+
		"һֻ�����С������ƽʱ�����������Ƶ�����������ɵ����������ˡ�;\n"+
		"����ɫ��˫��������������ֱ���������������ȴ��¶��һ˿���κͱ�����\n");
 new_id=ob->query("id")+"'s dragon";
 set("name",new_name);
 set("id",new_id);
 write( HIY "С������������"+ob->query("name")+"������һ�ݡ�\n" NOR);
 message_vision("����ָ��:\nattack sb ����ĳ��.\nsha sb ɱ��ĳ��.\nstop ֹͣս��.\ngift sb.--��С�����͸�sb.\n",me);
 return 1;
}     

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("id")==("aeolus")){
	write(CYN"С�������˵ĵ�˵��������ү�����ˣ�\n"NOR);
	return;
	} else {         
	write(CYN"С������ò��˵��"+ob->query("name")+""+RANK_D->query_respect(ob)+",���.\n"NOR);
	}
}