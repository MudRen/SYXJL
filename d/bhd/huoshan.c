// Room: /u/setup/huoshan.c



inherit ROOM;



void create()

{

        set("short", "��ɽ");

        set("long", @LONG

������������ʲô���������ˣ���������ֻ���б�������ĸо�����������

LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "east" : __DIR__"huoshanjiaoxia",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

