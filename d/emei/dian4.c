inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������ǧ���ֵĺ��ڽ�����ĺ��棬��ʦ̫�������εĵط�������
���������ţ���������ʮ���������̾�����ã������м���Ǿ���ʦ̫����
����������Ƹ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shendeng",
  "south" : __DIR__"dian3",
]));
	
        set("objects", ([
            __DIR__"npc/jinghe" : 1,
              ]));

	set("coor/x",-40);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",60);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
