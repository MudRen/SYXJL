// xxh1.c
// by QingP

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
东面石壁上一道裂缝通到一个山洞。南面有一条捷径可通往白驼山。
LONG
        );
        set("exits", ([
             "north" : __DIR__"xxh2",
             "southup" : __DIR__"tianroad2",
             "south" : "/d/baituo/houmen" ,
             "westup" : __DIR__"tianroad3",
	]));

        set("objects", ([
                "/kungfu/class/xingxiu/zhaixing" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "westup" || dir =="south" || dir =="southup")
	&& (me->query("in_xuncha") || me->query("work_xuncha")) )
		return notify_fail("巡查时怎可三心二意？惊扰了老仙怎么办？！\n");
	
	if (dir != "north" && dir != "westup")
		return ::valid_leave(me, dir);
        else {
        	if (objectp(present("zhaixing zi", environment(me)))&& living(present("zhaixing zi", environment(me)))) {
	        	if ((me->query("shen") > 100))
        		return notify_fail(
"这位" + RANK_D->query_respect(me) + "休走！星宿海岂是你闲逛之地，快速速离去！\n");
		}
	return ::valid_leave(me, dir);
	}
}

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

int do_stop(object ob)
{
        ob=this_player();
  
        if ( ob->query("in_xuncha") || ob->query("work_xuncha")) {
                tell_object(ob,"巡查时怎可三心二意？惊扰了老仙怎么办？！\n");
                return 1;
                }

        return 0;
}
