//shanlu1.c
inherit ROOM;

void create()
{
  set("short","山路");
  set("long","这里是山上的泥路。\n");
  set("exits",([
      "north" : __DIR__"shulin",
      "southeast" : __DIR__"shanlu",
     ]));
  set("outdoors", "baituo");
  set("objects" ,([
      __DIR__"npc/qiaofu" : 1 ,
      ]) );
  set("coor/x",-150);
	set("coor/y",-40);
	set("coor/z",-30);
	set("coor/x",-150);
	set("coor/y",-40);
	set("coor/z",-30);
	set("coor/x",-150);
	set("coor/y",-40);
	set("coor/z",-30);
	set("coor/x",-150);
	set("coor/y",-40);
	set("coor/z",-30);
	setup();
 replace_program(ROOM);
}





