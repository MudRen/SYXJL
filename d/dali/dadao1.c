inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。这条大道通向边域名山--苍山，
翻过苍山就是南昭大理国了。
LONG
        );
        set("outdoors", "dali");

        set("exits", ([
                "east" : "/d/wudang/wdroad1",
                "southup" : __DIR__"cangshan",
                "north" :"/d/shashou/enterance",
                
        ]));

        set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
