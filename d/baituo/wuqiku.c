//wuqiku.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
             "�����ǡ�����ɽ�����ӵ������⣬������ɽ�����ӿ��Ե���\n"
         "��ȡ�����õĸ����������������ɵ����ǲ���������ġ�\n"
        );
        set("exits", ([
                "east" : __DIR__"yuanzi",
        ]));
	set("objects",([
		"/clone/weapon/gangzhang":2,
	]));
        set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",-10);
	set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",-10);
	set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",-10);
	set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}






