//      cedian2.c ���
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µ�����ǽ��������ŷ��洫���Ĺ��¡�
LONG
        );

        set("exits",([
                "up" : __DIR__"zoulang2",
                "east" : __DIR__"dadian",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/samu" : 1,
                __DIR__"npc/xiang-ke" : 1,
        ]));

        set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",40);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="ѩɽ��") && dir=="up"
        && objectp(present ("samu huofo" ,environment(me) ))) 
                return notify_fail("��ľ���˵�� : ���ѩɽ�µ��� ,��������!! \n");
        return ::valid_leave(me,dir);
}