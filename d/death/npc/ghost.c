inherit NPC;

void create()
{
        set_name("����ʹ��", ({ "gouhun shizhe", "gouhun"  }) );
        set("gender", "����" );
        set("age", 28);
        set("long", "ִ�Ƶظ��ΰ���ר�ù»�Ұ��\n");
        set("combat_exp", 100000);
        set("attitude", "peaceful");
        set_skill("force", 70);
        set_skill("blade", 80);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 300);
        set("max_neili", 300);
        set("jingli", 300);
        set("max_jingli", 300);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/npc/obj/gangdao")->wield();
}

void greeting(object ob)
{
        if( !wizardp(ob) )
        command("say ����������������˭�����㵽�������");
        kill_ob(ob);
}
