// shanjiao.c ����ɽ��
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
����������ɽ��ɽ�ţ�����ɽ�ų������ĵ�һɽ����ɽ���������
���������ơ������ɽ�ƻ���ƽ����һ��ʯ������ͨ��ɽ�ϡ���ǰ��һ
����ɽ����ͬ����һ���������գ����Թ��˵�ʫ�����С�����һ����
��˵����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"xiaolu1",
                "westdown" : __DIR__"shanlu4",
        ]));
//        set("objects",([
//                __DIR__"npc/youke" : 1,
//                __DIR__"npc/xiangke" : 2,
//        ]));

        set("coor/x",-90);
	set("coor/y",130);
	set("coor/z",20);
	set("coor/x",-90);
	set("coor/y",130);
	set("coor/z",20);
	set("coor/x",-90);
	set("coor/y",130);
	set("coor/z",20);
	set("coor/x",-90);
	set("coor/y",130);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}


