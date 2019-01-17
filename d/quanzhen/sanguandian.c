// sanguandian.c 三官殿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "三官殿");
	set("long", @LONG
这里是三官殿，供奉着中国传说中的天官（尧）、地官（舜）、人官（禹）。
有“天官赐福，地官赦罪，水官解厄”之说。殿前有株山茶花，树干粗大古
老，没人知道是何人何年种的。 
LONG
	);
      

	set("exits", ([
		"southwest" : __DIR__"donglang5",
//		"north" : __DIR__"",
       ]));
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}



