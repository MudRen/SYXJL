// Room: /u/setup/shulin.c



inherit ROOM;



void create()

{

        set("short", "����");

        set("long", @LONG

��һֱ�߳���ʮ�������һ��Ƭ�����ˡ�ԭ���˵���Բ���㣬����

��������֪��ͷ�������������죬��ɭɭ��������գ�������ʲô�Ź֣�ȴ

�ǲ��ö�֪�����к���֮�˿϶�Ҫ����һ̽�ġ�



LONG

        );

        set("exits", ([ /* sizeof() == 3 */

	"south" : __DIR__"shishan",
	"north" : __DIR__"conglin",
]));

        set("no_clean_up", 0);

        set("objects", ([

		__DIR__"npc/bianfu":2,
         ]));

        setup();

        replace_program(ROOM);

}

