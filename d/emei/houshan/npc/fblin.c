//
//create bye cuer
inherit NPC;

void create()
{
        set_name("������", ({
                "fang bilin",
                "fang",
                "bilin",
        }));
        set("long",
                "����һλ����Ư���Ĺ��\n"
        );
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("age", 26);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set("score", 100);
        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("fuliu-jian", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "fuliu-jian");
        prepare_skill("sword", "fuliu-jian");
        
        create_family("������", 4, "����");
        setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}
        
void attempt_apprentice(object ob)
{
  command("say �Ҳ���ͽ����Ҫ�ź���ʦ��һ���ӡ�\n");
}    