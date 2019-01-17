// Room: /d/kunlun/qianting.c 

#include <ansi.h> 
inherit ROOM; 
 
void create() 
{ 
        set("short", "ǰ��");
        set("long", @LONG
�߽�����, ��������ʥ��ǰ�������м򵥵ط��ż�������, һ�����;��� 
��������Ϣ, �ȴ����ͻ����������ͨ�������Ҳ�ʱ��������֮��, �������� 
���������ɹ��⽫���䳡����ǰ��֮��, һ������������ĵ�����ѧ�ľ����� 
�Ź��򣬲��¹ۿ������������Եõ����ڶ�, ��׳�������ơ� 
LONG
        );
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kl-dizi3.c" : 2,
  __DIR__"npc/banshuxian.c" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lianwu2",
  "west" : __DIR__"lianwu1",
  "north" : __DIR__"zhongt",
  "out" : __DIR__"damen",
]));

        setup();
//       replace_program(ROOM);
        "/clone/board/kunlun_b"->foo();
} 

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "������") && dir == "north" &&
                objectp(present("ban shuxian", environment(me))))
    return notify_fail(HIW"\n����浺ȵ����㲻�����ص��ӣ�Ҫ��������������! \n"NOR);
                
        return ::valid_leave(me, dir);
}

