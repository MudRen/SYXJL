// donglang4.c ��������
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������ϣ��������������֡�����һ��֧����������ʵ��ϣ�
��һ�������������������ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ��Ƕ�ʮ��Т
��ͼ�Σ�ÿһ��ͼ������һ�������Ĺ��¡��������������������ʵ
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanhuangdian",
		"northwest" : __DIR__"leizudian",
	]));
	
	set("coor/x",-70);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",290);
	set("coor/z",190);
	setup();
       replace_program(ROOM);

}


