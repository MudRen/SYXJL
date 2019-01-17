inherit ROOM;
void create()
{
        set("short", "关庙");
        set("long", @LONG
关羽关云长大概是荆州百姓最为崇敬的人物了，所以修葺的关庙几乎是
本地最大的建筑，进去就可以看到关二爷的神像，左边是手持青龙郾月刀的
周仓，右边奉的是捧印的关平；前来烧香企福的人也不少，四季香火不绝，
门前的广场是有许多艺人在这里表演杂耍，魔术之类的表演挣生活，热闹非
凡。
LONG
        );        
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"nanmendajie2",
        ]));
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");
        set("no_study", "1");
        set("no_kill",1);
        set("no_yun",1);
        set("no_beg",1);
        set("no_hit",1);
        set("no_array",1);
        set("no_clean_up", 0);
        set("objects", ([
                "/d/city/obj/box" : 1,
                ]));
        setup();
        replace_program(ROOM);
}

