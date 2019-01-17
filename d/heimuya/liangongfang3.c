inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
一间宽敞的房间，空荡荡的没有任何摆设，地下铺着坚实的青石板。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"liangongfang2",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-ren" : 2,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
