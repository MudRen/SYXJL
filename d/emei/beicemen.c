inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǧ���ֵı����ţ���������һ��С������ͨ��ɽ�ϣ��������
�����˾������С���Եú��ǻ������Ӳݴ���������ʱ��ЩС�����·
�Ͼ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xdao1",
  "east" : __DIR__"xilang5",
]));
	set("no_clean_up", 0);

	set("coor/x",-70);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
