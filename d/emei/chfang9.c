// Room: /u/cuer/emei/chfang9.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ʦ̫���������򵥶�����İڷ���һ�Ŵ���һ��С��������
���ż����𾭣�����ʦ̫�������ڴ��ϣ�һ������ľ��һ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dlang1",
]));
	set("objects",([
           __DIR__"npc/wenling" : 1,
             ]));

	set("coor/x",-30);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",60);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
