inherit ROOM;

void create()
{
	set("short", "云海出口");
	set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都是云雾，根本就
弄不清自己身在何出。在雾中隐隐约约有一条小道通向前方，前面就是金
顶了！
LONG  );          
        set("exits",([
          "north": __DIR__"jinding",
              "south": __DIR__"yunhai12",
               ]));

	setup();  
	replace_program(ROOM);
}
