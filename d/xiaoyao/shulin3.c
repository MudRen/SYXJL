// Room: /d/xiaoyao/shulin3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG
	);
	set("objects", ([ ]));
	set("outdoors", "xiaoyao");
	set("exits", ([ /* sizeof() == 4 */
	"west" : "/d/wudang/wdroad4",
  "south" : __DIR__"shulin3",
  "north" : __DIR__"shulin3",
  "east" : __DIR__"shulin2",
]));
	set("no_clean_up", 0);

	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}