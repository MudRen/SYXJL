// animal: snake.c

// Johnny 98.8



inherit NPC;



void create()

{

        set_name("����", ({ "mang she", "mang" }));

        set("race", "Ұ��");

        set("age", 200);

        set("long", "һ���Ӵ��ޱ�, ɫ�ʰ�쵵ľ����� ����������ǿ�ҵ��ȳ�ζ��\n");

        set("attitude", "aggressive");

        set("str", 70);

        set("con", 50);

        set("max_qi", 800);

        set("limbs", ({ "ͷ��", "����", "β��" }) );

        set("verbs", ({ "bite" }) );

        set("combat_exp", 200000);

        set_temp("apply/attack", 50);

        set_temp("apply/armor", 50);

        setup();

}



void die()

{

        object ob,ob1,ob2;

        message_vision("$N�鴤�˼��£���������һ�����ˡ�\n", this_object());

        ob = new(__DIR__"shebian");

        ob1 = new(__DIR__"shepi");

        ob2 = new(__DIR__"sherou");

        ob->move(environment(this_object()));

        ob1->move(environment(this_object()));

        ob2->move(environment(this_object()));

        destruct(this_object());

}

