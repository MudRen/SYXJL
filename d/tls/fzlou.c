// Room: tianlongsi/fzlou.c

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����ĵ�������������ŷ�����ʮ���Ʋ����ţ�������һ��
��ľ��̳����̳�Ϸ��Ÿ����Ƶ�ľ�㡣�����߸�����һ��������
ۼ�Ĵ�ƿ���ϲ�̴����֦���������ƣ��뵷ҷ�������һƬ��
��֮�������������Ƿ��ɶ�ɮ�ڽ���˵���ĵط���
LONG
	);

	set("exits", ([
		"up" : __DIR__"fzlou1",
		"east" : __DIR__"shengdian",
	]));

	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}



