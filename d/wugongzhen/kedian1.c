// kedian1.c

inherit ROOM;

void create()
{
        set("short", "客店");
        set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，
你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待
着南腔北调的客人。客店的主人从不露面，他究竟是谁，有各种各样的猜
测。墙上挂着一个牌子(paizi)。
LONG
        );
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜十两白银。\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer1" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"dongjie",
                "up" : __DIR__"kedian2",
        ]));
        set("coor/x",-100);
	set("coor/y",140);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",140);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",140);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",140);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

        if ( me->query_temp("rent_paid") && dir == "south" )
        return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
这不是砸小店的招牌吗？\n");

        return ::valid_leave(me, dir);
}

