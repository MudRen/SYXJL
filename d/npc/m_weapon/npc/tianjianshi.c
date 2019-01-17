// npc: /d/xingxiu/npc/afanti.c

// Jay 3/26/96

// modify by five

#include <ansi.h>

inherit NPC;



int do_weapon();

object creat_weapon();



void create()

{

        set_name("ŷұ��", ({ "ouye zi", "zi" }) );

        set("nickname", RED "���Ľ���" NOR );

          set("title", "�����ɿ�ɽ��ʦ" );
        set("gender", "����" );

        set("age", 60);

        set("long",     

            "��ͷ�ϰ���ͷ�������Ƴ���Ʈ����ǰ����Ŀ���ݵ������й⣬\n"

            "��Ŀ��������˸˸���ž��������ݵĽ��⣬�����ƺ�����Χ\n"

            "��һ�ɽ���֮�С�\n");

        set("str", 25);

        set("dex", 20);

        set("con", 17);

        set("int", 30);

        set("shen_type", 0);

        set("max_neli",5000);

        set("jiali",50);



        set_skill("unarmed", 100);

        set_skill("dodge", 100);

        set_skill("claw",200);

        set_skill("jiuyin-baiguzhao",200);

        set_skill("force",150);

        set_skill("sword",150);

        set_skill("bibo-shengong",100);

        set_skill("luoying-shenjian",100);

        set_skill("parry",90);

        set_skill("anying-fuxiang",100);

        set_temp("apply/attack", 50);

        set_temp("apply/defense", 50);

        set_temp("apply/damage",50);



//          create_family("������",1,"����");


        set("combat_exp", 250000);

        set("score",0);

        

        map_skill("force","bibo-shengong");

        map_skill("parry","luoying-shenjian");

        map_skill("sword","luoying-shenjian");

        map_skill("claw","jiuyin-baiguzhao");

        map_skill("dodge","anying-fuxiang");



        

        set("attitude", "peaceful");

        

        set("inquiry", ([

            "����"  : "�������Ǽ�ʮ�ּ����£�Ҫ�����˵ľ��������������о��ĺ�������\n",

            "ԭ��"  : "��������ǧ���������������ҵ����Ҳ��ܰ���������\n",

       ]) );

            set("no_get",1);

        setup();

        set("chat_chance", 3);

        set("chat_msg", ({

             "ŷұ�Ӹ������裺��������⣬�����͡����������⣬��Ӣ�ۣ�\n",

             "ŷұ�ӵ�ͷ�������ƺ���˼��ʲô��\n"

             "ŷұ��̾��һ�����������Ӣ�ۣ���Ӣ�ۡ�����������\n"

       }) );

        carry_object("/clone/misc/cloth")->wear();

        carry_object("/clone/weapon/changjian")->wield();

}



void init()

{

        ::init();

        add_action("do_answer","answer");

}





int accept_object(object who, object ob)

{       



        if((who->query("weapon/make")) ){

                say("ŷұ��һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n");

       call_out("destrory",0,ob);

                return 2;

        }

        switch ((string)ob->query("name") ) 

        {

                case "ǧ����ľ": 

                        who->set_temp("or",1);

                        who->set_temp("get_orc",1);

                        break;

                case "���׽�ĸ":

                        who->set_temp("or",2);

                        who->set_temp("get_orc",1);

                        break;

                case "��˿����": 

                        who->set_temp("or",3);

                        who->set_temp("get_orc",1);

                        break;

                default :

                        message("vision","����ʲô���ⲻ���������������",who);

                        return 2;

        }

        message("vision","ŷұ�ӵ�ͷ������һ�����е�"+(string)ob->query("name")+

                        "���˵�ͷ˵��\n",who);



        write("��������Դ������±�����\n"+

              "     ��(jian)\n"+

              "     ��(dao)\n"+

              "     ��(gun)\n"+

              "     ��(staff)\n"+

              "     �(hammer)\n"+

              "     ��(whip)\n");               

        say("��λ"+RANK_D->query_respect(who)+"Ҫ��ʲô�����������˸�����(answer)��\n");

       call_out("destrory",0,ob);

        return 2;



}



int do_answer(string arg)

{

        object me,w_or;

        me = this_player();

        if(!(me->query_temp("get_orc") ) ){

                write("���ҵ�ԭ������\n");

                return 0;

        }

        

        if(!arg){

           write("��Ҫ��ʲô������\n");

          return 0;

        }

        message("vision",me->name()+"��ŷұ������˵�˼��䡣\n",environment(me), ({me}) );

        switch (arg) {

          case "jian" :

                me->add_temp("sword",1);

                write("����ԭ��ȥ���̽���!\n");

                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);

                break;

          case "dao" :

                me->add_temp("blade",1);

                write("����ԭ��ȥ���̵���!\n");

                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);

                break;

          case "gun" :

                me->add_temp("club",1);

                write("����ԭ��ȥ���̹���!\n");

                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);

                break;

          case "staff" :

                me->add_temp("staff",1);

                write("����ԭ��ȥ�����Ȱ�!\n");

                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);

                break;

          case "whip" :

                me->add_temp("whip",1);

                write("����ԭ��ȥ���̱ް�!\n");

                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);

                break;

          case "hammer" :

                me->add_temp("hammer",1);

                write("����ԭ��ȥ����颰�!\n");

                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);

                break;



          default :

                message_vision(HIC "ŷұ��һ�����ɣ�ʲô������\n" NOR,me);

                return notify_fail("ŷұ����ϸ��˵�����²��ɶ�Ϸ��������!!\n");

        }

        switch ( me->query_temp("or") ) {

          case 1:

                w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);

                w_or->move(me);

                message_vision(HIC "ŷұ�Ӹ���$Nһ��ǧ����ľ\n" NOR, me);

                break;

          case 2:

                w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);

                w_or->move(me);

                message_vision(HIC "ŷұ�Ӹ���$Nһ�麣�׽�ĸ\n" NOR, me);

                break;

          case 3:

                w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);

                w_or->move(me);

                message_vision(HIC "ŷұ�Ӹ���$Nһ�麮˿����\n" NOR, me);

                break;

        }

        me->delete_temp("or");

        return 1;

}

void destrory(object ob)

{

      destruct(ob);

     return;

}
