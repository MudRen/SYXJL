// Room: /d/death/road3.c



inherit ROOM;



void create()

{

	set("short", "·�ľ�ͷ");

	set("long", @LONG



..... ��û�뵽 ....



LONG

	);

	set("exits", ([ /* sizeof() == 1 */

  "down" : "/d/death/youmingjie",
  "south" : "/d/death/road2",

]));

        set("no_dun",1);

	setup();

	replace_program(ROOM);

}

