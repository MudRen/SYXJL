
// Room: /jingzhou/silao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "死牢");
        set("long", @LONG
四周都是凌乱的已经湿漉漉的稻草，散发出呛鼻的霉味，稻草里露出一
些白森森的不知道什么动物的骨头，马桶已经散了架，地上有一些破碎的瓷
片。里面的人已经看不出什么人的形状了，可能食物供给也几乎没有，就连
墙缝里的蝙蝠都被他们活活吃掉了。你只想快点离开这个鬼地方。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jianyuguodao2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}