// snake.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("������", ({ "dushe" }) );

        set("long",     "һ�������ĳ����ߣ�����쵣����ǿɲ���\n");



        set("race", "Ұ��");

        set("age", 3);

        set("attitude", "peaceful");



        set("max_ging", 130);

        set("max_qi", 130);



        set("str", 10);

        set("cor", 50);



        set("limbs", ({ "ͷ��", "����", "β��" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 20);

        set_temp("apply/damage", 20);

        set_temp("apply/armor", 20);



        set("combat_exp", 2000);

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


