// /d/xingxiu/beijiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "����С��");
        set("long", @LONG
������һ��ά�����۾ӵ�С����������������ʮ�����֡�ֻ��
����˵�Ļ����������������м�С���̣������������У������ھ���ʲô
�����������м�Ժ�䣬Ժ�ſ��пô�����
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"store",
        "east" : __DIR__"house",
        "northwest" : __DIR__"saimachang",
        "southeast" : __DIR__"shanjiao",
]));
        set("objects", ([
                __DIR__"npc/woman": 2 ]) );
        set("no_clean_up", 0);
        set("outdoors", "����");

        set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


