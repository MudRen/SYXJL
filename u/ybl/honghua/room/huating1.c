// by mayue


inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����Ǻ컨��������ã��Ǻ컨������Ҫ�µĵط���������������İڷ���
���ź�ľ���Ρ���һ������������ʰ��һЩ�����������Ų������������һ��
��ɫ��Щ���š�
LONG
	);
//      set("outdoors", "honghua");

	set("exits", ([
		"south" : __DIR__"huating2",
		"west" : __DIR__"huayuan1",
		"north" : __DIR__"huating3",
	]));
        set("objects", ([
                "/d/city/npc/main":1,
                "/u/ybl/honghua/npc/xinyan":1,
	]));
    

	setup();
	replace_program(ROOM);
}

