// Room: /d/wuguan/wuguangate.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "武馆大门");
        set("long", @LONG
这里是一个大宅子，门口高悬一个大匾“扬州武馆”，立了两个石狮，
你从大门口瞧进去，好象里面人来人往，都很繁忙的样子，门口站着两个
门卫，神情威严。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                 "north" : __DIR__"wuguandayuan",
                    "south" : __DIR__"wuguangate1",      
        ]));
        set("objects", ([
		__DIR__"npc/menwei" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("combat_exp") >= 10000 
           && present("men wei", environment(me)) 
           && dir =="north")
             return notify_fail("大门里面传出来一个声音：我们这里只接纳初入江湖的新手。\n");
	if (present("men wei", environment(me)) && dir =="south" && me->query("combat_exp") >= 10000)
  	{
      message_vision("门卫拱手说到：“$N，你现在武艺以有小成了，该去江湖上闯荡了。\n",me);
             	me->delete("enter_wuguan");
             	message_vision("$N抖起精神，步出了武馆。从此纵然江湖险恶，也不能庇护在此了！\n", me);
	}
        return ::valid_leave(me, dir);
        
}
