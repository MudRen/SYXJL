//Room: /d/dali/nongtian4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
	set("long",@LONG
һƬ�ٺ��ĵ�����������ˮ���﹡�ܸߣ��Ҹ�����Թ���
��������ھ����൱�����ˮ��������گ��ˮ���㣬�Ӻ��ڶ࣬��Ȼ
��ɽ�ص��������Ҳ�������⡣��ȥ������Щ������ӡ�
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu2": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southwest" : __DIR__"yangzong",
	    "east"      : __DIR__"dalangan1",
	]));
	set("coor/x",140);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

