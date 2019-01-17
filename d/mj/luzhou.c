// Room: luzhou.c

inherit ROOM;

void create()
{
        set("short", "沙漠绿洲");
        set("long", @LONG
在这狂风呼啸，烈日炎炎的大沙漠中，一片沙漠绿洲象海
市蜃楼般浮现在你的面前。一片片翠绿的椰子树，一洼洼清澈
的湖水，以及那连绵的青草地。几只小鸟在一边饮水，一边歌
唱，好不悠闲！！！！
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhang-shi",
  "south" : "/d/xingxiu/silk2",
  "north" : __DIR__"shanjiao",
  "east" : __DIR__"yuanzhenju",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");
        set("can_dig",1);
        set("dig_out",50);

        set("coor/x",-80);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-80);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-80);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-80);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

