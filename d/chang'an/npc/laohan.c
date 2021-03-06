#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("老汉", ({ "lao han"}));
        set("long", 
                "他就是负责长安鼓楼清洁的老汉。\n"
                "身穿一件干干净净的灰色布袍。\n"
                "他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
        set("gender", "男性");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 9000);
        set("max_jing", 3000);
        set("neili", 22000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 40000);

        set_skill("force", 300);
        set_skill("dodge", 685);
        set_skill("unarmed", 1100);
        set_skill("parry", 2180);

        set("inquiry", ([
                "扫帚" : (: ask_me :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "老汉愁眉苦脸地喃喃自语：今天是撞了邪了，竟然吃饭的东西都找不着。\n");
}

string ask_me()
{
        this_player()->set_temp("up",1);
        return "是啊，今天不能把这里打扫干净又要挨骂了，你帮我到二层找一找吧。";
}

