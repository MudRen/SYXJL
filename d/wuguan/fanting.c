// Room: /d/wuguan/fanting.c
// Date: 99/05/30 by Byt

inherit ROOM;
int valid_leave(object me, string dir);
void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是武馆内用餐的地方。屋里布置很简单, 只摆着几张桌椅
几个人在一声不响地吃着。一个厨子在不停的忙碌着，你可以向他
要食物和水。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"shibanlu3",
        ]));
        set("objects", ([
                __DIR__"npc/chuzi" : 1,
        ]));        
        setup();
}


int valid_leave(object me, string dir)
{

        if (  (dir == "east")
           && ( present("rice", this_player())
                || present("baozi", this_player())
                || present("yuebing", this_player())
                || present("tea", this_player()) )
           && objectp(present("pang chuzi", environment(me))) )
        return notify_fail
                ("胖厨子哼了一声：吃饱喝足了还要带走呀！\n");
        return ::valid_leave(me, dir);
}
