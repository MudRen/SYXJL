// hama.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("蛤蟆", ({ "dushe" }) );

        set("long",     "这是一只小小的蛤蟆，长不逾两寸，全身殷红胜血，眼睛却闪闪发出金光。\n");



        set("race", "野兽");

        set("age", 4);

        set("attitude", "peaceful");



        set("max_ging", 100);

        set("max_qi", 100);



        set("str", 10);

        set("cor", 30);



        set("limbs", ({ "头部", "身体" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 20);

        set_temp("apply/damage", 30);

        set_temp("apply/armor", 20);



        set("combat_exp", 2100);

        setup();

}