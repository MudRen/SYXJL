// room: /d/xingxiu/xxh6
// Jay 5/13/96

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "石道");
        set("long", @LONG
这是星宿海边有人用石头铺成的一条小道，周围弥漫着沼泽的瘴气和一
种说不出来的香味。路边有个石洞。
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"xxh4",
            "enter" : __DIR__"xiaoyao",
        ]));
        set("objects", ([ 
            __DIR__"npc/caihua" : 1,
         ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-140);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",70);
	set("coor/z",0);
	setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if ( dir == "enter"
	&& (me->query("in_xuncha") || me->query("work_xuncha")) )
		return notify_fail("巡查时怎可三心二意？惊扰了老仙怎么办？！\n");

	if (dir =="enter" ) {
	if (present("caihua zi", environment(me))) {
            if (!myfam || myfam["family_name"] != "星宿派") 
		return notify_fail("采花子挡住了你：我的小妞可不是给你们邪派弟子准备的！\n");
            if  (me->query("gender")=="无性") 
                return notify_fail("采花子挡住了你，一脸讥笑：您这小身板还想玩妞？别开玩笑了。\n");
            if (!(int)this_player()->query_temp("marks/花"))
                return notify_fail("采花子挡住了你：喂，你总该意思意思吧？\n");
        }
	return 1;
   	}
   return ::valid_leave(me, dir);
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
