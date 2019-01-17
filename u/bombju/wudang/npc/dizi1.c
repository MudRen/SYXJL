inherit NPC;

void create()
{
        set_name("����", ({ "gui san", "san", "gui" }));
        set("long", 
                "�����䵱ɽ�ĵ��ӡ�\n");
        set("gender", "����");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        
        set("max_qi", 350);
        set("max_jing", 300);
        set("neili", 450);
        set("max_neili", 450);

        set("combat_exp", 20000);
        set("score", 10000);

        set_skill("force", 80);
        set_skill("dodge", 70);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("�䵱��", 2, "����");

        setup();
        
        carry_object("/d/wudang/obj/greyrobe")->wear();
}
