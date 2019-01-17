inherit ROOM;

void create()
{
        set("short", "牢房入口");
        set("long", @LONG
东面一道紧闭着的铁门，门上开了个尺许见方的洞孔，从洞孔望进去，
有个狱卒模样的人在走动着。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houdian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/da" : 1,
]));

        setup();
        replace_program(ROOM);
}
