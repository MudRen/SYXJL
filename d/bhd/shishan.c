// Room: /u/setup/shishan.c



inherit ROOM;



void create()

{

        set("short", "ʯɽ");

        set("long", @LONG

����һ��ɽʯ��ɽʯ��Χ�������滨�������������д�����������㣬

���ɲ�֪��֮���䴫����ɽ����¶��һ��ʯ��(dong)��������ͨס��ɽ֮·

���߰��ﴦ��һСʯɽ��������һƬƬ����׵Ĵ����

LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 6 */

  "east" : __DIR__"xiaoshishan.c",

  "southeast" : __DIR__"lvyie",

  "north" : __DIR__"shulin",

  "west" : __DIR__"yashilu",

  "enter" : __DIR__"xiongdong.c",

]));

        setup();

        replace_program(ROOM);

}

