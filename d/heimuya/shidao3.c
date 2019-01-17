inherit ROOM;

void create()
{
        set("short", "石道");
        set("long", @LONG
一路往北行，中间仅有一道宽约五尺的石道，两边石壁
如墙，一路上都有日月教徒模样的人物在走动，对往来的路
人都严密监视。
LONG
        );
        set("no_clean_up", 0);
        set("outdoors", "wudang");
        set("exits", ([ /* sizeof() == 2 */
		"east" : "/d/quanzhou/nanmen",
		"north" : __DIR__"shidao",
		"southeast" : "/d/huanhua/xiaoqiao",
		"northwest" : __DIR__"road1",
  
]));

        set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
