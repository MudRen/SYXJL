// xxh5.c
// by QingP

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海的尽头。因为附近有野羊出没，所以星宿派弟子常常在此烤羊肉串
吃。当打不到野羊时，他们就抢山下牧人的羊。你环顾四周，发现南面杂草掩盖
之下似乎有一条小路。
LONG
        );
        set("exits", ([
             "southeast" : __DIR__"xxh3",
             "southwest" : __DIR__"xxh4",
             "south" :     __DIR__"xxh7",
        ]));
        set("objects", ([
                __DIR__"npc/boshou"  : 1,
                __DIR__"obj/yangrouchuan.c" : 2]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-120);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",80);
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
