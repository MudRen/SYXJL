
//xiangfang.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
�����Ǽ䲻��ķ��ӡ���ǽ����һ��̴ľ������������������Ŀ���ǽ
�ߣ�����ĳ���������Կ����ľ�������СԺ������ɽ���ӹ���Ʈ����
����Ҷ�����㡣
LONG
	);

	set("exits", ([
                "east" : __DIR__"dating",
		]));

	setup();
	replace_program(ROOM);
}
