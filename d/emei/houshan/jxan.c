inherit ROOM;

void create()
{
	set("short", "静修庵");
	set("long", @LONG
这里是静修庵，是灭绝师太静修的地方。这儿人迹罕至是静修的好地
方。在一片松林中，露出一扇小门，进去就看见了一个仙风道骨的老师太，
她就是峨嵋派的掌门----灭绝师太，旁边是一个扶持她的姑娘。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shandao3",
]));            

        set("objects", ([
            __DIR__"npc/miejue" : 1, 
            __DIR__"npc/fblin" : 1,
            ]));

	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
