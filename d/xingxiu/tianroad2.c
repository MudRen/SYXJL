// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ��ԭ��
·��ͷ��һƬ���֡����Ͼ������˺��µ����չ���.
LONG
        );
        set("exits", ([
            "northup" : "/d/lingjiu/shanjiao",
            "northdown" : __DIR__"xxh1",
            "south" : __DIR__"tianroad1",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}