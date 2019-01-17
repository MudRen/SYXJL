// writed by shadow

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "巫师会客室" );
        set("long",
"\n        这里是巫师和玩家交流的地方，如果你有什么问题要向巫师请教，\n"
"可以在这里留言(post)。不过如果问题牵涉到解谜或者已经在帮助文件里\n"
"有详细说明，巫师们就不一定会回答。楼上是巫师休息室，一般玩家到这\n"
"里后就上不去了。\n\n"
""YEL"   1) 对游戏的感慨和牢骚请发表在扬州客店留言板。\n"
"   3) post前请详细查阅巫师的留言，留言中已经声明的不再处理。\n"
"   4) 对游戏意外情况的post请提供详细内容，否则不予处理。\n"
"   5) 处理后意见将从这里删除，答复请见东边的处理室公告。"NOR"\n\n"
);
        set("no_fight", "1");
	set("no_study", 1);
        set("no_sleep_room", 1);
        set("no_yun", "1");
        set("exits", ([
                "up" : __DIR__"wizard_room",
                "southeast" : "/d/city/wumiao",

        ]));

         create_door("southeast", "竹门", "northwest");

        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	setup();

        call_other("/clone/board/towiz_b", "???");
}

void init()
{
        add_action("do_look","l");
        add_action("do_look","look");
}

int do_look(string arg)
{
        object me=this_player();
        if ( !arg ) return 0;
        if ( arg == "up" && !wizardp(me) && wizhood(me) !="(immortal)" ) {
                write("由于上边很高，所以你什么也看不清。\n");
               return 1;
       }
       if ( arg == "board" ) {
               write("这是一个专门给玩家用来和巫师交流的留言板。\n");
               return 1;
       }
        return 0;
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) && wizhood(me) !="(immortal)" )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}


// guest_room.c 巫师会客室
