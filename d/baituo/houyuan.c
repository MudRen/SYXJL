//room: huayuan.c
inherit ROOM;

void create()
{
  set("short","��Ժ");
  set("long",
       "����Ƨ���ĺ�Ժ��ס�š�ŷ���ˡ��������衺���衻��\n"
   "���������Ѹߣ����Ѿ����ɻ��ˣ������ﾲ����\n"
      );
  set("exits",([
      "southeast" : __DIR__"zhuyuan",
     ]));
  set("outdoors", "baituo");
  set("objects",([
    __DIR__"npc/zhangma" : 1,
    ]));
 set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",30);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}






