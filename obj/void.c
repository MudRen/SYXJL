inherit ROOM;

void create()
{
        set("short", "十八层地狱");
        set("long", @LONG

一片血的海洋！
LONG
        );


        set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/city/wumiao",
]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
        replace_program(ROOM);
}
