// baishulin3.c ������
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���߽��˰����ֵ�������²��ź�����Ҷ��������������Ĺ�
�߷ǳ��������㼸��ʲô���������ˡ�ͻȻһֻ���������ǰ����֦����
�����˹�ȥ��������һ����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"cuipingfeng",
                "east" : __DIR__"baishulin4",
                "southdown" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-100);
	set("coor/y",180);
	set("coor/z",40);
	set("coor/x",-100);
	set("coor/y",180);
	set("coor/z",40);
	set("coor/x",-100);
	set("coor/y",180);
	set("coor/z",40);
	set("coor/x",-100);
	set("coor/y",180);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}

