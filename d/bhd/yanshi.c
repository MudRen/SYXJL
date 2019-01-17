// Room: /u/setup/yanshi.c



inherit ROOM;



void create()

{

        set("short", "岩石");

        set("long", @LONG

这是一块露出水面的岩石。但见那火柱的周围一片青绿，原来这里是一

个极大的岛屿。岛屿西部都是尖石嶙峋的山峰，奇开怪样，莫可名状，岛东

却是一片望不到尽头的平野，乃火山灰倾入大海而成。此处虽处北极，但火

山万年不灭，岛上气侯便和长白山、黑龙江一带相似。岛的西部有一山顶有

一山顶正在帽出黑烟。 岩石的南部有几块浮冰(foubing)正向南漂流。往北

便是一片片大绿野。

LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 2 */

  "north" : __DIR__"lvyie1",

  "out" : __DIR__"xiaobing",

]));



        setup();

        replace_program(ROOM);

}

