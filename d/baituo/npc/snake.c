//snake.c

inherit NPC;

void create()
{
        set_name("�ڹھ���", ({ "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ��Ȼ������������,����Ҫһ�ڰ������¡�\n");
        set("attitude", "peaceful");
        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("str", 86);
        set("cor", 80);
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000000);

        //set("chat_chance",65);
        
        set_temp("apply/attack", 85);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 88);
        set_temp("apply/defence",80);

        setup();
}
void init()
 {       object me;        object where = environment(this_object());
        ::init();
        if (interactive(me = this_player()))
        {
        if (!where->query("no_fight")==1)          
               {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
                }
        }
}

