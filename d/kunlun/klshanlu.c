// klshanlu.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "����ɽ´");
                  set("long",@long
��������ɽ��ѩɽ���࣬���Ӵ�����Զ�����أ���������Ʋʼ����ɫ��
����ÿ�괺���Ժ󣬱�ѩ�ڻ������һ�ɹ��峺Ϫ�������볤�����ƺӡ�
long);
                 set("exits",([
                                "northup" : __DIR__"shanmen",
                                "east" : __DIR__"shankou",
]));
set("outdoors", "����");
set("coor/x",-180);
	set("coor/y",30);
	set("coor/z",20);
	set("coor/x",-180);
	set("coor/y",30);
	set("coor/z",20);
	set("coor/x",-180);
	set("coor/y",30);
	set("coor/z",20);
	set("coor/x",-180);
	set("coor/y",30);
	set("coor/z",20);
	setup();
replace_program(ROOM);
}

