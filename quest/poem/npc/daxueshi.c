// poemgirl.c

inherit NPC;

#include <ansi.h>

int send_back(object me);

void create()
{
        set_name(HIW"ÀÏÕß"NOR, ({ "oldman", "lao",}) );
        set("gender", "ÄÐÐÔ" );
        set("age", 52);
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set_skill("literate", 300);
        set_skill("dodge", 140);
        setup();
     this_player()->carry_object("/clone/misc/cloth")->wear();

}

