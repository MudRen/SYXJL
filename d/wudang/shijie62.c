// shijie1.c 石阶
// by Xiang

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
	你走在一条坚实的石阶上，不时地有进香客从你的身边走过。一边是峭
壁，一边是悬崖，抬头隐约可见笼罩在云雾中的天柱峰，听着流水淙淙，令人心
旷神怡。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie61",
		"northup" : __DIR__"guangchang",
	]));
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",170);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",170);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",170);
	setup();
	replace_program(ROOM);
}

