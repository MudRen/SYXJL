#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("绿竹翁", ({ "lu zhuweng", "lu",}));
        set("long", 
"此人琴棋书画无一不精，尤其善于画
竹，武功如何就不得而知了。\n");
        set("title",RED"日月神教朱雀堂坛主"NOR);         
       set("gender", "男性");
        set("age", 80);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
       set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);


       
        set_skill("tmzhang",100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
     create_family("日月神教",3,"弟子"); 
         set("inquiry", ([
                        "太极拳经": (: ask_me :),
                ]));
        set("book_count", 1);

        setup();
}

string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，太级拳经不在我处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/force-book");
        ob->move(this_player());
        return "好吧，这本「太级拳经」你拿回去好好钻研。";
}

