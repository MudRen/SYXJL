// tianshan: /d/xingxiu/shanjiao.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ɽ���£������Ǹ������Ƶ���ɽ�������ʱ����Կ���ɽ��
�ϵı�����һ����ɽ�������Ϊ���롣�������������ľ۾������Ͻ���
�ޱߵ���������ɴ�ɳĮ�����������ǵ�����ɽ�ıؾ�֮·��
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad1",
		"west" : "/d/kunlun/shanjiao",
            "northwest" : __DIR__"beijiang",
            "southwest" : __DIR__"nanjiang",
            "southeast" : __DIR__"silk4",
]));
        set("no_clean_up", 0);
        set("outdoors", "��ɽ");
        set("objects", ([
            __DIR__"npc/trader" : 1]));

        set("coor/x",-110);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",30);
	set("coor/z",0);
	setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    int current_water;
    if (dir == "southwest") {

        if (!userp(me)) return 0;
        current_water = me->query("water");
        if (current_water==0) {
        }

        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }

        if (current_water>20) {
            me->set("water",current_water-20);
        }
        return ::valid_leave(me, dir);
    }
        return ::valid_leave(me, dir);

}
