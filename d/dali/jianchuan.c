//Room: /d/dali/jianchuan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
�����ǽ����������ģ����Ӳ��󣬾�����󲿷��������壬����
ȫ��������Ϊ��������ɽ�ߵغ�������ɽ�ֵ�Ұ�޴��Ƥ��ë����
����Ƥ����������͵������˽��ס�����ɽ����������������Ҳ����
��֮;���ϴ���ɽ��ɵִ�����½��
LONG);
	set("objects", ([
	   __DIR__"npc/lieren": 1,
	   __DIR__"npc/pihuoshang": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"jianchuankou",
	    "south"      : __DIR__"cangshanzhong",
	]));
	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
