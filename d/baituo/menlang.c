//room: menlang.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "���Ǹ����ȣ����ȵķ����Ϲ���һ������Сͭ�壬\n"
  "������з�����ද����������\n"
      );
  set("exits",([
      "north" : __DIR__"huayuan",
      "south" : __DIR__"liangong",
     ]));
  set("objects",([
    __DIR__"npc/guanjia" : 1,
    ]));
 set("outdoors","baituo");
 set("coor/x",-130);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",0);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}






