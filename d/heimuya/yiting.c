inherit ROOM;

void create()
{
        set("short", "议事厅");
        set("long", @LONG
这里是日月神教的聚议厅，是教中议事的地方。时时可以见到教主
同教中各位堂主.长老在此共商大计，教中各堂下属都皆尽叹服。
LONG
        );
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"changlang6",
]));

        setup();
        replace_program(ROOM);
}
