// Room: /shaolin/jiulou1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ӭ��¥");
	set("long", @LONG
��Բ������������ӭ��¥����˵�����˲�֪�����˲�����������
ѧʿ���ε��ˣ���ӭ��¥�������޲����ڣ���ȻΪ�����ң�����һ��
���麣�ڵļѻ����Ӵ�ӭ��¥��������¥�²��ü��ף��˿Ͷ��Ǵ�
�ҵ����ˣ������ӣ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG
	);

	set("exits", ([
		"east" : __DIR__"nanyang",
		"up" : __DIR__"jiulou2",
	]));

	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	set("coor/x",-10);
	set("coor/y",120);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
