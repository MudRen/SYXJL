// by mayue


inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����Ǹ���԰��һ���ļ��������Ÿ�������Ļ��ݣ��������·����߲�
���޵Ĺ�ԡ���԰��һƬ���ţ���������һֻ�۷��������衣��һ��ʯ��
С·ͨ��ǰ��һ��������
LONG
	);
        set("outdoors", "honghua");

	set("exits", ([
                "west" : __DIR__"huating4",
                "south" : __DIR__"huayuan5",
                "east" : __DIR__"zoulang",
                "north" : __DIR__"huayuan6",
	]));
        set("objects", ([
                "/d/honghua/dizi" : 4,
	]));
    

	setup();
	replace_program(ROOM);
}

