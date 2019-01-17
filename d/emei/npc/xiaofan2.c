// xiaofan2.c å 

inherit NPC;

inherit F_DEALER;
                      
 
void greeting(object);
void create()
{
        set_name("Ğ¡··", ({ "xiao fan", "fan" }));
        set("title","×¨ÊÕ·ÏÎï");  
        create_family("¶ëáÒÅÉ",7,"¼ÇÃûµÜ×Ó");
        set("shen_type", 0);

        set("gender", "Å®ĞÔ");
        set_max_encumbrance(10000000000);
        set("age", 35);
        set("long",
                "Ò»¸öÍâ³öÌÖÉú»îµÄÀÏ¸¾ÈË¡£\n");
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
        say( "Ğ¡··¿ì»îµØËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
            + "£¬ÎÒÕâ¶ù×¨ÊÕ¹º´ó¼Ò²»ÓÃµÄ·ÑÎï¡£\n");
         
}
void die()
{
        message_vision("\n$NËÀÁË¡£\n", this_object());
        destruct(this_object());
}

