#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ɽ�ŵ�");
	set("long", @LONG
�����Ƕ����ɵ�ɽ�ŵ�������ƵĴ��������ɽ��֮�䣬���ѵ�ʯ
�����쵽���ǰ���ٴ��������ɽ�����죬����ڵĹ���������һ������
�ϵ��޺����񡣴���������������ڿ��ش�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanmen",
  "northup" : __DIR__"shijie2",
]));
	set("no_clean_up", 0); 
        set("objects",([
             __DIR__"npc/wenxin" : 1,
             __DIR__"npc/wenyue" : 1,  
             ]));
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",60);
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",60);
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",60);
	setup();
}
                                     

int valid_leave(object me, string dir)
{
        if( dir == "south" && (string)me->query("id") == "xunshan dizi")
                return notify_fail("������ɽ!\n");
        else if (objectp(present("wenxin shitai", environment(me)))
                  ||objectp(present("wenyue shitai", environment(me)))) 
              {if( dir == "northup" && (string)me->query("family/family_name") != "������")
                return notify_fail(RED"ʦ̫��ס�����ȥ·����\n"NOR);              
              else if(dir == "south" && (int)me->query("xiashan") == 1 )
                return notify_fail(GRN"û�о������ŵ�ͬ�⣬������ɽ��\n"NOR);  
             }
        return ::valid_leave(me, dir);
}
