// bingqifang.c 练功房

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
	这里是华山派的兵器房，四周放这几个兵器架，上面是华山派各
弟子平时练剑用的竹剑。
LONG
	);
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 4]));

	set("no_fight", 1);
	
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}