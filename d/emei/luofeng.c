inherit ROOM;

void create()
{
	set("short", "�޷�ɽ");
	set("long", @LONG
��������޷�ɽ�ˡ�������ȥ������Ŀ�������Ͱ��ƣ���ɫ����Ҷ��
��ɫ���ƽ����ӳ������ȥ���Ǵ��̵��Ʋʣ�����ǡ��޷���ơ���������
�ڱ���ï�ܵ��������������ԼԼ����С������������ɽ�ġ����ơ���ȴ
�ֿ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"fuhusi",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
