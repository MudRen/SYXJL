// minju2.c ���
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����é�ݴ�ķ��ݣ���ͽ�ıڣ��ݽǵ��׸��ǿյģ�������
��ˮ��Ҳ�ǿյġ�����ȱ�첲���ȵ����ο�ǽ���š����������Ѿ�����
����ֵǮ�Ķ���ȫ�������ˡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-120);
	set("coor/y",140);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",140);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",140);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",140);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

