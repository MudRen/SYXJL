//Room: /d/dali/yuxuguanqian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����ǰ");
	set("long",@LONG
����һ����ۣ���ǰ����д�š�����ۡ��������֣�����һ��
��ˮ������С����������������ʵ���������Եĺõط���
LONG);
	set("objects", ([
	   __DIR__"npc/xiaodaogu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuxuguan",
	    "south"  : __DIR__"hudiequan",
	]));
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}

