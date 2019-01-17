inherit ROOM;

void create()
{
        set("short", "伏虎寺");
        set("long", @LONG
丛林茂密，绿荫蔽天之间，一座宏大的殿宇若隐若现，这就是被称为“密
林藏伏虎”的伏虎寺了。此处清幽雅静，景色宜人，尽管殿宇藏在密林之间，
却从来没有积存飘落下来的败叶，屋顶显得干干净净，想来是山风将落叶都吹
走了吧。寺后有座罗峰山，那里就是峨眉十景之一－－－“罗峰翠云”。东面
就是解脱桥了。
LONG
        );

        set("exits", ([
                "eastup" : __DIR__"jietuo",
                "west" : __DIR__"bgsgate",
                "north" : __DIR__"luofeng",
               ]));
        set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}