//Room: /d/dali/wuyiminju1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
����һ��������ķ��ݡ�������ӵĽ��غ����򽲾���������ɽ
�ƣ�һ����ʯΪǽ�ͻ�����ľΪ�����ṹ���ºͺ��˷�����£�����
ƽ����ʯ��Χǽ�����Ժ����һȦ������ţ����С�
LONG);
	set("objects", ([
	   __DIR__"npc/muyangnu": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"wumeng",
	]));
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",20);
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",20);
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",20);
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}

