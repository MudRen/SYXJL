// fu-zhangfang �ʷ�
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
�����Ǻ�Ա��ҵ��ʷ���������ש�̵أ����Ŵ������һ�����ӣ�
һ���ܼ�����������С�۾���ס�ظ�����ת���������ڴ�ʲô����
�⡣
LONG
        );
        set("exits", ([
                "east" : __DIR__"fu-datang",
        ]));
        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));

        set("coor/x",-110);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

