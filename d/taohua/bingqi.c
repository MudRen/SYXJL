inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
����һ���ű��������ӡ�����ǹ������ꪵȸ��ֱ������������
���Եı������ϡ��������������ҳ�����Ȼ�Ѿ��þ�û��������
LONG
	);
	set("exits", ([
        "west" : __DIR__"qianyuan",
	]));
	set("objects", ([
        __DIR__"obj/taojian": 5,
	]) );

	set("coor/x",60);
	set("coor/y",-220);
	set("coor/z",0);
	setup();
    replace_program(ROOM) ;
}
