//      tiantai.c ��̨
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","��̨");
        set("long",@LONG
    ������ѩɽ�µĸߴ������߿ɼ���ΰ�Ĵ�ѩɽ���ϱ߿��Ը��
�����羵��ʥ����
LONG
        );

        set("exits",([
                "west" : __DIR__"neidian",
        ]));

        set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",60);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",60);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",60);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}


