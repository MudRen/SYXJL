//Room: /d/dali/shizilukou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ʮ��·��");
	set("long",@LONG
���Ǵ������ڵ���Ҫ��ó����������ɫɫ�Ľ������ڶ��ߴ����
�������಻����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ������
���Ը���������¥�ƣ����������־���פ�أ�����������ӡ�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"center",
	    "south"  : __DIR__"southgate",
	    "east"   : __DIR__"dahejieeast",
	    "west"   : __DIR__"dahejiewest",
	]));
	set("no_clean_up", 0);
	set("coor/x",-10);
	set("coor/y",-130);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-130);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-130);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-130);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
