//Room: /d/dali/garments.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","Ѧ�ǳ�����");
	set("long",@LONG
����һ�����ֺŵĹ���ׯ����������˸�ʽ���������
�񡢾˿������Ƥ������춷��л������ȹ��ˮ��ɫ
�ް�������ɫ�Ż���������һ���㡣
LONG);
	set("objects", ([
	   __DIR__"npc/xueboss": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south" : __DIR__"taiheeast",
	]));
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

