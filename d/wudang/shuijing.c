// Room: /city/chaguan.c
// YZC 1995/12/04 
//arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "ĥ�뾮");
	set("long", @LONG
	��һ�߽������͸е�һ������������Ƣ������Ϊ֮һˬ���������˼������ˣ���
����̸Ц����ͷ�Ӷ����м���һ�ھ����������ˣ�����������Ϣһ�£�װһЩˮ��
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"haohan",
	]));

	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",90);
	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",90);
	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",90);
	setup();
	replace_program(ROOM);
}

