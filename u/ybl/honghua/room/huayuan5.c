// by mayue


inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����Ǹ���԰��һ���ļ��������Ÿ�������Ļ��ݣ��������·����߲�
���޵Ĺ�ԡ���԰��һƬ���ţ���������һֻ�۷��������衣�Ա���һ��
Сͤ�ӡ�
LONG
	);
        set("outdoors", "honghua");

	set("exits", ([
                "west" : __DIR__"huating5",
                "north" : __DIR__"huayuan4",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

