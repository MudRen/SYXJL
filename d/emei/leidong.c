inherit ROOM;

void create()
{
	set("short", "�׶�ƺ");
	set("long", @LONG
������ǧ�������ߵ��׶�ƺ���Ƕ��������׵ĵ����������ĳ�������
��Ƭ�����Ĳ�ƺ��ɢ���ż������׵ĳ��ҵ�С��á�				
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"xiaodao",
]));
	set("objects", ([
          __DIR__"npc/girl3" : 3,  
          __DIR__"npc/nigu2" : 3,
             ]));

	set("coor/x",-90);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",30);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
