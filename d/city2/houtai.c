
inherit ROOM;

void create()
{
	set("short", "ϷԺ��̨");
	set("long", @LONG
������ϷԺ��̨������Ϸ�����ڻ�ױ���ӱ��߿�����̨��
LONG
	);
        set("outdoors", "city2");


	set("exits", ([
  		"west" : "/d/city2/xiyuan",
  		"northup" : "/d/city2/stage",
	]));
        set("objects", ([
                "/d/city2/npc/xizi" : 2,
        ]));
	set("coor/x",-50);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
