inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
    set("short",MAG" ����߽� "NOR);

set("long",
 MAG"\n�����һ��\n"NOR
 MAG"����صİ������˽��\n\n"NOR
 MAG"��Ը�����Ϻ�ɫ������\n"NOR
 MAG"���µ���ȥ�һ��ҵİ���\n\n"NOR

);
set("sleep_room",1);

set("exits",([
 "south" : "/u/bsd/workroom",
]));
  setup();
}
