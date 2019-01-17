// Room: /d/tianlongsi/zhonglou2.c



inherit ROOM;









void create()

{

	set("short", "钟楼一层");

	set("long", @LONG

每个楼层上都铺设了结实的木楼板，八角形的墙身上则开

了四扇大窗。从窗孔看，墙体也是极为厚实。从这里往外眺望，

可以看到围绕塔周的小园以及北边的竹林，随风飘来阵阵竹叶

的清香。

LONG

	);



	set("exits", ([

		"up" : __DIR__"zhonglou2",

		"out" : __DIR__"zhonglou",

	]));



	setup();

	replace_program(ROOM);

}







