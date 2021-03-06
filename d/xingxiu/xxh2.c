// xxh2.c
// by QingP

#include <room.h>
#include <ansi.h>

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里左右两厢通向星宿海的深处，北边是星宿派总舵——日月洞。洞口两
侧的石壁上的刻着副对联(duilian)。
LONG
        );
        set("exits", ([
             "north" : __DIR__"riyuedong",
             "south" : __DIR__"xxh1",
             "northeast" : __DIR__"xxh3",
             "northwest" : __DIR__"xxh4",
        ]));

        set("objects", ([
                "/kungfu/class/xingxiu/shihou" : 1,
                __DIR__"npc/dizi"  : 2,
        ]));

	set("valid_startroom",1);

        set("item_desc", ([
                "duilian" : "\n\n"

"		※※※		※※※\n"
"		※※※		※※※\n"
"		※"HIW"星"NOR"※		※"HIW"日"NOR"※\n"
"		※"HIW"宿"NOR"※		※"HIW"月"NOR"※\n"
"		※"HIW"海"NOR"※		※"HIW"洞"NOR"※\n"
"		※"HIW"福"NOR"※		※"HIW"洞"NOR"※\n"
"		※"HIW"地"NOR"※		※"HIW"天"NOR"※\n"
"		※※※		※※※\n"
"		※※※		※※※\n\n"

        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-120);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",60);
	set("coor/z",0);
	setup();
        "/clone/board/xingxiu_b"->foo();

}

/*
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "星宿派") && dir != "north" &&
                (present("chuchen zi", environment(me)))) {
                say("出尘子对"+me->name()+"喝道：你不是星宿派弟子，不想吃大爷我的钢杖就快滚开。\n");
                return notify_fail("出尘子喝道：你不是星宿派弟子，不想吃大爷我的钢杖就快滚开。\n");
        }
        return ::valid_leave(me, dir);
}
*/

void init()
{
	object ob;

	if (interactive(ob = this_player())
	&& ( ob->query("in_xuncha") || ob->query("work_xuncha")) )
	{
		add_action("do_stop","du");
		add_action("do_stop","dazuo");
		add_action("do_stop","study");
		add_action("do_stop","tuna");
		add_action("do_stop","lian");
		add_action("do_stop","practice");
		add_action("do_stop","exercise");
		add_action("do_stop","meditate");
		add_action("do_stop","quit");
	}
}

int valid_leave(object me, string dir)
{
	if ( dir == "north"
	&& (me->query("in_xuncha") || me->query("work_xuncha")) )
		return notify_fail("巡查时怎可三心二意？惊扰了老仙怎么办？！\n");
	else return ::valid_leave(me, dir);
}

int do_stop(object ob)
{
        ob=this_player();
  
        if ( ob->query("in_xuncha") || ob->query("work_xuncha")) {
                tell_object(ob,"巡查时怎可三心二意？惊扰了老仙怎么办？！\n");
                return 1;
                }

        return 0;
}
