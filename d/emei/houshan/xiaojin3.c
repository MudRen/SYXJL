inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ������ͨ�ĵ�С���������Ǵ�����У����п������ŵ��ö�����
����һ��СϪ����С·�İ��ߣ�ǰ�����������ľ��϶��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xiaojin2",
  "west" : __DIR__"jldong",
]));
	set("no_clean_up", 0);

	set("coor/x",-80);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
