// guangchang.c �㳡
// by Arnzh

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
����һ��㳡���С�Ĵ�ʯ��������ƽ�ֹ⣬��Ȼ��������������
Ҳ���������Ƴɡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie7",
		"north" : __DIR__"tyroadct",
		]));
	set("objects", ([
		CLASS_D("wudang") + "/yu" : 1]));

	set("coor/x",-60);
	set("coor/y",90);
	set("coor/z",190);
	set("coor/x",-60);
	set("coor/y",90);
	set("coor/z",190);
	set("coor/x",-60);
	set("coor/y",90);
	set("coor/z",190);
	setup();
	
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�䵱��") && dir == "north" &&
		objectp(present("yu lianzhou", environment(me))))
	   return notify_fail("��������ס��˵���������Ǳ����صأ��㲻���䵱���ӣ�\n��ȥ���в��㣬��������\n");
		
        return ::valid_leave(me, dir);
}

