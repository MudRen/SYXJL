// langren.c ����

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��Ĺ��", ({ "shoumu ren","ren",  }) );
        set("gender", "����");
        set("age", 35);
        set("long",
                "���Ǹ��һ�������Ĺ�ˡ�\n");
        set("combat_exp", 20000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("str", 30);
        set("con", 25);
        set("int", 20);
        set("dex", 30);

        set("max_qi", 500);
        set("eff_qi", 500);
        set("qi", 500);
        set("max_jing", 200);
        set("jing", 200);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("shen_type", 0);

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);

        set_skill("sword", 100);
        set_skill("unarmed", 80);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        setup();
}
