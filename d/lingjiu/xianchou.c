//room: xianchou.c
inherit ROOM;

void create()
{
  set("short","�ɳ���");
  set("long",@LONG
����Ϳ쵽��翷�����ˣ�Խ�����ߣ�ɽ��Խ�ߣ�����������ߵİ�
��������Ũ������������ɽ��·������ɽ��û�߼�����������ǰ����һ��
ʯ�������顺�ɳ��š��������֣�������ɽ֮�����ɡ�
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "eastup" : __DIR__"dadao1",
      "southdown" : __DIR__"jian",
     ]));

 set("coor/x",-140);
	set("coor/y",70);
	set("coor/z",60);
	setup();
 replace_program(ROOM);
}