// Room: /u/setup/yashilu.c



inherit ROOM;



void create()

{

        set("short", "��ʯ·");

        set("long", @LONG

����һ��ʯ·���ɴ�ȥ��ɽ������ʮ����·�����ڴ��ѿ��Կ�������ɽ

��һ�ƺ��̳��������ʯ·���ɻ�ɽ�Ҷѳɣ���ʱ�ã�����ʮ�ּ�Ӳ��

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"shishan",

  "west" : __DIR__"haoshanyanshilu",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

