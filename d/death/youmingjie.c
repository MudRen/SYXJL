inherit ROOM; 
#include <ansi.h>
int num_of_killer;
string call_killer();

void create() 
{ 
        set("short", "幽冥界");
        set("long", @LONG

幽冥界，你疑心怎么从酆都走到这里来了。四处弥漫着浓厚的烟雾，
你什么也看不清楚，空中浮动着若隐若现的鬼火，周围似乎有一双双
眼睛盯着你看，你走了几步，看见地上斜插着一块石碑（shibei），
你连忙俯身下去看上面的字。
LONG);
       set("no_clean_up", 0);
       set("item_desc", ([
        "shibei" : (: call_killer :),
    ]));

       set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"youmingdian",
  "up" : __DIR__"road3",
]));
       
       setup();
        reset();
}

void reset()
{
        ::reset();
        num_of_killer = 5;
}

string call_killer()
{
        object ob;
        if (num_of_killer == 0) 
        return "石碑上写着几个血红的大字：
"HIR"        酆 都 鬼 域 幽 冥 地 府 ！！"NOR"
忽然你觉得背后似乎有脚步声，于是猛然回头一看。。。
什么也没发现，原来是虚惊一场。\n";
        num_of_killer --;
        ob = new(__DIR__"npc/ghost");
        ob->move("/d/death/youmingjie");
        return "石碑上写着几个血红的大字：
"HIR"        酆 都 鬼 域 幽 冥 地 府 ！！"NOR"
忽然你觉得背后似乎有脚步声，于是猛然回头一看。。。\n";
}
