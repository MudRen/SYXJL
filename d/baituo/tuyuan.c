//room: tuyuan.c
inherit ROOM;

void create()
{
  set("short","��Է");
  set("long",
       "���Ǹ��������Է����ֻ����þ����ض����̲ݵ��ϳԲݡ�\n"
   "�����Ǻ��ţ����Ϸ�����԰��\n"
      );
  set("exits",([
      "north" : __DIR__"houmen",
      "southwest" : __DIR__"zhuyuan",
     ]));
  set("outdoors", "baituo");
  set("objects",([
    __DIR__"npc/baitu" : 2,
    ]));
 set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}




