inherit ROOM;

void create()
{
        set("short", "�ؾ����¥");
        set("long", @LONG
�м����������Ŵ���ܡ���������а������Թ��Ķ�����
λ��ɮ��ִ�������ڱ�Ŀ��˼��
LONG
        );

        set("exits", ([
                "down" : __DIR__"cjlou",
        ]));

        set("objects",([ 
           __DIR__"npc/benguan":1,                       ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if ( present("ben guan", environment(me)) )
        if ( present("tianlongsi wuji", me)
        ||   objectp(ob = present("corpse", me)) && present("tianlongsi wuji", ob) )
        {
                if (dir == "down" )
                {
                        return notify_fail("����˵��: �书�ؼ�ֻ���ڲؾ�������ϰ������Я����� !\n");
                }
        }
        return ::valid_leave(me, dir);
}
