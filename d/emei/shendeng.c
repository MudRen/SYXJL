inherit ROOM;

void create()
{
	set("short", "��Ƹ�");
	set("long", @LONG
������ǧ���ֵ���Ƹ���ʦ̫�Ǻ��������Ϣ�ĵط���һȺ�����
���������죬�������ѵĲ�ˮ�������ͳ�����Ƹ󣬽���һ����Ժ�ӡ�				
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dian4",
  "north" : __DIR__"houyuan",
  "west" : __DIR__"beilang",
  "east" : __DIR__"beilang1",
]));
	set("resource/water", 1);

	set("coor/x",-40);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
