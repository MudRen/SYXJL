//LHQPAIFANG.C

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
����������ɽ��´��һƬ�����أ�����ɽ�»�������ľ���죬����
·�е���һ������Ʒ��������Ʒ�����һƬ��ש���ߣ���������
���죬·������վ�����Ž��ڣ�����ɽ���к����������ڣ������
Ұ��ʵ���ǽ�����һ��������û�е�׳�۾����ɴ��򶫱���ת��
��·ֱͨ����죻�ɴ����������У���Ϊ��ľ�졣��������Ƕ���
֮�ƣ��Թ���������Χ��
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"torjq1",
		"northwest" :__DIR__"tojmq1",
		"northup" : __DIR__"lhqmen",
		"southdown" : __DIR__"shanlu4",
	]));

	set("outdoors", "mingjiao");
        set("objects",([
//			"/kungfu/class/mingjiao/zhangwuji":1,
        		"/kungfu/class/mingjiao/yangxiao":1,
		        "/kungfu/class/mingjiao/fanyao":1,
		        "/kungfu/class/mingjiao/yintianzheng":1,
		        "/kungfu/class/mingjiao/xiexun":1,
		        "/kungfu/class/mingjiao/weiyixiao":1,
			]));
	set("coor/x",-150);
	set("coor/y",-40);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}