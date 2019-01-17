// xiaoer2.c �Ƶ�С��

inherit NPC;
inherit F_DEALER;
inherit SELL_SALT;                          // ��˽��
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
        set("need_salt",2000);                  // ��Ҫ2000��˽��       
        set("vendor_goods", ({
                __DIR__"obj/jitui",
                "/d/city/obj/guiyu",
                __DIR__"obj/jiudai",
                __DIR__"obj/baozi",
                __DIR__"obj/hongcha",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "ؤ��" 
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("sell_salt", "sell");                            // ��˽��
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
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

// 69  void saying(object ob)
// 70  {
// 71          if (!ob || environment(ob) != environment()) return
//
// 73          say("\n��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n")
// 74          remove_call_out("kicking")
// 75          call_out("kicking", 1, ob)
//
// 77  }

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/city/beidajie2");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴�����¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
void reset()
{
    set("need_salt",2000);                  // ��Ҫ2000��˽��
}

