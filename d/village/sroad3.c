// Room: /d/village/sroad3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·��������һ
���ںڰ�����С���ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sroad4",
  "south" : __DIR__"sroad2",
  "west"  : __DIR__"alley1",
]));
	set("objects", ([
		__DIR__"npc/kid" : 4,
	]));

        set("no_clean_up", 0);
        set("outdoors", "xxx");

        set("coor/x",-10);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


