// Room: tianlongsi/fzlou.c

inherit ROOM;

void create()
{
	set("short", "方丈楼");
	set("long", @LONG
这里的地上整整齐齐的排放着数十个黄布蒲团，北首有一个
红木讲坛，讲坛上放着个竹制的木鱼。东西边各放着一对美轮美
奂的大花瓶，上插檀香数枝，香烟缭绕，氤氲芬芳，室内一片祥
和之气。看来这里是方丈对僧众讲经说法的地方。
LONG
	);

	set("exits", ([
		"up" : __DIR__"fzlou1",
		"east" : __DIR__"shengdian",
	]));

	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}



