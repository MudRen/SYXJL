inherit ROOM;

void create()
{
        set("short", "无无境");
        set("long",@LONG
一片水池静卧眼前，一座精雕木桥横跨其上，与其倒影恰成一圆，映
着空灵的水面，使你心中似有所动。仿佛体会到了众生之源，万物之本的
真谛。
LONG
        );
	set("outdoors","tianlongsi");
        set("exits", ([
		"southdown": __DIR__"yaotai",
		"west" : __DIR__"doumugong",
	  ]));
	set("objects",([
		__DIR__"npc/xing-yu" : 1,
	]));

        set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
