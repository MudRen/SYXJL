//Room: /d/dali/sheguta.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�߹���");
	set("long",@LONG
�߹���λ�ڴ�����ڣ����ڵ��ɽб���嶫�¡��ഫ����������
�������١�����β�����ڣ���ˮ���ģ�����ʿ�γ��ֻ�����������
��ͬ���ھ������˽�������ˮ�ƣ����߹ǻ�����ˮ����Ϣ������һ��
�ܴ�ʽ����ש����
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"taihejiekou",
	    "west"  : __DIR__"qingchi",
	]));
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

