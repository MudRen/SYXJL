//Room: /d/dali/road6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","�ٵ�");
        set("long",@LONG
����һ��������᫵�ɽ����·��������ԭͨ�����Ĺٵ�����
��Զ��������佻����ɵĽ�®�ˡ�
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */ 
            "southwest"  : __DIR__"road1", 
            "northeast"  : __DIR__"road7",        ]));
        set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
