// Johnny 8/98

inherit NPC;

void create()
{       set_name("÷��¹", ({"meihua lu", "meihua", "lu"}));
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һƥ���ֵ�÷��¹�����ϵİ���ʮ�ֺÿ���\n");
        set("attitude", "peaceful");
set("limbs", ({ "��", "����", "ǰ��", "����" }) );
        set("verbs", ({ "hoof", "knock" }) );
        set("max_qi",1000);
set("combat_exp", 5000);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        set("chat_chance", 10);
        set("chat_msg", ({
                "÷��¹�������������ߵ��ܿ��ˡ�\n",
                (: random_move :)
        }) );
        setup();
}
