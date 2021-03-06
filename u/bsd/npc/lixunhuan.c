// lixunhuan.c 李寻欢

#include <ansi.h>

inherit NPC;
void greeting(object ob);
void do_init();
void do_init1();
int ask_me();

void create()
{
        set("title",HIR"风云第一刀"NOR);
	set("nickname",HIM"浪子"NOR);
        set_name("李寻欢", ({"li xunhuan", "li", "master"}));
        set("gender", "男性");
        set("age", 34);
        set("long", 
                "他就是一代浪子李寻欢,名列百晓声兵器谱第二.\n"
                "小李飞刀,列无虚发.不知成为多少武林豪杰的偶像.\n"
                "而他的爱情故事更不知道倾倒了多少痴情男女.\n");
        set("attitude", "peaceful");
        
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("chat_chance",9);
        set("chat_msg", ({
                HIR"李寻欢开始不停的咳,一丝丝鲜血顺着他的嘴角流了下来.\n"NOR,
  		HIB"李寻欢叹了囗气，自角落中摸出了个酒瓶，他大囗的喝起酒来.\n"NOR,
                HIW"李寻欢呆呆的看着手里的雕像,眼神却已痴了.\n"NOR,
                (: call_out("do_init1", 1) :),

        }));

        set("inquiry", ([
                "林诗音"  : HIR"过去的事情还提做什么?唉...\n"NOR, 
		"阿飞"    : HIY"阿飞是我的好兄弟,你有他的消息吗?\n"NOR,
		"liwu"    : (: ask_me :),
                "礼物"    : (: ask_me :),
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 8000000);
        set("score", 200000);

        set_skill("dodge", 100);                
        set_skill("feidao", 200);
        set_skill("parry", 120);                
	set_skill("throwing",200);
	set_skill("force",200);
        
        map_skill("throwing", "feidao");

       
        setup();
		
        
      carry_object("/d/city/obj/cloth")->wear();
}


void greeting(object ob)
{

        int combatexp = (int) (ob->query("combat_exp"));
        if( !ob || environment(ob) != environment() ) return;
	switch ( random(2) ){
		case 0:
command("es ""欢迎光临随缘洗剑录 202.101.10.243 8888 对新入门的新手实行奖励系统. 帮助玩家入门.\n");
			break;
		case 1:
command("es ""随缘洗剑录 202.101.10.243 8888 带您回到笑傲江湖的岁月 实现您的梦想 保证玩家公平竞争.\n");
			break;
	}

        if(combatexp<1000)
        {

        command("bow "+ob->query("id"));
        command("say 你不妨四处看看"HIY"look"NOR CYN",地上有什么东西你都可以捡起来"HIY"get"NOR CYN"收着。你
            可以先查查"HIY"i or inventory"NOR CYN"，看你现在身上有些什么。你要不时地
            查查"HIY"hp"NOR CYN"你的身体状态，要是饿了或渴了就去找些吃的喝的吧。至于
            各种指令的具体用法可以参看 "HIY"help commands"NOR CYN"。"NOR);

        return;
        }
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
int ask_me()
{
  object ob=this_player();
  if( ob->query("shizhe") )
    {command("smile "+ob->query("id"));
     command("say 这位"+RANK_D->query_respect(ob)+"已经拿过我给你的礼物哦！");
     return 1;
    }
    ob->add("combat_exp",20000);
ob->add("potential",10000);
  ob->set("shizhe",1);

  command("addoil "+ob->query("id"));
command("chat "+ob->name(1)+HIR+"得到了我给帮助，开始行走随缘洗剑录上海站(202.101.10.243 8888)！"+NOR+"");
  command("es "+ob->name(1)+"得到了我给帮助，开始行走"+HIY+"随缘洗剑录"HIR"(202.102.230.25 5555)"+NOR+"");
  return 1;
}
