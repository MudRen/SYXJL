inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ɽ��С���������˼�������С��������ֳ�����������ͨ
��ǧ���ֺ��ţ�������ͨ��һ��СϪ����������ȥ�����ֺ�ҩ������·�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"xiaoxi1",
  "northeast" : __DIR__"shandao3",
  "southwest" : __DIR__"shandao",
]));
	set("no_clean_up", 0);

	set("coor/x",-30);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
