// liangongfang.c 练功房
// by Xiang

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
	这里是练功房，地下凌乱地放着几个蒲团，几位武当弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
		"west" : __DIR__"donglang2",
	]));
	set("objects", ([
       "/d/huashan/npc/muren2" : 3,
               "/d/village/obj/zhujian" : 1]));

	
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",180);
	setup();
	replace_program(ROOM);
}
