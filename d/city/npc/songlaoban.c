inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("���ϰ�", ({ "song lao ban", "laoban", "song" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "���ϰ����ĵĽӴ�ÿһλ����˵Ŀ��ˣ�����Ц�ݿɾ�\n");
        set("combat_exp", 100);
        set("per", 18);
        set("attitude", "friendly");
        set("rank_info/respect", "�ϰ�");

        set("vendor_goods", ({
                "/d/city/obj/camera",
                "/d/city/obj/maomao",
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
        switch( random(2) ) {
                case 0:
                        say( "���ϰ�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������߰ɣ��͸�������ѱ�֤�õĳ��֡�\n");
                        break;
                case 1:
                        say( "���ϰ�����һ����ߣ�˵������λ" + RANK_D->query_respect(ob)
                                + "������������֤������ͯ�����ۡ�\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 1000) 
        {
                tell_object(who, "���ϰ���˵�˵������л���кõ����һ����������һ��������ǧ������ҵ���˾������֪�������ܻߡ�\n");

                return 1;
        }

        return 0;
}


