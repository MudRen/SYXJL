//room: changl9.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ������
LONG
     );

  set("exits",([
      "east" : __DIR__"changl12",
      "west" : __DIR__"changl11",
      "south" : __DIR__"changl5",
     ]));

 set("coor/x",-150);
	set("coor/y",130);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}