inherit ROOM;

void create()
{
	set("short", "ҩ����");
	set("long", @LONG
������Ƕ��������ľ��϶��ˣ�һ���ܿտ��Ĵ��ڣ������˸��ֵ�
ҩ��¯����һ�����������ָ�������˸ɻ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao4",
]));
	set("objects",([
       __DIR__"npc/jingci" : 1,
     ]));

	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
