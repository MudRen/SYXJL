// Room: /u/setup/shidong.c



inherit ROOM;



void create()

{

        set("short", "ʯ��");

        set("long", @LONG

�˴�ΪһСɽ�����м�͸��һ����⣬�����촰һ�㡣�������롢����

��ʯ������ߵ�һӦ��ȫ��



LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "out" : __DIR__"xiaoshishan",

]));

        set("no_clean_up", 0);



       set("objects", ([

           "/d/mj/npc/shiwang": 1,
    ]));

        setup();

        replace_program(ROOM);

}

