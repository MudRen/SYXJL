// spider.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("֩��", ({ "dushe" }) );

        set("long",     "һֻ��ɫ��֩�룬ȫ������ë��������צ����ʱ��������������\n");



        set("race", "Ұ��");

        set("age", 3);

        set("attitude", "peaceful");



        set("max_ging", 120);

        set("max_qi", 120);



        set("str", 20);

        set("cor", 40);



        set("limbs", ({ "ͷ��", "����" }) );

        set("verbs", ({ "bite" }) );



        set_temp("apply/attack", 20);

        set_temp("apply/damage", 250);

        set_temp("apply/armor", 25);



        set("combat_exp", 1900);

        setup();

}