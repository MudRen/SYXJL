// by mayue


inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����Ǻ컨��ľ����ã��Ǻ컨��Ӵ����˵ĵط���������������İڷ���
���ź�ľ���Σ�һЩ������ʿ���ڸ���̸����ʲô��
LONG
	);
//      set("outdoors", "honghua");

	set("exits", ([
                "south" : __DIR__"huating5",
                "east" : __DIR__"huayuan4",
                "north" : __DIR__"huating6",
	]));
        set("objects", ([
                "/u/ybl/honghua/npc/xutianhong" : 1,
	]));
    

	setup();
	replace_program(ROOM);
}

