
inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
����һ��С��԰����Ȼ������̫�࣬ȴʮ��������࣬����ƽ��
����������ɨ����԰������һ����á�
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
  		"east" : "/d/city2/kang3",
  		"north" : "/d/city2/fotang",
	]));
	set("coor/x",-70);
	set("coor/y",210);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
