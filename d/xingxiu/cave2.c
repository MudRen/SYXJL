// cave2.c

// by QingP



inherit ROOM;



void create()

{

	set("short", "山洞");

	set("long", @LONG

这是一个十分宽敞的山洞，四周石壁上点着数盏昏暗的油灯。几名星宿的弟子正

在练功。你忽然发现地上竟然躺几具肢体僵硬，面目惨白的死尸。

LONG

	);



	set("exits", ([

		"out" : __DIR__"xxh8",

	]));



	set("objects",([

		__DIR__"npc/kuilei" : 4,

	]));

	

	setup();



}