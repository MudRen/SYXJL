// Room: /u/setup/conglin1.c



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

  "south" : __DIR__"shulin",

  "north" : __DIR__"conglin1",

]));

        set("no_clean_up", 0);

          set("objects", ([

		__DIR__"npc/mang":1,
          ]));

        setup();

        replace_program(ROOM);

}

