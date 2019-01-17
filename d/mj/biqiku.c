// Room: bingqiku.c

inherit ROOM;

void create()
{
        set("short", "兵器库");
        set("long", @LONG
这里是教中的兵器库，刀枪剑戟、斧钺钩叉十八般兵器，一应俱
全，整整齐齐的放满了几十排兵器架，一批新打造的刀剑象小山一样
堆放在靠门口的地方，五六个教众忙着整理上架，不时传来一阵兵器
撞击的“铿锵~”之声。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang2",
]));
        set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/guangmingjian" : 3,
  __DIR__"obj/guangmingdao" : 3,
  __DIR__"npc/mingjiaodizi" : 1,
  __DIR__"obj/muchui" : 1,
]));
        set("no_clean_up", 0);

        set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

