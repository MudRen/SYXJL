// Room: zoulang2.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
一条宽阔的长廊，四周没有什么饰物，光滑的石壁上有着一些天
然的纹理，时而有一些教众匆匆走过，但似乎从没人留步去仔细地望
一望这些美丽而又古怪的花纹。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"biqiku",
  "east" : __DIR__"shiwangdian",
]));
        set("no_clean_up", 0);

        set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

