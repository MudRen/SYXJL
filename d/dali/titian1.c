//Room: /d/dali/titian1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
����ˮ�ӹ��������ů������������ɽ�¿����˲�������˼�
���ǵ��£�����������¶��ϣ����ؿ����������֣������ϡ�裬��
�ĵ���ũҵ��Ϊ��󣬶��л����ָ�������ɽ�ϵ�һЩ�����������
���������š�
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"zhenxiong",
	]));
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

