inherit ROOM;

void create()
{
        set("short", "斗母宫");
        set("long",@LONG
这是给进香客们休息的地方。四周围放着一溜檀木红漆椅。几个进香
客坐在上面休息。向南是可以看见僧人们休息的清心阁，北面传来阵阵砰
砰声，向西就要到天龙寺的后殿重地了。
LONG
        );
        set("exits", ([
                "south" : __DIR__"qingxinge",
                "east" : __DIR__"wuwujing",
                "north" : __DIR__"yuhuayuan",
                "west" : __DIR__"sanwugong",
        ]));
        set("objects",([
                __DIR__"npc/guest" : 3,
        ]));
        set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
