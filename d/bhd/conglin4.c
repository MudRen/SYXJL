// Room: /u/setup/conglin4.c



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

        set("exits", ([ /* sizeof() == 4 */

  "south" : __DIR__"conglin2",

  "east" : __DIR__"conglin2",

  "north" : __DIR__"conglin5",

  "west" : __DIR__"conglin4",

]));

        set("no_clean_up", 0);

         set("objects", ([

		__DIR__"npc/bianfu":1,
         ]));

        setup();

        replace_program(ROOM);

}

