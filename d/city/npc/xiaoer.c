// waiter.c

inherit NPC;
inherit F_VENDOR;
#define TIME_CHECK NATURE_D->outdoor_room_description()

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");

        set("vendor_goods", ({
                "/d/city/obj/denglong",
                "/d/city/obj/huoba",
                            }) );

        setup();
       carry_object("/d/city/obj/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
/*
        if ((strsrch(TIME_CHECK, "ҹ��") != -1 || strsrch(TIME_CHECK, "��ҹ") != -1))
                {
                        say( "��С������Ǹ���˵������λ" + RANK_D->query_respect(ob)
                                + "��С���Ѿ�������,���������������ɡ�\n");
                        ob->move("/d/city/beidajie1");
                }
*/
                        
        switch( random(2) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 2000) 
        {
                tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");

                who->set_temp("rent_paid",1);

                return 1;
        }

        return 0;
}

