// Room: /u/setup/huoshanjiaoxia.c



inherit ROOM;



void create()

{

        set("short", "火山脚下");

        set("long", @LONG

你越走越热，不觉已至火山脚下。此时已可以看到大火从火山中怒喷而

出，到这里你虽然是只穿单衣也是顶受不住，不觉已是口干舌燥，遍身大汗

，但见身旁已无一株树木花草，只余光秃秃、黄焦焦的岩石。

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"haoshanyanshilu",

  "west" : __DIR__"huoshan",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

