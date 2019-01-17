// animal: laoying

// Johnny 8/98



inherit NPC;



void create()

{

        set_name("老鹰", ({ "lao ying", "ying" }) );

        set("race", "野兽");

        set("age", 20);

        set("long", "一只丑陋的老鹰，看上去有些可怕。\n");

        set("str", 26);

        set("cor", 30);



        set("limbs", ({ "头部", "颈部", "后背", "腹部", "脚爪", "翅膀" }) );

        set("verbs", ({ "claw","poke"}) );



        set("combat_exp", 50000);



        set_temp("apply/attack", 250);

        set_temp("apply/damage", 300);

        set_temp("apply/armor", 400);

        set("chat_msg", ({

                "老鹰在你头顶盘旋。\n",

                "老鹰正在瞪着你。\n",

                "老鹰 在飞上飞下。\n",

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

        message_vision("$N啊~~的一声撕列的叫声死了。\n", this_object());

        destruct(this_object());

}

