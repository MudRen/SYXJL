
inherit ROOM;

void create()
{
	set("short", "ȫ�۵¾�¥");
	set("long", @LONG
	��Բ������������ȫ�۵¾�¥����˵�����˲�֪�����˲�����
¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·
ȥ�ˡ�¥����������
LONG
	);

	set("exits", ([
		"east" : __DIR__"wangfu2",
		"up" : __DIR__"jiulou2",
	]));

	set("objects", ([
                  "/d/city/npc/xiaoer2" : 1,
	]));

	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

