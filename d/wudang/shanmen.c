// shanmen.c �䵱ɽ��
// by Xiang

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�䵱ɽ��");
        set("long", @LONG
        �����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�ʯ����д�š��䵱ɽ���������֣�ԭ�������
�����������䵱ɽ��
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                "east" : __DIR__"wdroad8",
                "westup" : __DIR__"shijie11",
//                "west" : "/d/mingjiao/westroad1",
        ]));
        set("objects", ([
                __DIR__"npc/guest" : 1,
               __DIR__"npc/zhike" : 1]));
        set("coor/x",-40);
        set("coor/y",-90);
        set("coor/z",0);
        set("coor/x",-40);
        set("coor/y",-90);
        set("coor/z",0);
        set("coor/x",-40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
//      replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("shou") && (dir == "east" || dir == "westup") &&
                objectp(present("zhike daozhang", environment(me))))
        {
        message_vision(CYN"$NͻȻ���뿪ɽ�š�\n"NOR,me);
        message_vision(CYN"֪�͵��������˵Ķ�$N˵����������ʱ��Ҫ���ܡ�����㲻�����ŵĻ��ͷ����ɡ���\n"NOR,me);
        return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

