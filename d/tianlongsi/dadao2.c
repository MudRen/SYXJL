inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��������ͨ��������ǡ���������
LONG
	);
        set("outdoors", "tianlongsi");

	set("exits", ([
		"west" : __DIR__"dadao3",
                "north" : "/d/dali/dadao1",
	]));

	setup();
	replace_program(ROOM);
}
