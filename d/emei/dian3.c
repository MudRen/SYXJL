inherit ROOM;

void create()
{
	set("short", "接引殿");
	set("long", @LONG
这里是千佛庵的接引殿，在大殿的后面，是师太们做功课的地方。地上
摆满了蒲团，殿内坐着十几个正在颂经的尼姑，坐在中间的是静心师太。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dian4",
  "south" : __DIR__"dadian",
]));
	set("objects", ([
            __DIR__"npc/jingxin" : 1,
              ]));

        set("no_clean_up", 0);

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
