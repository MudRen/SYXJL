// Room: /d/quanzhou/xijie.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ȫ�ݵ�����֣�������һ���ưܵ�լ�ӡ�������һ���ӻ��̣�
ר��Ů�˼��õĶ��������˲����Խ�ȥ�������Ǹ��÷��̡�
LONG
	);

	set("exits", ([
                "east" : __DIR__"zhongxin",
                "north" : __DIR__"laozhai",
                "west" : __DIR__"zahuopu",
                  "south":"/d/city/bupu",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && ((string)me->query("gender") =="����") && !wizardp(me))
                return notify_fail("�������ү�Ƕ�ȥ�Ǹ����\n");
        return 1;
}


