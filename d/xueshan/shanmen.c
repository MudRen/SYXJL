//      shanmen.c ѩɽ��ɽ��
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","ѩɽ��ɽ��");
        set("long",@LONG
    �������������ѩɽ�¡�������ɽ�������Եø���׳�ۡ�
��Բ�������ڵ���Ͷ����˳��ݡ�
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "north" : __DIR__"guangchang",
                "southdown" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                __DIR__"npc/saxi" : 1, 
   ]));
        set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
