
inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
��������������ֵľ�ͷ��������һ�������ûʵĴ�¥���Ŷ�
������һ�����ң�д�š������������ĸ����֣����ǿ����ʵ��ױʡ�
����ͨ���ذ��š�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"west" : __DIR__"di_an1",
		"south" : __DIR__"wangfu2",
		"north" : __DIR__"kang1",
	]));

	set("coor/x",-60);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

