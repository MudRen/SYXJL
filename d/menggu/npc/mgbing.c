inherit NPC;

void create()
{
        set_name("�ɹű�", ({ "menggu bing", "bing" }));
        set("age", 22);
        set("gender", "����");
        set("long", "�ɹű���������С�ܵ�ѵ�������̳�治����ԭ�Ĳ\n");
        set("attitude", "peaceful");
        set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("force", 50);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        setup();
this_object()->carry_object("/d/menggu/obj/madao")->wield();
}

int accept_fight(object me)
{
        command("say ��������ɣ������ɹŵ���ʿ��������õġ�\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}

int check_jindao (object who)
{
  object me = this_object();
if (present("jin dao", who));
    message_vision("$N��$n�������ð�������ɹŹ��Ľ���������������\n",me,who);
        kill_ob(who);
}
