//room:cao1.c
inherit ROOM;

void create()
{
  set("short","�ݴ�");
  set("long",
      "�������Ҳݴԡ��������ȹ�����С���š�\n"
  "�������涼�������ߵ���ݣ������߳�û��\n"
    );
  set("exits",([
        "west" : __DIR__"cao1",
      "north" : __DIR__"cao2",
	"east" : __DIR__"ximen",
        "south" : __DIR__"cao1",
     ]));
 set("objects",([
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));
 set("outdoors","baituo");
 set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}




