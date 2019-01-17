inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
这里是千佛庵的后殿，在接引殿的后面，是师太们做功课的地方。地上
摆满了蒲团，殿内坐着十几个正在颂经的尼姑，坐在中间的是静和师太。再
往北就是神灯阁了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shendeng",
  "south" : __DIR__"dian3",
]));
	
        set("objects", ([
            __DIR__"npc/jinghe" : 1,
              ]));

	set("coor/x",-40);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",60);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
