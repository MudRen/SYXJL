inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ɽ��С���������˼�������С��������ֳ�������������
ͨ��ǧ���ֺ��ţ�������ͨ����϶�����������ȥ�ƺ��ͽ𶥵�·�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shandao",
  "northwest" : __DIR__"yhrkou",
  "southwest" : __DIR__"xiaojin1",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
