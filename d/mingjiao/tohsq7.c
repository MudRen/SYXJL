//TOHSQ7.C

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工
凿出一格格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。
瀑布在脚下奔腾而过，山脚下汇成一个深潭。
LONG
	);

	set("exits", ([
		"north" : __DIR__"hsqmen",
		"south" : __DIR__"tohsq6",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",50);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}