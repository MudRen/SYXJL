inherit ROOM;

void create()
{
        set("short", "青龙堂");
        set("long", @LONG
大堂设许多各式的刑具，在微弱的烛光之下，散发着冰冷的寒光，令人
越看越是心中发毛，想像受刑之人那种惨状及那凄惨的叫声，心中更感
到一阵惊怖。
LONG
        );
        set("no_fight", "1");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aaa" : 1,
]));
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changlang2",
]));

        setup();
        replace_program(ROOM);
}
