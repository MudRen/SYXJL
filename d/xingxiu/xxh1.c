// xxh1.c
// by QingP

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
����ʯ����һ���ѷ�ͨ��һ��ɽ����������һ���ݾ���ͨ������ɽ��
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
		return notify_fail("Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");
	
	if (dir != "north" && dir != "westup")
		return ::valid_leave(me, dir);
        else {
        	if (objectp(present("zhaixing zi", environment(me)))&& living(present("zhaixing zi", environment(me)))) {
	        	if ((me->query("shen") > 100))
        		return notify_fail(
"��λ" + RANK_D->query_respect(me) + "���ߣ����޺��������й�֮�أ���������ȥ��\n");
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
                tell_object(ob,"Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");
                return 1;
                }

        return 0;
}
