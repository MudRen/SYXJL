inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
    set("short",MAG" 爱情边界 "NOR);

set("long",
 MAG"\n如果有一天\n"NOR
 MAG"天与地的爱情有了结局\n\n"NOR
 MAG"我愿化作紫黑色的蝙蝠\n"NOR
 MAG"飞下地狱去找回我的爱人\n\n"NOR

);
set("sleep_room",1);

set("exits",([
 "south" : "/u/bsd/workroom",
]));
  setup();
}
