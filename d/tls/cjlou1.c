inherit ROOM;

void create()
{
        set("short", "藏经阁二楼");
        set("long", @LONG
中间排列着五排大书架。四周则陈列矮几，以供阅读。几
位老僧手执经卷，正在闭目凝思。
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
                        return notify_fail("本观说道: 武功秘籍只许在藏经阁内研习，不得携带外出 !\n");
                }
        }
        return ::valid_leave(me, dir);
}
