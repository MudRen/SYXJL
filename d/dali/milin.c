//Room: /d/dali/milin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�˴�ɽ����խ����ľ�ر�ï�ܣ�ɽ��̤������С�����ݺύ����
��ľ�ڵ��谭�ţ���·�߲�ͣ���õ�������·������˳��ǰ��������
��ɽ������������ʱ�������޾��ߣ�ż�����ܿ��������Ŀ�ȸ�ɹ���
LONG);
	set("objects", ([
	   __DIR__"npc/qingshe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"yangzong",
	    "southup"    : __DIR__"shanjian",
	]));
	set("coor/x",120);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-120);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
