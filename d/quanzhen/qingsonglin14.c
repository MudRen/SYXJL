// qingsonglin14.c ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
������������������ʧ�˷��򣬼��ʾ�������������о��Լ�����
������֮�У�ֻҪ�ߴ�һ��������������Σ�գ����г����˿־塣
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"qingsonglin"+(random(10)+2),
		"north" : __DIR__"yadi",
              "west" :__DIR__"qingsonglin"+(random(10)+2),
		"east" : __DIR__"qingsonglin8",
         ]));
	
	set("no_acc_drop",1);
	set("coor/x",-90);
	set("coor/y",310);
	set("coor/z",200);
	set("coor/x",-90);
	set("coor/y",310);
	set("coor/z",200);
	set("coor/x",-90);
	set("coor/y",310);
	set("coor/z",200);
	set("coor/x",-90);
	set("coor/y",310);
	set("coor/z",200);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{

	if (dir == "north" ) me->add_temp("bamboo/count", 1);
	else 			 me->add_temp("bamboo/count", -1);

	return ::valid_leave(me, dir);
}
