//room:cao1.c
inherit ROOM;

void create()
{
  set("short","草丛");
  set("long",
      "这里是乱草丛。东边是扇拱月形小敞门。\n"
  "其余三面都是齐腰高的蒿草，常有蛇出没。\n"
    );
  set("exits",([
        "west" : __DIR__"cao1",
      "north" : __DIR__"cao2",
	"east" : __DIR__"ximen",
        "south" : __DIR__"cao1",
     ]));
 set("objects",([
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));
 set("outdoors","baituo");
 set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}




