// ROOM : biguan.c
inherit ROOM;
void create()
{
  set("short","�չ���");
  set("long",@LONG
������ɽͯ�ѱչ������ĵط���ֻ��һ����Ľ�С, ò�紦�ӵ�ʮ��
�����Ů����ϥ�������������������µ���ɽͯ�ѡ�������������״���
�ӣ�ǧ��Ҫ���״����
LONG
    );
  set("sleep_room", 1);   
  set("exits",([
      "south" : __DIR__"men3",
     ]));
  set("objects",([
                "/kungfu/class/lingjiu/tonglao" : 1,
     ]));
 set("coor/x",-130);
        set("coor/y",160);
        set("coor/z",70);
        setup();
 replace_program(ROOM);
}

