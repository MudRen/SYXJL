// Room: /u/setup/conglin3.c



inherit ROOM;



void create()

{

        set("short", "����");

        set("long", @LONG

����һƬ���Ĵ��֡���ʮ�ɸߵĹ�ľ����һ�飬��ʵ��֦Ҷ��һ�����ɡ

��������գ��������ڵ�˿��Ҳ�ޡ����ڴ�����ʱ����ܾã��ֺ�������������

��ֲ������ܶ࣬��������Ӧ�о��С�ż�����г����޳������ˡ���һ�߽�����

��������ɭ�ֵģ���ĸо������㣬Ҫ�����뿪���������˿��ͣ��



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

