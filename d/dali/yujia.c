//Room: /d/dali/yujia.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG
���Բ�ר�����ԣ�����������������������һ����ͨ����¥��
�²�ͨ��������Ȧ���޲��������Ĺ��һλ̨�ĸ�Ů����ϸ�ĵ�
"��֯������¥����һ��ľ�ܣ����������ŵ��㣬������ɹ��ɡ�
LONG);
	set("objects", ([
	   __DIR__"npc/funu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"hexi",
	]));
	set("coor/x",-20);
	set("coor/y",-210);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-210);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-210);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-210);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

