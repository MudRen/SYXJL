// Room: /d/emei/dadian.c

inherit ROOM;

void create()
{
	set("short", "ǧ���ִ��");
	set("long", @LONG
����ڷ���ׯ�ϣ����·����������ţ����������һ������������̨ǰվ
��һλüĿ���������������Ů�ᣬ����Ƕ�ü�ɵ����Ŵ�ʦ�㣬������������
��ʦ̫���岻�ʣ�����һӦ��С���񶼽����˴�ʦ�����
LONG
	);
         set("valid_startroom",1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xilang6",
  "south" : __DIR__"dian2",
  "north" : __DIR__"dian3",
  "east" : __DIR__"dxiang",
]));

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
