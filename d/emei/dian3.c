inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǧ���ֵĽ�����ڴ��ĺ��棬��ʦ̫�������εĵط�������
���������ţ���������ʮ���������̾�����ã������м���Ǿ���ʦ̫��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dian4",
  "south" : __DIR__"dadian",
]));
	set("objects", ([
            __DIR__"npc/jingxin" : 1,
              ]));

        set("no_clean_up", 0);

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
