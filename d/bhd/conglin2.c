// Room: /u/setup/conglin2.c



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

  "south" : __DIR__"conglin3",

  "east" : __DIR__"conglin4",

  "north" : __DIR__"conglin5",

  "west" : __DIR__"conglin1",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

