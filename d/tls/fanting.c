inherit ROOM;
create()
{
	set("short", "ի��");
	set("long", @LONG
���������������ɮ��ի�ĵط���ի���������������
ǧ��ͬʱ���͡��Ӷ�����һ���Ű����˳����Ĳ����ͳ��ʣ���λ
С����������æµ�Ų�����ի�����ϰ��˼����زˡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"yuhuayuan",
		"west" : __DIR__"fanting1",
	]));

	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
		__DIR__"obj/qingshui-hulu" : 1,
		__DIR__"obj/sucai" :3,		
	]));
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (( present("qingshui-hulu", me)||present("sucai", me))
	&&objectp(present("shaofan-seng", environment(me))) )
	{
		if ((dir == "east") || (dir == "west"))
		{
			return notify_fail("�����ӷ�,���ʳ������������ɮ�˳�ʲô !\n");
		}
	}
	return ::valid_leave(me, dir);
}


