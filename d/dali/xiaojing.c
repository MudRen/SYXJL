//Room: /d/dali/xiaojing.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ��С��");
	set("long",@LONG
������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�������
Ҷ������ϡ�ɡ������ౡ�����ϰϰ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"    : __DIR__"jinzhihe",
	    "westup"  : __DIR__"dadieshui",
	]));
	set("no_clean_up", 0);
	set("coor/x",50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

