// room: /d/xingxiu/xxh6
// Jay 5/13/96

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������޺���������ʯͷ�̳ɵ�һ��С������Χ�����������������һ
��˵����������ζ��·���и�ʯ����
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
		return notify_fail("Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");

	if (dir =="enter" ) {
	if (present("caihua zi", environment(me))) {
            if (!myfam || myfam["family_name"] != "������") 
		return notify_fail("�ɻ��ӵ�ס���㣺�ҵ�С椿ɲ��Ǹ�����а�ɵ���׼���ģ�\n");
            if  (me->query("gender")=="����") 
                return notify_fail("�ɻ��ӵ�ס���㣬һ����Ц������С��廹����椣�����Ц�ˡ�\n");
            if (!(int)this_player()->query_temp("marks/��"))
                return notify_fail("�ɻ��ӵ�ס���㣺ι�����ܸ���˼��˼�ɣ�\n");
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
                tell_object(ob,"Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");
                return 1;
                }

        return 0;
}
