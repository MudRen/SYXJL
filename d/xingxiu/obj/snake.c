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