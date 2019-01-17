// Room: /u/setup/xiongdong.c



inherit ROOM;



void create()

{

        set("short", "熊洞");

        set("long", @LONG

此处为一熊洞，洞内极是宽敞，有八九丈深，中间透入一线天光，宛似

天窗一般。此洞以前有几条白熊在此居处，但后来张翠山夫妇杀熊而住在此

处，故此陶碗、土灶、石床、粗具等一应俱全



LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "out" : __DIR__"shishan",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

