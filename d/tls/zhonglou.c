// Room: /d/tianlongsi/zhonglou.c

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
		"south" : __DIR__"yaotai",
		"enter" : __DIR__"zhonglou1",
	]));

	set("objects",([
		__DIR__"npc/seng-bing" : 2,
	]));

	set("outdoors", "tianlongsi");
	set("coor/x",-30);
	set("coor/y",-100);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-100);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-100);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-100);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}



