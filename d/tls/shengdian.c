// shengdian.c

inherit ROOM;

void create()
{
        set("short", "ʥ��");
        set("long", @LONG
����������������ʥ�ĵط��������������˻ƽ����ɵķ�������
�乩����һ�����׸ߵĴ��������󣬹�����ȥ�����Ӳӣ����е�һ��
�޲����ֳ��������ڴ�����������ϵĵ�λ������ǰһ���Ϻ�������ϥ
��������ȫ���������ݽ���Ӱ�졣
LONG
        );

       set("exits", ([
               "north" : __DIR__"zoulang1",
               "south" : __DIR__"doushuai",
               "east" : __DIR__"jialan",
               "west" : __DIR__"fzlou",
       ]));
        set("objects", ([
                __DIR__"npc/benxiang": 1,

]));
        set("no_clean_up", 0);
        set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        set("valid_startroom", 1);

}

