inherit ROOM;

void create()
{
        set("short", "雨花院");
        set("long",@LONG
相传当年佛祖降临天龙寺传法时，漫天遍洒雨花石。后人以石建
院，即成此间玉花院。
LONG
        );
        set("exits", ([
 //               "west" : __DIR__"fanting",
		"south" : __DIR__"doumugong",
                "east" : __DIR__"bingqifang",
                "northdown" : __DIR__"xuanya",  
	]));
	set("objects",([
		__DIR__"npc/gui-xiang" : 1,
	]));

        set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}


int valid_leave(object me,string dir)
{
        if(dir=="west" && (!me->query("family") 
                || me->query("family")["family_name"]!="天龙寺"))
                return notify_fail("路中间竖着一个“石碑”，上面写到：非天龙寺弟子，请勿进入。\n");
        return ::valid_leave(me,dir);
}

