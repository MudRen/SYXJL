#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("����", ({"xing yun","yun",}));
        set("long",
                "����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
                "�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
        );


        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 40);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 400);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 40);
        set("combat_exp", 75000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("kurong-changong", 60);
        set_skill("dodge", 70);
        set_skill("duanjia-shenfa", 70);
        set_skill("qingyan-zhang", 55);
        set_skill("unarmed", 55);
        set_skill("parry", 60);
        set_skill("buddhism", 70);
        set_skill("literate", 60);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "duanjia-shenfa");
        map_skill("unarmed", "qingyan-zhang");
        map_skill("parry", "qingyan-zhang");

        prepare_skill("unarmed", "qingyan-zhang");

        create_family("������", 8, "����");
       
        setup();
}
