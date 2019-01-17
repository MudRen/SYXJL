// Room: /d/tianlongsi/gulou.c


inherit ROOM;




void create()
{
	set("short", "��¥С��");
	set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ�����
���ᣬ�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ����
�յ�������������ǵ�����һ������̬άФ��������������֮
�֡�������ڴ�����һ�ȹ��ε�Сľ�ţ����������ò���Ϳ�棬
��������������ɽ�������ڷ𽲾�ʱ�����Ρ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"yaotai",
		"enter" : __DIR__"gulou1",
	]));

	set("objects",([
		__DIR__"npc/seng-bing" : 2,
	]));

	set("outdoors", "tianlongsi");
	set("coor/x",-30);
	set("coor/y",-120);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-120);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-120);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-120);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;

	return ::valid_leave(me, dir);
}


