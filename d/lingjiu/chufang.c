//ROOM: chufang.c
inherit ROOM;

void create()
{
  set("short","ź���");
  set("long",@LONG
���Ǽ������ Ũ���ķ�����ζһ�����������ı��ӣ� ��·�����
�����������������������ܲ�֪��Դ�� ԭ������Ķ������֡�
LONG
     );
  set("exits",([
      "east" : __DIR__"changl6",
     ]));
  set("objects",([
    __DIR__"npc/lisao" : 1,
    __DIR__"obj/suanmei" : 2,
    __DIR__"obj/gao" : 2,  
  ]));
 set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}