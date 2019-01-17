// Room: /d/xingxiu/xxh3.c
// Jay 3/18/96

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里通向星宿海的深处。
LONG
        );
        set("objects", ([
                __DIR__"npc/gushou"  : 1,
	]) );

        set("exits", ([
             "southwest" : __DIR__"xxh2",
             "northwest" : __DIR__"xxh5",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-110);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",70);
	set("coor/z",0);
	setup();
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
