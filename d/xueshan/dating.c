//      dating.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
    ���������ڵĴ�������λ�е��ĸ�ɮ�ڸ������ۡ�
LONG
        );

        set("exits",([
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"zoulang2",
                "northeast" : __DIR__"chanshi",
                "northwest" : __DIR__"cangjingge",
        ]));
set("objects", ([
"/kungfu/class/xueshan/fawang" :1,
]));

        set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",50);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",50);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",50);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",50);
	setup();
        replace_program(ROOM);
}


