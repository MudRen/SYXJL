//TOHSQ5.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ˮ��Խ��Խ��ɽ�������ŨŨ��ˮ����ɽ·�ϣ����ѵ�ɽ
϶�У�������һ����ϸϸ��Ȫˮ�����һ�ɳα̵�СϪ����ɽ��
������ȥ����Χ���⵴���������������������ɾ���
LONG
	);

	set("exits", ([
		"north" : __DIR__"tohsq6",
		"south" : __DIR__"tohsq4",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}