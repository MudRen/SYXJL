//Room: /d/dali/minadian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ɵ�");
	set("long",@LONG
���������ķ�֧�����������۾ӵ����ӣ����������ɵ�����ݡ�
������Ϫ��������ˮ������ı��������ũҵ��Թ������������Ϸ�
����о���Щ��ª����ӣ�Ҳ�������̹�����
LONG);
	set("objects", ([
	   __DIR__"npc/shaonu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"gelucheng",
	    "southwest" : __DIR__"zhenxiong",
	]));
	set("coor/x",-50);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

