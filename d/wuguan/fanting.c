// Room: /d/wuguan/fanting.c
// Date: 99/05/30 by Byt

inherit ROOM;
int valid_leave(object me, string dir);
void create()
{
        set("short", "����");
        set("long", @LONG
������������ò͵ĵط������ﲼ�úܼ�, ֻ���ż�������
��������һ������س��š�һ�������ڲ�ͣ��æµ�ţ����������
Ҫʳ���ˮ��
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"shibanlu3",
        ]));
        set("objects", ([
                __DIR__"npc/chuzi" : 1,
        ]));        
        setup();
}


int valid_leave(object me, string dir)
{

        if (  (dir == "east")
           && ( present("rice", this_player())
                || present("baozi", this_player())
                || present("yuebing", this_player())
                || present("tea", this_player()) )
           && objectp(present("pang chuzi", environment(me))) )
        return notify_fail
                ("�ֳ��Ӻ���һ�����Ա������˻�Ҫ����ѽ��\n");
        return ::valid_leave(me, dir);
}
