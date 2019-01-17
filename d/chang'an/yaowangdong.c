
// Room: /chang'an/yaowangdong.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "药王洞");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西面是一个很大的借
口拐角，东面是鼓楼。北面有一家店铺，但是出入的人看来不多，但几乎
个个都是衣着光鲜富翁模样的人，原来是一家古玩店。南面隐隐随风飘来
一阵中草药味。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beidajie2",
                "south" : __DIR__"yaopu",
                "west"  : __DIR__"jiekou1",
                "north" : __DIR__"guwandian",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}