//Room: /d/dali/langan3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
һ�������ĸ�����ӣ��˼��²�û��ţ��ȴ����ϯΧ��һ����
ɣ�ϵ�С���ݣ���������̡�¥�ϴ��������ɴ�����������
LONG);
	set("objects",([
	    __DIR__"npc/yangcannu" : 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : __DIR__"nongtian5",
	    "up"     : __DIR__"langan4",
	]));
	set("coor/x",140);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

