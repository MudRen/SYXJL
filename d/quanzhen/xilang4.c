//xilang4.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������������ϡ�����һ��֧�ڱ�����ϼ����ϣ���һ��
�����ϱ�Ԫ������ݶ����������ȶ��ߵ�ǽ�Ͽ���һֻ����ͭ�򣬸���
λ��ʮ����Ф�Ļ������������ţ�ǡ���צ�����졢���ǡ���β��������
���롢�ﾱ�����ۡ����������Ρ��������ϼ��������Ԫ���
LONG
	);

	set("exits", ([
	     "north" : __DIR__"yuanchendian",
             "southeast" : __DIR__"nanjidian",
	]));
	set("coor/x",-120);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",290);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}