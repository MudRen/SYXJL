#include <ansi.h>

#include <room.h>

inherit ROOM;

void create()

{

         set("short","木桥");

         set ("long",@long

这是通往湖中小亭的木桥，从这望去湖面碧波荡漾，景色宜人。木桥的

扶手上雕刻着一尊尊小木头狮子，让人爱不释手。木桥往西面走能够看

到一座湖中小亭。

long);

         set("outdoors","mr");

         set("exits",([

             "east" : __DIR__"houyuan1",

             "west" : __DIR__"bishuiting",

]));

         setup();

         replace_program(ROOM);

}

