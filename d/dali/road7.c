//Room: /d/dali/road7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","С��");
        set("long",@LONG
����һ��������᫵�ɽ��С��������ش����ύ�紦��������Զ������
佻����ɵĽ�®��������ͨ�����Ѵ�����Ĺٵ���
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */ 
            "southwest"  : __DIR__"road6", 
            "northeast"  : "/d/huanhua/podi",        ]));
        set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
