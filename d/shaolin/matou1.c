// Room: /d/shaolin/matou1.c
// Date: Hop 97.06.13

inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
�����Ǻ�ˮ�ϰ���һ������ͷ���׳ơ�С�������һ���ļ�
�����������˵������ַǷ������治Զ���ǻ�ɽ���¡������Ϸ�
���Ͽ�������ԼԼ�ؿ������ݳǵ�Ӱ�ӡ���������֡������ǵ�
��ء����ֿ��Ե�����ȥ�ܵ㾭���Ǳ�ܡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"hanshui1",
//            "east" : "/u/smok/entrance_road",
            "north" : "/d/shaolin/hanshui3",
	]));

	set("objects", ([
		"/d/city/npc/chuanfu1" : 1,
	]));
	set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



