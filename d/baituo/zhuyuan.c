//zhuyuan.c
inherit ROOM;

void create()
{
  set("short","��԰");
  set("long",
      "������һ���ľ�����԰���߸ߵ͵͵Ĵ��������װ���\n"
  "�������¡��������Ǻ�Ժ���������и���Է���ϱ��ǻ�԰��\n"
     );
  set("exits",([
      "northeast" : __DIR__"tuyuan",
      "northwest" : __DIR__"houyuan",
      "south" : __DIR__"huayuan",
     ]));
  set("outdoors", "baituo");
  set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}





