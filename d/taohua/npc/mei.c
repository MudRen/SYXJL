// mei_chaofeng.c

// written by Dewey



#include <ansi.h>



inherit NPC;



int do_look(string var);

int ask_me();



void create()

{

	set_name("÷����", ({ "mei chaofeng", "mei", "chaofeng" }));

	set("long", "����һ��ä��˫�۵����긾�ˣ���Ŀ������������ʲô\n"+

            "����ޡ�\n");

	set("nickname",HIB "��ʬ" NOR);

	set("gender", "Ů��");

	set("age", 37);

	set("attitude","heroism");

	set("str", 30);

	set("dex", 32);

	set("con", 17);

	set("int", 25);

	set("shen_type", -1);



        create_family("�һ���", 2, "����");



	set_skill("force", 60);

        set_skill("bibo-shengong", 60);

        set_skill("dodge", 150);

        set_skill("anying-fuxiang", 100);

        set_skill("parry", 90);

//      set_skill("sword", 60);

//      set_skill("luoying-shenjian",60);

        set_skill("unarmed",70);

        set_skill("jiuyin-baiguzhao",60);       



        map_skill("force"  , "bibo-shengong");

        map_skill("unarmed"   , "jiuyin-baiguzhao");

        map_skill("dodge"  , "anying-fuxiang");

        map_skill("parry"  , "jiuyin-baiguzhao");



       

    

	set("jiali",50);



	set("combat_exp", 180000);



	set("max_qi", 500);

	set("max_jing", 200);

	set("neili", 400);

	set("max_neili", 400);



	set("inquiry", ([

	    "name" : "վԶ�㣡",

	    "������" : "�����ҵ���������ʲô�����Ѿ�����",

	    "˼��" : "�����걳��ʦ�ţ��ű�ʦ����������˼����",

	    "�����澭" : (: ask_me :),

            "�ڷ�˫ɷ" : "�����Һ��ҵ������ӵ����ţ���Ҳ��˵����",

       ]) );



	set("chat_chance", 10);

	set("chat_msg", ({

	    "÷�������ĵ�̾��һ�����������������֪�������������ڵ��¿������ң���\n",

	    "÷����˵�����������Һ��ҵ��������Ǻεȵ����磡��\n",

	     }) );



	setup();

	carry_object("/d/taohua/obj/cloth")->wear();

	

}





int ask_me()

{

	object me;



	me = this_player();

	   message("vision",

   HIY "÷������Цһ����������ʹ���ȥ�ҡ���\n"

       "÷�������ɱ��" + me->name() +"\n"

   NOR, environment(), this_object() );

		   kill_ob(this_player());

   return 1;

}





