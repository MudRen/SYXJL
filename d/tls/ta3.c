inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
������������֮һ�������Ƴ��������Զ����Ȼ�����Ѿ�ʯ���߲���
������Ȼ����ͦ�Σ�ٲȻ�������°���������������
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "east" : __DIR__"talin",
        ]));
	set("objects",([
                __DIR__"npc/guest" : 2,
        ]));
        set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
