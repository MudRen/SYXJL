//      kedian.c �͵�
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","�͵�");
        set("long",@LONG
    ������һ��·�ߵ�С�͵ꡣ���������˶�������������Ϣ��������
·���Ե�����ԭ��
LONG
        );

        set("valid_startroom",1);

        set("exits",([
                "east" : __DIR__"tulu2",
        ]));
set("objects", ([
  __DIR__"npc/xiaoer2" :1
]));

        set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

