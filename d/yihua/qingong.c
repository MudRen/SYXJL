// ROOM : qinong.c
inherit ROOM;
void create()
{
  set("short","�����޹�");
  set("long",@LONG
���ǹ�����Ϣ�ĵط���ֻ��һ��������, ò���绨��Ů��վ����
������,�������书���,������ص��ƻ�����������ǰ��Ϊ����������
�������ǳ������ˣ��������������ò�Ҫ�ӽ�����
LONG
    );
  set("exits",([
      "north" : __DIR__"changlang",
      "south" : __DIR__"woshi",
     ]));
  set("objects",([
		__DIR__"npc/gongzhu" : 1,
     ]));
 setup();
 replace_program(ROOM);
}
