inherit ROOM;

void create()
{
        set("short", "云海");
        set("long", @LONG
  这里的云雾更深了！放眼望去，灰蒙蒙一片.你只觉心头郁闷，根本就弄
不清自己身在何处。四周好象都有出路，但就是看不太清楚。
LONG   );
  
        setup();
        
}

void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"yunhai1"+random(3));
  me->set("exits/west",__DIR__"yunhai1"+random(3));
  me->set("exits/north",__DIR__"yhchkou");
  me->set("exits/south",__DIR__"yunhai0");
}

