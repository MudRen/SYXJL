// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
	��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�����
�Ǹ������ڡ�
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
