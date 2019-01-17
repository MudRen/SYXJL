// 忏悔室

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", "忏悔室");
        set("long", @LONG
这里是意图不轨者的牢房，看来你是出不去了。好好反思下你干的事，
你一定是严重违反了玩家条例多次，没人会帮助你了。国有国法，家有家规，
本MUD也有条例，再读读 help rules 吧，如果WIZS不能原谅你，那你就只好
选择自杀 suicide -f 了。请记住这是玩家们共有的世界。
LONG
);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1); 
        set("no_yun", 1);
        set("title",HIR"悔过中... "NOR);        set("valid_startroom", 1);

        setup();
//        "/clone/board/huiguo_b.c"->foo();
}
void init()
{ 
	object ob;
	ob = this_player();
        //::init();	
	call_out("do_check",1,ob);
        add_action("do_action", "");                             
}


int do_action(string arg)
{
       string action = query_verb();

       switch (action) { 
               case "suicide -f":
               case "edit":
               case "wiz":
               case "dun" :               
               case "move":
               case "dazuo": 
               case "more":
               case "cat" :
               case "update" :               
               case "chat":
               case "chat*":
               case "cha":
               case "skills":
               case "goto":
               case "home":
               case "music":
               case "music*":
               case "rumor":
               case "rumor*":
               case "to":
               case "ldj":
               case "ldj*":               
               case "du":
               case "read":
               case "ask":
               case "tell":
               case "reply":
               case "exercise": 
               case "lian":
               case "tuna":       
               case "quit":
               case "dazuo" : 
               case "practice":
               case "es":
               case "es*":               
               case "bidd":
               case "bidd*":               
  write(HIW"这里是专为不轨玩家反思之用的悔过室\n"NOR);
  write(HBRED"一个魔鬼收了你的所有武功和法力! \n"NOR);
  write(HBRED"你面对着魔鬼，现在你什么都干不了了! \n"NOR);
  write(HBRED"忏悔吧! \n"NOR);
                       return 1;
      }
      return 0;
}

int do_check(object ob)
{
 
        if(time()-(int)ob->query("block_time") < 24000)
        {
		call_out("do_check",1,ob);
        	return 1;
        }
        else
        ob->move("/d/city/kedian");
        ob->save();
        return 1;
}        
