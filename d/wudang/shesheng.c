// Room: shiliang.c ʯ��
// arnzh 97/1/24
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	    ������������,�����վ�,�����ƺ����˶�վ����,
�䵱���Ӿ�����������ϰ�Ṧ.
LONG
	);

	set("exits", ([
		"west" : __DIR__"tyroadct",
	]));

	set("objects", ([
		CLASS_D("wudang") + "/zhangcui" : 1
       ]));

	set("coor/x",-50);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-50);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-50);
	set("coor/y",100);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}

