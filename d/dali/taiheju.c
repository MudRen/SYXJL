//Room: /d/dali/taiheju.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�;�");
	set("long",@LONG
���Ǵ����������ľ�¥��¥����Щ������С�ԣ���������
����������·�ˡ�¥����������
LONG);
	set("objects", ([
	   __DIR__"npc/xiaoer2": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"center",
	    "up"    : __DIR__"taiheju2",
	]));
	set("coor/x",0);
	set("coor/y",-120);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-120);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-120);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-120);
	set("coor/z",10);
	setup();
}
