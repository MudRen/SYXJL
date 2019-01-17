// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ��Ͼ�
��������ݡ��Ա��ƺ���һ�����š�
LONG
	);

        set("no_fight", "1");
	set("no_study", 1);
        set("no_yun", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

        set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
                    "/d/city/npc/jinyong" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
//		"up" : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "����", "southeast");
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	//replace_program(ROOM);
}

void init()
{
   object me;
    me=this_player();
me->set("startroom",base_name(environment(me)));
    return;
}