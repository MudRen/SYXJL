inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ƶ��������򵥶�����İڷ���һ�Ŵ���һ��С�������Ϸ�
�ż����𾭣������������ڴ��ϣ�һ������ľ��һ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dlang2",
]));
	set("objects",([
          __DIR__"npc/wenshan" : 1,
               ]));

	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
