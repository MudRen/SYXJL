inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƕ�����ǧ���ֵĺ����ˣ���ط��ܰ�����û��ʲô�ˣ�������
���Ƕ����ɵĺ�ɽ�ˡ������֣����϶���ҩ�����ͽ𶥶��Ǵ����ȥ�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houshan/shandao",
  "south" : __DIR__"houyuan",
]));
	set("no_clean_up", 0);

	set("coor/x",-40);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",90);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
