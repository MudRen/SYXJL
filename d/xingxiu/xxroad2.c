// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�����������Լ���Կ������ݳǵĳ�ǽ����������Сɽ��
LONG
        );
        set("exits", ([
  "east" : __DIR__"xxroad1",
  "northup" : __DIR__"xxroad3",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

