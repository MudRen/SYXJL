inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
������һ������ͨͨ���᷿���Ƕ������Ĵ��׼ҵ�������ϼ����Ϣ
�ҡ����﷿����������������࣬�����أ���һ�ж�����������һ
����Ⱦ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dlang4",
]));
	set("objects",([
           __DIR__"npc/lmxia" : 1,
               ]));

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
