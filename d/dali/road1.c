//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","�ٵ�");
        set("long",@LONG
����һ��������᫵�ɽ����·��������ԭͨ�����Ĺٵ����˴�
�����ϣ�������ȥ����ɽ·ͨ���ƹ�ɽ�����̶��ɴ����Ѵ��������
ȥ�򱱲�Զ��������佻����ɵĽ�®�ˡ�
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */ 
            "southwest"  : __DIR__"road2", 
            "northeast"  : __DIR__"road6",        ]));
        set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
