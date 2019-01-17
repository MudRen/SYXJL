inherit ROOM;

void create()
{
	set("short", "雷动坪");
	set("long", @LONG
这里是千佛庵西边的雷动坪，是峨嵋派年幼的弟子们练功的场所。在
这片开阔的草坪上散布着几个年幼的出家的小尼姑。				
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"xiaodao",
]));
	set("objects", ([
          __DIR__"npc/girl3" : 3,  
          __DIR__"npc/nigu2" : 3,
             ]));

	set("coor/x",-90);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",30);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
