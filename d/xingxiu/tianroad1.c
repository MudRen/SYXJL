// tianroad1.c
// by QingP

inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��ԭ����ԭ��һλ�����˸���һȺ�������򶫿�����ɽ�����ߴ�����
�����޵�Х����
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"shanjiao",
            "north" : __DIR__"tianroad2",
]));
        set("objects", ([
                __DIR__"npc/herdsman" : 1,
		__DIR__"npc/sheep" : 3,
        ]));

        set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}