// Room: shulin12.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬټ������֣���ľ���죬���Ʊ��ա����������ʧ�˷���
��֪�������Լ����ںδ������в�ʱ����Ұ�޹���ĵͺ��Х��,���㲻
��ë���Ȼ��ֻ������뿪��

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shulin11",
  "west" : __DIR__"shulin11",
  "south" : __DIR__"shulin6",
  "east" : __DIR__"shulin",
]));
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/huo-chan" : 1,
]));
        set("no_clean_up", 0);

        set("coor/x",-170);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-170);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-170);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-170);
	set("coor/y",50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

