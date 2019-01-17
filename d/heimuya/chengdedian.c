inherit ROOM;

void create()
{
        set("short", "成德殿");
        set("long", @LONG
殿中摆放着一张大桌，桌上放满了文房四宝，墙上挂满了字画，布置得
十分清雅，旁边一道木梯通往上面。
LONG
        );
        set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"yaofang",
  "up" : __DIR__"changjingge",
  "south" : __DIR__"dadian",
  "north" : __DIR__"changlang2",
  "west" : __DIR__"zhuquetang",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ji" : 1,
]));

        setup();
        replace_program(ROOM);
}
