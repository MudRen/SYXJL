#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��Ԫ", ({"gui yuan",  "yuan",}));
        set("long",
                "����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
                "̫��Ѩ�߸߹����ƺ��������书��\n"
        );

//      set("nickname", "");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 50);
        set("shen_type", 1);
        set("str", 28);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 700000);
        set("score", 10000);

        set_skill("force", 240);
        set_skill("kurong-changong", 240);
        set_skill("dodge", 240);
        set_skill("tiannan-bufa", 240);
        set_skill("unarmed", 240);
        set_skill("jinyu-quan", 240);
        set_skill("parry", 250);
        set_skill("buddhism", 240);
        set_skill("literate", 90);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("unarmed", "jinyu-quan");
        map_skill("parry", "jinyu-quan");

        prepare_skill("unarmed", "jinyu-quan");

        create_family("������", 7, "����");

        setup();

}

