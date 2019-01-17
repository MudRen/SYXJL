inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是文怡的禅房。简单而整齐的摆放着一张床和一张小桌，桌上放
着几本佛经，文怡正端坐在床上，一边敲着木鱼一边念经。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dlang5",
]));
	set("objects", ([ 
             __DIR__"npc/wenyi" : 1
                   ]));
	
        set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
