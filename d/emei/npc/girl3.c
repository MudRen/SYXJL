// girl3.c

inherit NPC;

void create()
{
	set_name("С���",({ "xiao nigu","nigu" }) );
        set("gender", "Ů��" );
        set("age", 15);
        set("long", "���Ǹ��ѳ��ҵ�С��á�\n");
        set("str", 16);
        set("dex", 17);
        set("con", 20);
        set("int", 17);    
        set("class","bonze");
	set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

