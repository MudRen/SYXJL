inherit ROOM;

void create()
{
        set("short", "���޹�");
        set("long",@LONG
����������㵽����ΰ�������ʿ�������������Χ��һ������ɮ
���ּۻ��ۡ������Ƿ����ɮ����ڵĵط����������������µ��ص��ˡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"doumugong",
                "west" : __DIR__"jialan",
        	"north" : __DIR__"mianbishi",
	]));
	set("objects",([
                __DIR__"npc/guest" : 4,
		__DIR__"npc/laoniansengren" : 1,
                __DIR__"npc/gui-bao" : 1,
        ]));
        set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
