inherit ROOM;
void create()
{
	set("short", "СϪ");
	set("long", @LONG
����һ�������۵�ɽ��СϪ������������ɽ֮�䣬СϪ��ð��������
��������һ����Ȫ�����ߵ�ֲ��Ҳ��������ԭ�������ïʢ�������л���
������Ϊ�̱ǵ���ǵ�ζ��������СϪ������ȥ����ǵ�ζ��Խ��ԽŨ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xiaoxi2",
  "northwest" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",100);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
