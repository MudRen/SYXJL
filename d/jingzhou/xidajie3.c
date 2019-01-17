
// Room: /jingzhou/xidajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
真是块喧闹的地方，往东面可以看到花台中央那棵上千年龄的大树，
北面是一家钱庄，南面却是一片喧哗，不断有各类吆喝声传出来，进进出
出发都是三流九教的人物，原来那里是一家赌场。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"huatai",
                "south" : __DIR__"duchang",
                "west"  : __DIR__"xidajie2",
                "north" : __DIR__"qianzhuang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}