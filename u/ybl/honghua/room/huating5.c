// by mayue

inherit ROOM;

void create()
{
        set("short", "�ܷ�¥");
	set("long", @LONG
�����Ǻ컨��Ҿ��ס�ĵط����м���һ�ô������м���С�����ڴ��˵Ŀ���
����ˣ��
LONG
	);
//       set("outdoors", "honghua");

	set("exits", ([
                "east" : __DIR__"huayuan5",
                "north" : __DIR__"huating4",
	]));
        set("objects", ([
//              "/clone/npc/tong-ren":4,
	]));
    

	setup();
	replace_program(ROOM);
}

