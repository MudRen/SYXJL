// xiezi.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("Ы��", ({ "dushe" }) );

        set("long",     "һֻ�������ƺڰߵ�Ĵ�Ы�ӣ�Ыβ����������⣬��Ȼ�Ǽ���֮�\n");



        set("race", "Ұ��");

        set("age", 3);

        set("attitude", "peaceful");



        set("max_ging", 110);

        set("max_qi", 110);



        set("str", 10);

        set("cor", 55);



        set("limbs", ({ "Ы��", "Ыͷ", "Ы��", "Ыβ" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 30);

        set_temp("apply/damage", 25);

        set_temp("apply/armor", 20);



        set("combat_exp", 2300);

        setup();

}