// Room: /u/setup/lvyie1.c



inherit ROOM;



void create()

{

        set("short", "绿野");

        set("long", @LONG

这里是岛屿的东部。极目的是一片看不到尽头的大绿野，是活火山经几

千万年的火山灰堆积而成，平野上一群梅花鹿正在低头吃草，周围一片平静

，绝无可怖之处，远处高山处玄冰白雪，些处却是极目青绿，苍松翠柏，更

诸般奇花异树，皆为中土所无

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "south" : __DIR__"yanshi",

  "north" : __DIR__"lvyie",

]));

        set("no_clean_up", 0);

          set("objects", ([

		__DIR__"npc/lu":3,
          ]));

        setup();

        replace_program(ROOM);

}

