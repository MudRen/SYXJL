//cave1.c
inherit ROOM;

void create()
{
  set("short","�Ҷ���");
  set("long",
        "�������Ҷ��ڲ��������������Ž�׵�����ʯ��\n"
      );
  set("exits",([
      "south" : __DIR__"cave",
     ]));
// set("objects",([
//      ]));
 set("coor/x",-160);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-160);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-160);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-160);
	set("coor/y",30);
	set("coor/z",10);
	setup();
 replace_program(ROOM);
}




