// shutong.c 书童

inherit NPC;

void create()
{
        set_name("书童", ({ "shutong", "shu tong", "tong" }) );
        set("gender", "男性" );
        set("age", 16);
        set("long",
                "这是礼部尚书的书童。\n");
        set("mingwang", 1);
        set("combat_exp", 600);
        set("str", 2);
        set("con", 2);
        set("int", 2);
        set("attitude", "peaceful");
        setup();
        carry_object("/u/csy/kunlun/obj/cloth")->wear();
}

