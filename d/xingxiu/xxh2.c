// xxh2.c
// by QingP

#include <room.h>
#include <ansi.h>

inherit ROOM;

int do_stop(object);

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
������������ͨ�����޺�������������������ܶ桪�����¶���������
���ʯ���ϵĿ��Ÿ�����(duilian)��
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

"		������		������\n"
"		������		������\n"
"		��"HIW"��"NOR"��		��"HIW"��"NOR"��\n"
"		��"HIW"��"NOR"��		��"HIW"��"NOR"��\n"
"		��"HIW"��"NOR"��		��"HIW"��"NOR"��\n"
"		��"HIW"��"NOR"��		��"HIW"��"NOR"��\n"
"		��"HIW"��"NOR"��		��"HIW"��"NOR"��\n"
"		������		������\n"
"		������		������\n\n"

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

        if ((!myfam || myfam["family_name"] != "������") && dir != "north" &&
                (present("chuchen zi", environment(me)))) {
                say("�����Ӷ�"+me->name()+"�ȵ����㲻�������ɵ��ӣ�����Դ�ү�ҵĸ��ȾͿ������\n");
                return notify_fail("�����Ӻȵ����㲻�������ɵ��ӣ�����Դ�ү�ҵĸ��ȾͿ������\n");
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
		return notify_fail("Ѳ��ʱ�������Ķ��⣿������������ô�죿��\n");
	else return ::valid_leave(me, dir);
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
