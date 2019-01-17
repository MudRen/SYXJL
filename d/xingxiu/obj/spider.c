// spider.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("蜘蛛", ({ "dushe" }) );

        set("long",     "一只黑色的蜘蛛，全身长满黑毛，张牙舞爪，随时都会向你扑来。\n");



        set("race", "野兽");

        set("age", 3);

        set("attitude", "peaceful");



        set("max_ging", 120);

        set("max_qi", 120);



        set("str", 20);

        set("cor", 40);



        set("limbs", ({ "头部", "身体" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 20);

        set_temp("apply/damage", 250);

        set_temp("apply/armor", 25);



        set("combat_exp", 1900);

        setup();

}