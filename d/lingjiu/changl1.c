//room: changl1.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ������һ������Ӷ���
������
LONG
     );

  set("exits",([
      "west" : __DIR__"changl5",
      "east" : __DIR__"huayuan",
     ]));

 set("coor/x",-140);
	set("coor/y",120);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}