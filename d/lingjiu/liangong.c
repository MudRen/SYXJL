//room: liangong.c

inherit ROOM;

void create()
{
  set("short","Ϸ���");
  set("long",@LONG
���������չ����������ĵط����м�������Ů������ר�����µ�����
���м����ֳ���,�ڻ������,���鶯�����紩������һ�㣬�㲻����
�����ۣ�����������ڵ��ϵ������Ͽ���������
LONG
      );

  set("exits",([
      "west" : __DIR__"changl4",
     ]));

 set("objects",([
          "/d/shaolin/npc/mu-ren2" : 2 ]));
  set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",70);
	setup();
 replace_program(ROOM);
}