inherit NPC;

#include "/d/emei/npc/wen.h"

void create()

{

        set_name("����ʦ̫", ({

                "wenyi shitai",

                "wenyi",

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

        set("max_jing", 500);

        set("neili", 1000);

        set("max_neili", 1000);

        set("jiali", 40);

        set("combat_exp", 60000);

        set("score", 100);


        set_skill("force", 60);

        set_skill("linji-zhuang", 60);

        set_skill("dodge", 70);

        set_skill("zhutian", 70);

        set_skill("yanxing-dao", 70);

        set_skill("blade", 70);

        set_skill("parry", 60);

        set_skill("mahayana", 70);

        set_skill("literate", 60);

        map_skill("force", "linji-zhuang");

        map_skill("dodge", "zhutian");

        map_skill("blade", "yanxing-dao");

        map_skill("parry", "yanxing-dao");

        prepare_skill("blade", "yanxing-dao");

        

        create_family("������", 5, "����");

        setup();

        carry_object(__DIR__"obj/cloth")->wear();

        carry_object(__DIR__"obj/gangdao")->wield();

}

