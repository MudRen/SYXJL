//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","��������");
        set("long",@LONG
����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ�
��һ����ң����顸�����������ĸ����֡��ſ�վ����������������
���£���ִ�ֵ�������������
LONG);
        set("objects", ([
           CLASS_D("dali")+"/zhuwanli": 1,
           __DIR__"npc/weishi2": 1,
           __DIR__"npc/weishi1": 2,
        ]));
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "enter"  : __DIR__"wfdating",
            "south"  : __DIR__"wangfulu",
        ]));
        set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",10);
	setup();
}
