inherit ROOM;

void create()
{
        set("short", "仙人指路");
        set("long", @LONG
这仙人指路其实是东面仙人洞处垂下的一道石梁，远远搭上西边
的莲花崖。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"xian",
		"westup" : __DIR__"lianhua",
]));
	set("objects", ([
                __DIR__"npc/hudie": 2,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
