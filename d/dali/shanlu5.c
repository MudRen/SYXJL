//Room: /d/dali/shanlu5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·��
�Լ��ɼ�һЩ����Ĵ���ɽ·���������š�
LONG);
	set("objects", ([
	   __DIR__"npc/wuliangdizi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"shanlu4",
	    "southeast"  : __DIR__"shanlu6",
	]));
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

