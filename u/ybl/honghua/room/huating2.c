// by mayue

inherit ROOM;

void create()
{
        set("short", "����ͤ");
	set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣ͤ�ӵ������ż���ͭ�ˡ�
LONG
	);
//       set("outdoors", "honghua");

	set("exits", ([
		"west" : __DIR__"huayuan2",
		"north" : __DIR__"huating1",
	]));
        set("objects", ([
                "/clone/npc/tong-ren":4,
	]));
    

	setup();
	replace_program(ROOM);
}

