inherit ROOM;

void create()
{
        set("short", "药房");
        set("long", @LONG
这是一间供日月教徒疗伤的药房
LONG
        );
        set("no_fight", "1");
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"chengdedian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/yao" : 1,
]));

        setup();
        replace_program(ROOM);
}
