inherit ROOM;

void create()
{
        set("short", "封阐台");
    set("long",@LONG 
一进来你便发现这里与众不同，一切都是绿色的，苁蓉的大树环抱着
这里的一切，珍奇的花朵让你赏心悦目。一种回到久别家乡的感觉尤然而
升，于是多了一份惬意少了一份仇怨，和朋友多聊聊，和亲人多聚聚，为
你的生活多添一份乐趣少一份烦忧。
LONG
);

        set("exits", ([
                "out" : "/d/city/kedian",
        ]));

        set("objects", ([
               "/u/yanzi/bingqipu" : 1,
                "/adm/daemons/topten/bang" : 1,
        ]));

        set("no_fight",1);
        set("no_hit",1);
        set("no_array",1);
        set("no_sleep_room",1);
        set("no_kill",1);
        set("no_steal",1);
        set("no_yun",1);
        set("no_beg",1);
        setup();
        replace_program(ROOM);
}

