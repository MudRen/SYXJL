// Room: shanpo2.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
С�����������һ�ζ��º�ңң��������һ������ɽ�ȣ�ǰ
����µ�Ҳ��ʼƽ̹������ʱʱ����������ɽ�ȴ���������������

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanpo1",
  "north" : __DIR__"caodi",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}



