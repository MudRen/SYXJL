//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "���");
        set("long",
		"�����������Ŷ�����ĵط�����Χ����Ķѷ�������õ�ԭ�ϣ�һ������\n"
		"С����������һ�����������������ϸ���ж��š����������˹�������æ����\n"
		"���е��飬����һ��������㺩����һЦ���������ֺ��ˡ�\n"
        );
        set("exits", ([
                "east" : "/d/xueshan/shenghu",
        ]));

	set("objects",([__DIR__"npc/shigun" : 1,]));

        set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
