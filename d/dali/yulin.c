//Room: /d/dali/yulin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
����һƬʪ������֣�����ˮ��������·���У�ʮ���ɸߵľ޴�
�����̸���ڣ����ɴֵü����˺ϱ�ҲΧ��ס����������֦�´�����
ˮ�з�������������Ϊ����ľ��¡�������Ȼ�������ޣ�ȴ�Ƿ��ݾ�
�ӵ���������������̨��������Խ�ڴ�������¶�ĸ�֦�ϣ��ö���
���Է���
LONG);
	set("objects", ([
	   __DIR__"npc/lieshou": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"luwang",
	]));
	set("coor/x",10);
	set("coor/y",-190);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-190);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-190);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-190);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

