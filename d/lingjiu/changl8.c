//room: changl8.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ����������ͨ�������
LONG
    );

  set("exits",([
      "west" : __DIR__"changl15",
      "east" : __DIR__"changl4",
     ]));

 set("coor/x",-120);
	set("coor/y",110);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}