// Room: /d/tianlongsi/fzlou1.c

inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ��ɴ��͵ĵط�����ǽ�����������һ��̫ʦ�Ρ���
��ǽ�Ϲ���һ��������ǽ��һ�������ż���������и��������
�����ˡ����ݴ�������׭�֣������������ڣ��ƺ��Ǹ�����²衣
�����Ƿ����ҡ�
LONG
	);

	set("exits", ([
		"up" : __DIR__"fzlou2",
		"down" : __DIR__"fzlou",
	]));

	set("objects",([
//		CLASS_D("shaolin") + "/qing-le" : 1,
	]));

	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",40);
	setup();
}

int valid_leave(object me, string dir)
{
	int skill;

	skill = me->query_skill("buddhism", 1);
	if (!wizardp(me) && skill < 101)
	{
		if (dir == "north" )
		{
			return notify_fail("���ʸ񲻹������ܽ��뷽���ҡ�\n");
		}
	}
	return ::valid_leave(me, dir);
}


