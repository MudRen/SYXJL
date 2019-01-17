inherit ROOM;

void create()
{
        set("short", "般若台");
        set("long",@LONG
这是个普通的石台，相传当年佛祖曾降临此台传法。再往南去就是本
寺重地——牟尼堂。江湖中传言天龙寺的镇寺之宝——六脉神剑谱就藏于
此中，但你千万不要打什么主意。
LONG
        );
        set("exits", ([
                "west" : __DIR__"munitang",
		"northdown" : __DIR__"doushuai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
        ]));
        set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
