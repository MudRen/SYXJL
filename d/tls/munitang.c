inherit ROOM;

void create()
{
        set("short", "牟尼堂");
        set("long",@LONG
这是高僧们的静修之处。整堂全以松木制成，板门木柱，木料均不去
皮，天然质朴，和一路行来金碧辉煌的殿堂截然不同。西首一个和尚
面朝里壁一动不动。
LONG
        );
        set("exits", ([
		"east" : __DIR__"banruotai",
		]));
        set("objects",([
		__DIR__"npc/kurong" : 1,
        ]));
        set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",-130);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
