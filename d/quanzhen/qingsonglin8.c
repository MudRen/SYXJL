// qingsonglin8.c ������

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
		"south" : __DIR__"qingsonglin14",
		"north" : __DIR__"qingsonglin"+(random(10)+2),
              "west" :__DIR__"qingsonglin"+(random(10)+2),
		"east" : __DIR__"qingsonglin7",
         ]));
	set("coor/x",-90);
	set("coor/y",320);
	set("coor/z",200);
	set("coor/x",-90);
	set("coor/y",320);
	set("coor/z",200);
	set("coor/x",-90);
	set("coor/y",320);
	set("coor/z",200);
	set("coor/x",-90);
	set("coor/y",320);
	set("coor/z",200);
	setup();
	replace_program(ROOM);
}

