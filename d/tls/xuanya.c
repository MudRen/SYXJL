// xuanya.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "舍身崖");
	set("long", @LONG
这是一段极窄极险的山崖，四周云雾飞绕，下面就是滚滚的洱水, 雄伟的大理城就在脚下的洱水对岸,
如不小心，一失足掉下去，只怕连骨头都找不到。
LONG
        );
        set("exits", ([ 
	  "southup" : __DIR__"yuhuayuan",
	]));
	
	set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "tianlongsi" );
	set("objects",([
		__DIR__"npc/gui-yan" : 1,
	]));

        set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",20);
	setup();
}

/* void init()
{
        add_action("do_climb", "climb");
        add_action("do_pa", "pa");
}



int do_climb(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message("vision",
				me->name() + "你卷起袖子，小心易易的往下爬。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underhs");
                	message("vision",
				me->name() + "从下面爬了上来来。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("你有啥想不开的,非要这样呢？\n");
	}
}              */
