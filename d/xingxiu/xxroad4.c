// Room: /d/xingxiu/xxroad4.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����ɽ�����˹����������᫵�С·�ϣ������������������
���������׵����
LONG
        );
        set("exits", ([
  "southdown" : __DIR__"tianroad3",
  "north" : __DIR__"xxroad5",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
