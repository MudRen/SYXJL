// shutong.c ��ͯ

inherit NPC;

void create()
{
        set_name("��ͯ", ({ "shutong", "shu tong", "tong" }) );
        set("gender", "����" );
        set("age", 16);
        set("long",
                "�������������ͯ��\n");
        set("mingwang", 1);
        set("combat_exp", 600);
        set("str", 2);
        set("con", 2);
        set("int", 2);
        set("attitude", "peaceful");
        setup();
        carry_object("/u/csy/kunlun/obj/cloth")->wear();
}

