//room: houmen.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",
       "���Ǹ�ɽׯ�ĺ��š������нݾ�����ͨ�����޺���\n"
	);
	set("exits",([
		"north" : "/d/xingxiu/xxh1",
		"south" : __DIR__"tuyuan",
	]));
        set("objects", ([
            __DIR__"npc/menwei" : 1 ,
       ]));
	set("outdoors", "baituo");
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
}

int valid_leave(object me, string dir)
{

	if (  (dir == "south")
	   && ((int)me->query("shen") > 300)
	   && objectp(present("men wei", environment(me)))) 
	 return notify_fail
		("��������һ���������������������һ���Ͷ��ģ������\n");
	return ::valid_leave(me, dir);
}