// xuanya.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�������ǹ����Ķ�ˮ, ��ΰ�Ĵ���Ǿ��ڽ��µĶ�ˮ�԰�,
�粻С�ģ�һʧ�����ȥ��ֻ������ͷ���Ҳ�����
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
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "��������ӣ�С�����׵���������\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underhs");
                	message("vision",
				me->name() + "������������������\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("����ɶ�벻����,��Ҫ�����أ�\n");
	}
}              */
