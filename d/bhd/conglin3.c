// Room: /u/setup/conglin3.c



inherit ROOM;



void create()

{

        set("short", "丛林");

        set("long", @LONG

这是一片厚厚的丛林。几十丈高的古木簇在一块，密实的枝叶象一蓬蓬巨伞

般伸向天空，把阳光遮得丝毫也无。由于丛林厉时年代很久，又罕有人至，所以

动植物种类很多，飞禽走兽应有尽有。偶尔会有吃肉兽出来伤人。你一走进这这

觉得阴阴森林的，你的感觉告诉你，要尽快离开这里，不能有丝毫停留



LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 4 */

  "south" : __DIR__"conglin",

  "east" : __DIR__"conglin4",

  "north" : __DIR__"conglin4",

  "west" : __DIR__"conglin1",

]));

         set("objects", ([

		__DIR__"npc/bianfu":1,
         ]));

        setup();

        replace_program(ROOM);

}

