// xiezi.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("蝎子", ({ "dushe" }) );

        set("long",     "一只浑身长满黄黑斑点的大蝎子，蝎尾隐隐泛出清光，显然是极毒之物。\n");



        set("race", "野兽");

        set("age", 3);

        set("attitude", "peaceful");



        set("max_ging", 110);

        set("max_qi", 110);



        set("str", 10);

        set("cor", 55);



        set("limbs", ({ "蝎螯", "蝎头", "蝎身", "蝎尾" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 30);

        set_temp("apply/damage", 25);

        set_temp("apply/armor", 20);



        set("combat_exp", 2300);

        setup();

}