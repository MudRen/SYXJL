//shanlu.c
inherit ROOM;

void create()
{
  set("short","ɽ·");
  set("long","������ɽ�ϵ���·��\n");
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





