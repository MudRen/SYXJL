inherit ROOM;

void create()
{
        set("short", "清都瑶台");
        set("long",@LONG
这是出入前后寺的必经之路。往南望去，可见后寺中亭台楼阁规模宏
大，构筑精丽，宅地连云，其气势之盛更胜于五台，普陀等诸处佛门胜地
的名山大寺。
LONG
        );
        set("outdoors","tianlongsi");
        set("exits", ([
                "westup": __DIR__"wuwujing", 
                "eastdown": __DIR__"shijie1", 
                "north":__DIR__"zhonglou",
                "south":__DIR__"gulou",                         
        ]));
        set("objects",([
                __DIR__"npc/xing-yun" : 1,
                __DIR__"npc/xiaoshami" : 1,
        ]));

        set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

