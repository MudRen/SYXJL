// Room: xiuxishi.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是教中弟子们起居休息的地方。靠墙摆着几一张大床，床头
叠着床薄被，南面的长窗往外可以看到幽静的竹林小院，阵阵山风掠
过，飘来阵阵竹叶的清香。东边通往练功房。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang3",
  "east" : __DIR__"liangongfang2",
]));
        set("sleep_room", "1");
set("no_fight","1");
        set("no_clean_up", 0);

        set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

