#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"����ͷ"NOR, ({ "tufei tou","tou" }) );
        set("gender", "����");
        set("age", 45);
        set("long",
                "����ǧ��ʯ����������һ�����ɱ����һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 120000);
        set("shen_type", -1);
        set("attitude", "aggressive");

        set("apply/attack",  30);
        set("apply/defense", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
                "����ͷ�ٺٵ���Ц��:�㾹�Ҵ�����������������ͱ����������ų�ȥ��!\n",
        }) );
       set_skill("dugu-jiujian", 80);
        set_skill("sword", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 150);
        set_skill("dodge", 80);
        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "dugu-jiujian");
        setup();
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10000);
}
