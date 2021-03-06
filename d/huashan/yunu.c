// yunu.c

inherit ROOM;

void create()
{
	set("short", "玉女峰");
	set("long", @LONG
这里是华山的中峰，玉女峰。玉女峰地势略为平缓，不似其它四峰般
险峻，江湖上赫赫有名的华山剑派就在此处。西边有所小小的庙宇，那就
是玉女祠了。东北面稀稀落落有十几间房子，是华山派的地方，闲杂游客
最好别往那里去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"westdown" : __DIR__"zhenyue",
		"west" : __DIR__"yunuci",
		"south" : __DIR__"shanlu",
		"north" : __DIR__"square",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
        set("outdoors", "华山");

	set("objects", ([ 
		__DIR__"npc/lingshan" : 1,
	]));

	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",90);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}
