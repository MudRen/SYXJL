// Room: /u/cuer/emei/shandao3.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ɽ��С���������˼�������С��������ֳ�����������ͨ
��ǧ���ֺ��ţ�������ͨ��ҩ�������������Ǿ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shandao4",
  "north" : __DIR__"jxan",
  "southwest" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
