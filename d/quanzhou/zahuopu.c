// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��ר��Ů���õĶ�����С���ӡ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"xijie",
	]));

    set("objects", ([
                 __DIR__"npc/chen" : 1,
    ]) );


	set("outdoors", "quanzhou");
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

