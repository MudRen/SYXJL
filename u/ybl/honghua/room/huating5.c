// by mayue

inherit ROOM;

void create()
{
        set("short", "栖凤楼");
	set("long", @LONG
这里是红花会家眷居住的地方，中间有一棵大槐树，有几个小孩子在大人的看护
下玩耍。
LONG
	);
//       set("outdoors", "honghua");

	set("exits", ([
                "east" : __DIR__"huayuan5",
                "north" : __DIR__"huating4",
	]));
        set("objects", ([
//              "/clone/npc/tong-ren":4,
	]));
    

	setup();
	replace_program(ROOM);
}

