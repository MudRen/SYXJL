inherit NPC;

void create()
{
        set_name("����", ({ "hou zi","hou" }) );
        set("gender", "����");
        set("age", 10);
        set("long",
                "����ֻ��ëɫ�⻬�����ϻ�����ʲô��ร�������Ǻ�����\n");
        set("combat_exp", 2000);
        set("attitude", "peaceful");
        
        set("water", 200);
        set("food", 200);

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        setup();
}
