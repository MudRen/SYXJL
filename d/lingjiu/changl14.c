//room: changl14.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ���������ȶ���ͨ����ױ
¥��
LONG
  );

  set("exits",([
      "east" : __DIR__"daban",
      "west" : __DIR__"changl10",
      ]));

 set("coor/x",-100);
	set("coor/y",130);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}