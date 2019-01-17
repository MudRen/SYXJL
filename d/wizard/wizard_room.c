// wizard_room.c 巫师休息室
// writed by shadow

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC "巫师休息室" NOR );
        set("long",
"这里就是「"HIB"随缘洗剑录"NOR"」巫师的休息所在，刚粉刷过的四周墙壁\n"
"上光秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫\n"
"师留言簿(board)。\n"
HIR"WIZ天条：任何人不能随意给玩家更改数据，违者PURGE。\n"
"         私自给予玩家物品或泄漏迷题者，做降级处理。\n"NOR);
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);


        set("exits", ([
                "up" : __DIR__"arch_room",
//              "enter" : "/adm/room/meeting_room",
                "down" : __DIR__"guest_room",
        ]));

        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",10);
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",10);
        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",10);
	setup();

        call_other("/clone/board/wiz_b", "???");
}

void init()
{
        object ob=this_player();
        if ( !wizardp(ob) && wizhood(ob) !="(immortal)" )
        {
                ob->move(__DIR__"guest_room");
                return;
        }
}




