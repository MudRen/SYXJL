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
		"east" : __DIR__"huating2",
		"north" : __DIR__"huayuan1",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

