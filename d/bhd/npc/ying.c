// animal: laoying

// Johnny 8/98



inherit NPC;



void create()

{

        set_name("��ӥ", ({ "lao ying", "ying" }) );

        set("race", "Ұ��");

        set("age", 20);

        set("long", "һֻ��ª����ӥ������ȥ��Щ���¡�\n");

        set("str", 26);

        set("cor", 30);



        set("limbs", ({ "ͷ��", "����", "��", "����", "��צ", "���" }) );

        set("verbs", ({ "claw","poke"}) );



        set("combat_exp", 50000);



        set_temp("apply/attack", 250);

        set_temp("apply/damage", 300);

        set_temp("apply/armor", 400);

        set("chat_msg", ({

                "��ӥ����ͷ��������\n",

                "��ӥ���ڵ����㡣\n",

                "��ӥ �ڷ��Ϸ��¡�\n",

              (: random_move :)



        }) );



        setup();

}



void init()

{

        object ob;

        ::init();

        if (interactive(ob = this_player()) &&

                random(ob->query_kar() + ob->query_per()) < 30) {

                        remove_call_out("kill_ob");

                        call_out("kill_ob", 1, ob); 

        }

}



void die()

{

        message_vision("$N��~~��һ��˺�еĽ������ˡ�\n", this_object());

        destruct(this_object());

}

