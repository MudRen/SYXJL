// xijie.c ����
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�书���������ƶ����յľ۾��������ֱ������������ֵ���Ҳ�Ե�
�������ҵöࡣ��������һ�����ʧ�޵�С�����Ѿ�ҡҡ��׹�ˡ�������
һ���Ͱ���é�ݣ��������书�����š�������ת�����������ߵ��书���
�����ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"zhongxin",
                "north" : __DIR__"minju2",
                "south" : __DIR__"xiaomiao",
                "west" : __DIR__"ximen",
        ]));
        set("objects", ([
                __DIR__"npc/punk" : 1,
        ]));

        set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
