// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
	����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG
	);

	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));

        set("objects", ([
                __DIR__"npc/qian" : 1
        ]));

	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

