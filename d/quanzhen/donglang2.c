// donglang2.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������ϣ��������������֡�����һ��֧�ڱ�������ʵ��ϣ�
��һ���������ϱ���ٵ���ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ��Ƕ�ʮ��Т
��ͼ�Σ�ÿһ��ͼ������һ�������Ĺ��¡���������ٵ���������ٵ
LONG
	);

	set("exits", ([
             "southwest" : __DIR__"lingguandian",
		"north" : __DIR__"sanhuangdian",
	]));
				
	set("coor/x",-70);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",270);
	set("coor/z",190);
	setup();
       replace_program(ROOM);

}

