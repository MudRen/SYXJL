// Npc ����ʦ̫   /d/emei/npc/jingxin.c
#include "/quest/quest.h"
inherit NPC;

void create()
{
        set_name("����ʦ̫", ({
                "jingxin shitai",
                "jingxin",
                "shitai",
        }));

        set("long",
                "����һλ����ʦ̫��\n"
        );

        set("gender", "Ů��");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 70);
        set("combat_exp", 400000);
        set("score", 100);

        set("per", 25);
        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        set_skill("throwing",100);
        set_skill("feihua-shou",100);
        map_skill("throwing","feihua-shou");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "tiangang-zhi");
        prepare_skill("finger", "tiangang-zhi");
        create_family("������", 4, "����");

        setup();

        carry_object(__DIR__"obj/cloth")->wear();
}
