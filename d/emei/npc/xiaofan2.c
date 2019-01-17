// xiaofan2.c � 

inherit NPC;

inherit F_DEALER;
                      
 
void greeting(object);
void create()
{
        set_name("С��", ({ "xiao fan", "fan" }));
        set("title","ר�շ���");  
        create_family("������",7,"��������");
        set("shen_type", 0);

        set("gender", "Ů��");
        set_max_encumbrance(10000000000);
        set("age", 35);
        set("long",
                "һ�������������ϸ��ˡ�\n");
        set("no_get_from", 1);
        set("no_steal_from", 1);
        set("no_beg",1);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        
        setup();
}

void init()                         
{                                   
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);

        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "С������˵������λ" + RANK_D->query_respect(ob)
            + "�������ר�չ���Ҳ��õķ��\n");
         
}
void die()
{
        message_vision("\n$N���ˡ�\n", this_object());
        destruct(this_object());
}

