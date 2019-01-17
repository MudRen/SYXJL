inherit ROOM;

void create()
{
	set("short", "太子坪");
	set("long", @LONG
这里是千佛庵西边的太子坪，是峨嵋派年幼的弟子们练功的场所。
在这片开阔的草坪上散布着几个年幼的还没有出家的小女孩。				
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"xiaodao",
]));
	set("objects",([
           __DIR__"npc/girl2" : 3, 
           __DIR__"npc/nigu1" : 1,
           __DIR__"npc/zhou" : 1,
             ]));    

	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",120);
	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",120);
	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}
