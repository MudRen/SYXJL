//shijie.c
inherit ROOM;

void create()
{
  set("short","石阶");
  set("long","这里是青石板铺成的石阶。\n");
  set("exits",([
      "east" : __DIR__"caoping",
	"northup" : __DIR__"damen",
      "southdown" : __DIR__"guangchang" ,
     ]));
  set("outdoors", "baituo");
  set("coor/x",-130);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-130);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-130);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-130);
	set("coor/y",-50);
	set("coor/z",-20);
	setup();
 replace_program(ROOM);
}





