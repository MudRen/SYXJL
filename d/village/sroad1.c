// Room: /d/village/sroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ�����һ����ʯ·������ͨ����ӵ����ģ�
���Ͼ��ǳ����·�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad2",
  "south" : __DIR__"sexit",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");
        set("objects", ([
		__DIR__"npc/girl": 1,
		__DIR__"npc/boy": 1 ]),
 );

        set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


