// Room: /u/setup/haoshanyanshilu.c



inherit ROOM;



void create()

{

        set("short", "火山岩石路");

        set("long", @LONG

岩石路皆由火山灰堆成，厉时久，地面十分坚硬。在这里已可以看见那

缕黑烟之中竟有红火光不断的喷出，原来黑烟之处是一座活火山，走到这里

已感到一丝的热气扑面而来，再走十多里路就到达火山脚下了。

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"yashilu",

  "west" : __DIR__"huoshanjiaoxia",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

