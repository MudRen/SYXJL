// yunu.c

inherit ROOM;

void create()
{
	set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��Ů�������Ϊƽ�������������ķ��
�վ��������Ϻպ������Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�
����Ů���ˡ�������ϡϡ������ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο�
��ñ�������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"westdown" : __DIR__"zhenyue",
		"west" : __DIR__"yunuci",
		"south" : __DIR__"shanlu",
		"north" : __DIR__"square",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
        set("outdoors", "��ɽ");

	set("objects", ([ 
		__DIR__"npc/lingshan" : 1,
	]));

	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}
