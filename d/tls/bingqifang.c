// bingqifang.c


inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������µı����ң���ǽ��һ�ų����ı����ܣ���������˳�����
������������ĺ��л����ǲ�ͣ�Ĵ��쳤����æ����ͣ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"yuhuayuan",
]));
        set("no_clean_up", 0);
        set("objects", ([
                       __DIR__"obj/muyuchui": 1,
                       __DIR__"obj/changjian": 1,
]));
        set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
