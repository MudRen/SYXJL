//JMQJIGUAN.C

inherit ROOM;

void create()
{
	set("short", "��ľ����ľ");
	set("long", @LONG

����ǰֻ��һ�ô��������а��ɣ�ʮ��Ҳ������ס�������о��ڶ�
����֦Ҷ��ï�����ܻ��ƣ���Ȼ�޷�һ��ȫò��������һ���⻬��
�ȣ��ǳ�����Ħ�����ɡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"jmqshulin6",
	]));

	set("outdoors", "mingjiao");
	setup();
//	replace_program(ROOM);
}

void init()
{
