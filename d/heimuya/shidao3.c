inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����У��м����һ����Լ��ߵ�ʯ��������ʯ��
��ǽ��һ·�϶������½�ͽģ�����������߶�����������·
�˶����ܼ��ӡ�
LONG
        );
        set("no_clean_up", 0);
        set("outdoors", "wudang");
        set("exits", ([ /* sizeof() == 2 */
		"east" : "/d/quanzhou/nanmen",
		"north" : __DIR__"shidao",
		"southeast" : "/d/huanhua/xiaoqiao",
		"northwest" : __DIR__"road1",
  
]));

        set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
