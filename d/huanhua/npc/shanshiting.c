//shanshiting.c

inherit ROOM;

void create()
{
	set("short", "��ʳ��");
	set("long", @LONG
�㿴�������Ѿ���������������佻����ӣ�Χ�Ű����������š�һ��
�ϳ��ӹ���������ӭ�˹�����ָ��ָ�����������ʣ�µ�Ψһһ��ȳ
���ȵ�С�������εض��������ʼ硣
LONG
	);

	set("exits", ([
               "north" : __DIR__"changlang2",
		]));
	set("objects", ([
		  "/d/city/obj/baozi" : 3,
	]));

	setup();
	replace_program(ROOM);
}
