// hama.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("���", ({ "dushe" }) );

        set("long",     "����һֻСС�ĸ�󡣬���������磬ȫ�����ʤѪ���۾�ȴ����������⡣\n");



        set("race", "Ұ��");

        set("age", 4);

        set("attitude", "peaceful");



        set("max_ging", 100);

        set("max_qi", 100);



        set("str", 10);

        set("cor", 30);



        set("limbs", ({ "ͷ��", "����" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 20);

        set_temp("apply/damage", 30);

        set_temp("apply/armor", 20);



        set("combat_exp", 2100);

        setup();

}