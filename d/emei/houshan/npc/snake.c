// animal: snake.c

// Jay 3/18/96



inherit NPC;



void create()

{

        set_name("����", ({ "snake", "she" }) );

        set("race", "Ұ��");

        set("age", 4);

        set("long", "һֻ�����������Դ����ߣ�β��ɳɳ���졣\n");

        set("attitude", "peaceful");



        set("str", 26);

        set("cor", 30);



        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );

        set("verbs", ({ "bite" }) );



        set("combat_exp", 1000);

        set("max_qi",300);

        set("qi",300);



        set_temp("apply/attack", 15);

        set_temp("apply/damage", 6);

        set_temp("apply/armor", 2);



        setup();

}



void init()

{

        object ob;

        ::init();

        if (interactive(ob = this_player()) )

        {

                        remove_call_out("kill_ob");

                        call_out("kill_ob", 1, ob); 

        }

}





