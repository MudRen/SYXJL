//      kufang.c �ⷿ
//      Designed by secret (����)
//      97/04/09

inherit ROOM;


void create()
{
        set("short","�ⷿ");
        set("long",@LONG
���������䳡�Աߵ�С�ⷿ��������Щ���õ�������
LONG
        );

        set("exits",([
                "east" : __DIR__"chang",
        ]));

	set("objects", ([
		"/d/village/obj/zhujian" : random(4),
		"/d/xueshan/obj/mugun" : random(4),
		"/d/xueshan/obj/falun" : random(4),
	]));


        set("coor/x",-180);
	set("coor/y",10);
	set("coor/z",40);
	set("coor/x",-180);
	set("coor/y",10);
	set("coor/z",40);
	set("coor/x",-180);
	set("coor/y",10);
	set("coor/z",40);
	set("coor/x",-180);
	set("coor/y",10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}


