//room: changl7.c
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
      "east" : __DIR__"changl15",
      "west" : __DIR__"changl6",
     ]));

 set("coor/x",-140);
	set("coor/y",110);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}