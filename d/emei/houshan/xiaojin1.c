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
  "northeast" : __DIR__"shandao2",
  "west" : __DIR__"xiaojin2",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
