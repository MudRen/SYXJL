//Room: /d/dali/shanlu3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
һ����ɽ·���Ѵ�����ï�ܵ�ɭ���У��򶫲�Զ�ɴ���������
��--����ǣ���ȥ�������ɽ�����ڽӽ��������ģ�����·��������
��ƽ��������ɽ����᫣���·�������ѡ�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : __DIR__"shanlu2",
	    "east"    : __DIR__"northgate",
	]));
	set("no_clean_up", 0);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

