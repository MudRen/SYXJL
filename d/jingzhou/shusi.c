
// Room: /jingzhou/shusi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "书肆");
        set("long", @LONG
这里是书肆，窗明几净，一尘不染。壁上的书架 (shelf)，堆满明日帝
国的先贤们的文选，记录了明日帝国的风风雨雨和无数凄婉的、遥远磨灭不
去的传说。你可以阅读(read)到这些古老的故事。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"xidajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}