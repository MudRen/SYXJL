// yuzhenggong.c ���湬
// by Xiang

inherit ROOM;

void create()
{
	set("short", "���湬");
	set("long", @LONG
	�������䵱�����湬����ʱ���н���ʹ��������߹��������Ǽ�����
����һ��������ʯ�״��ö�����ֱͨ�����������е������壬����������������
����¯������Χ�ϵ���Ը�ˣ�������Ȼ�𾴡�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie12",
		"northup" : __DIR__"shijie21",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));

	set("coor/x",-50);
	set("coor/y",-70);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-70);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-70);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}

