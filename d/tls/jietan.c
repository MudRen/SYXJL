inherit ROOM;

void create()
{
        set("short", "戒坛殿");
        set("long",@LONG
这是僧人们点化顽徒的地方。不少江湖豪客由于厌倦了打打杀杀
的日子，来到此处落发为僧，叛依佛门。墙上一幅佛祖神像，两边各
有一条幅，上书：放下屠刀，立地成佛。
LONG
        );
        set("exits", ([
                "west" : __DIR__"shijie2",
		"north" : __DIR__"huangtianmen",
	]));
	set("objects",([
		__DIR__"npc/xing-feng" : 1,
                __DIR__"npc/xiaoshami" : 2,
	]));

        set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
