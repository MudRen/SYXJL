//shanlu.c
inherit ROOM;

void create()
{
  set("short","山路");
  set("long","这里是山上的泥路。\n");
  set("exits",([
      "northwest" : __DIR__"shanlu1",
      "southeast" : __DIR__"guangchang",
     ]));
  set("outdoors", "baituo");
  set("coor/x",-140);
	set("coor/y",-50);
	set("coor/z",-30);
	set("coor/x",-140);
	set("coor/y",-50);
	set("coor/z",-30);
	set("coor/x",-140);
	set("coor/y",-50);
	set("coor/z",-30);
	set("coor/x",-140);
	set("coor/y",-50);
	set("coor/z",-30);
	setup();
 replace_program(ROOM);
}





