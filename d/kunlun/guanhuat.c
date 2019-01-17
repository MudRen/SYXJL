// Room: /d/kunlun/guanhuat.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "观花亭");
	set("long", @LONG
这是一个小巧的亭子, 供赏花时休息之用。亭中石桌石凳俱全，石桌上还 
摆放着几盘点心。早年间, 铁琴先生也曾在此与夫人对弈, 但已经是久远的往 
事了。亭外是九曲廊，弯弯曲曲的不知道通向何方，南面是小练功房。 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"jiuqulang3.c",
  "north" : __DIR__"jingsish",
  "northwest" : __DIR__"jiuqulang1.c",
  "south" : __DIR__"xlgf_1",
]));

	setup();
	replace_program(ROOM);
}
