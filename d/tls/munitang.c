inherit ROOM;

void create()
{
        set("short", "Ĳ����");
        set("long",@LONG
���Ǹ�ɮ�ǵľ���֮��������ȫ����ľ�Ƴɣ�����ľ����ľ�Ͼ���ȥ
Ƥ����Ȼ���ӣ���һ·������̻Ի͵ĵ��ý�Ȼ��ͬ������һ������
�泯���һ��������
LONG
        );
        set("exits", ([
		"east" : __DIR__"banruotai",
		]));
        set("objects",([
		__DIR__"npc/kurong" : 1,
        ]));
        set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
