//room:cao2.c

inherit ROOM;

void create()
{
  set("short","�ݴ�");
  set("long",
      "�������Ҳݴԡ������������֡��������涼�������ߵ���ݣ�\n"
  "�����߳�û��\n"
     );
  set("exits",([
      "west" : __DIR__"cao2",
      "north" :__DIR__"zhulin",
      "east" : __DIR__"cao1",
      "south" : __DIR__"cao1",
     ]));
 set("objects",([
                "/clone/beast/qingshe" : random(2),
                "/clone/beast/jinshe" : random(2),
                "/clone/beast/dushe" : 1,
      ]));
 set("outdoors","baituo");
 set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}




