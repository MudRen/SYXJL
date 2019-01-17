// wugong.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("蜈蚣", ({ "dushe" }) );

        set("long",     "一条大蜈蚣，全身闪光，头上凸起一个小瘤，写寻常蜈蚣大不相同。\n");



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