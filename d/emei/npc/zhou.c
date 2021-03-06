// zhou.c 周芷若

#include <command.h>
#include <ansi.h>

int do_teach();
inherit NPC;
void create()
{
        set_name("周芷若", ({ "zhou zhiruo","zhiruo","zhou"}));
        set("long",
                "她是峨嵋派的第四代掌门弟子。\n"
                "一张脸秀丽绝俗。身着一身淡黄衣裳。\n"
                "略显清减的巧笑中带了些许无奈。\n"
                "她很寂寞。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "剃度"    : "找我剃度？不对吧。",
                "出家"    : "要出家找我的师姐们去。",
                "还俗"    : "无聊。还俗也找我！",
                "张无忌"  : "这个狠心短命的家伙，我再也不要见她！",
                "赵敏"    : "不要问这个贱婢子！",
                "指点武功" : (: do_teach :),                
        ]));
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 70);
        set("combat_exp", 400000);
        set("score", 100);
        set("max_jingli", 1000);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        set_skill("throwing",100);
        set_skill("sword",100);
        set_skill("fuliu-jian",100);
        set_skill("pili-dan",100);
        map_skill("throwing","pili-dan");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "tiangang-zhi");
        prepare_skill("finger", "tiangang-zhi");
 
        create_family("峨嵋派", 4, "掌门弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
int do_teach()
{
        object ob;
        ob=this_player();
        if(ob->query("jiuyin") ==1)
        {
                say("周芷若说道：“我不是已经指点过你了吗？”\n");
                return 1;
        }
        
        if(ob->query("gender")!="女性")
        {
                say("周芷若说道：你是什么东西？偷睹我面容，打扰我清修！”\n");
                command("heng");
                return 1;
        }
        if((int)ob->query_skill("jiuyin-baiguzhao", 1) < 100)
        {
        say("周芷若说道：你的九阴白骨爪还不够娴熟，我指点不了你什么。\n");
        return 1;
	}
	say("周芷若说道：我也没什么好教你的，就给你讲解一下九阴白骨爪吧。\n");
	say("你听了周芷若的讲解，学会了「亡魂一击」和「施毒大法」。\n");
        this_player()->set("jiuyin",1);
        return 1;
}
