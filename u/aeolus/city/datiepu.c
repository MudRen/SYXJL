// Room: /city/datiepu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬
��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���������������ذ
�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG
	);

	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
        set("objects", ([
                 __DIR__"npc/smith": 1,]));

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

