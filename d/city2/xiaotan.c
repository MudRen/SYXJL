
inherit ROOM;

void create()
{
	set("short", "С̯");
	set("long", @LONG
����һ��ʱ��ɵ�С̯������ȴ�ǳ���¡��·�˶�����������ţ�
�������������������ǵ�������Ȥ��С���Ҵ�ææ�ؽӴ�����������
�Ŀ��ˡ������°��ż���Сľ�������������˸��ָ��������ˡ�
LONG
	);

        set("no_sleep_room",1);


	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
                "/d/huashan/npc/youke" :2,
	]));

	set("exits", ([
		"east" : __DIR__"road8",
	]));

	set("coor/x",-10);
	set("coor/y",170);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir == "east")&& present("mian", this_player())
	&& objectp(present("xiao er", environment(me)))&&living(present("xiao", environment(me))))
	 return notify_fail("\nС��׷����˵������λ�͹٣����滹��������߰���\n");
return ::valid_leave(me,dir);
}