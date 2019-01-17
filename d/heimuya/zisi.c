inherit ROOM;

void create()
{
        set("short", "紫石崖");
        set("long", @LONG
片片粉石中忽起出一处冲天石崖，通体却是紫色，阳光映照下，石体
闪闪欲动，非常陡峭。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"taohua",
]));
        set("objects", ([
                __DIR__"npc/bee": 2,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
