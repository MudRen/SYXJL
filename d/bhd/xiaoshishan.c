// Room: /u/setup/xiaoshishan.c



inherit ROOM;



void create()

{

        set("short", "Сʯɽ");

        set("long", @LONG

����һ��Сɽʯ����֮�����ʯɽΪСɽʯ��Χ�������滨��������

�����д�����������㣬���ɲ�֪��֮���䴫����ɽ����¶��һ��Сʯ��

(dong)��������һʯɽ

LONG

        );

        set("exits", ([ /* sizeof() == 3 */

  "west" : __DIR__"shishan",

  "enter" : __DIR__"shidong",

]));

        set("no_clean_up", 0);

    set("objects", ([

		__DIR__"npc/longwang": 1,


]));

        setup();

        replace_program(ROOM);

}

