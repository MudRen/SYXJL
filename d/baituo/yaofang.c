//room: /d/btshan/restroom.c
inherit ROOM;

void create()
{
  set("short","ҩ��");
  set("long",
      "�����Ǽ�ҩ������ǽ����һֻ��ҩ���������������ӣ��ϱ߰�������\n"
  "ҩ�õ�ƿƿ�޹ޡ�����һ��ҩƿ(bottle)��ֻװ����ˮ����ҩʦ��λС����\n"
  "���������﷢������֪����ʲô�����������ɵĳ��ȡ�\n"
     );

  set("exits",([
      "north" : __DIR__"changlang",
     ]));

  set("item_desc",([
      "bottle" : "ҩ�������ű�ǩ�����ߵ��ࡻ�������Ʒ������������Ч����ѡ�\n",
      ]));

  set("objects",([
// __DIR__"obj/wan" :1,
    __DIR__"npc/xiaoqing" : 1,
    ]));

 set("coor/x",-140);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",-20);
	set("coor/z",0);
	setup();

 replace_program(ROOM);
}






