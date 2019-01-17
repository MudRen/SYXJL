// xxh8.c
// by QingP

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "С��");
        set("long", @LONG
�������޺���һ�����ص�С���������Ӳݴ�������Χ�����������������ֻ����
ԼԼ��������µ�һС��·������֮�У����ƺ�����ǰ����һ�����ڡ�
LONG
        );
        set("exits", ([ 
            "north" : __DIR__"xxh7",
            "enter" : __DIR__"cave2",
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
}

int valid_leave(object me, string dir)
{
	if ( dir == "enter"
	&& (me->query("in_xuncha") || me->query("work_xuncha")) )
		return notify_fail("Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");
	else return ::valid_leave(me, dir);
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
                tell_object(ob,"Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");
                return 1;
                }

        return 0;
}
