inherit ROOM;

void create()
{
	set("short", "神灯阁");
	set("long", @LONG
这里是千佛庵的神灯阁，是师太们和香客们休息的地方。一群香客正
坐在那聊天，这儿有免费的茶水。往北就出了神灯阁，进入一个大院子。				
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dian4",
  "north" : __DIR__"houyuan",
  "west" : __DIR__"beilang",
  "east" : __DIR__"beilang1",
]));
	set("resource/water", 1);

	set("coor/x",-40);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
