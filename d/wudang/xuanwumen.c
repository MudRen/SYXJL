// xuanwumen.c ������
// by Xiang
// by arnzh 97.1.24 

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
	�������ǰ��һ���ߴ��ʯ��������д�š������š������ֽ���֣���
�������Զ���þ���ɹ���ܣ��Ѿ��Ե���Щ��������������һ��С�Ե꣬��ʱ��
�м������ڳԷ�����Ϣ����������һ��ʯ��·һֱͨ��ɽ�£�������һ������
���ۣ�ȴ���������ʣ����Ǹս��ɲ��á�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
                "west":__DIR__"fuzhen1",
		"southdown" : __DIR__"shijie42",
 		"northup" : __DIR__"xiaochidian",  
//   guangchang",
	]));
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}

