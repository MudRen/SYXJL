inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��Сɽ�������Ͼ���ǧ���ֵĺ����ˡ������ֳ����������
�������Ƕ����ɵĺ�ɽ�ˣ�������ͨ�������ֺ�ҩ������С����������
ͨ���𶥺;��϶���С����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shandao1",
  "north" : __DIR__"houshan1",
  "south" : "/d/emei/houmen",
  "northwest" : __DIR__"shandao2",
]));
	set("no_clean_up", 0);

	set("coor/x",-40);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",100);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
