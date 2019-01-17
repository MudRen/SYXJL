
// Room: /jingzhou/datiepu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "打铁铺");
        set("long", @LONG
你一走进来就感到浑身火热。原来这是一家简陋的打铁铺，中心摆着
一个火炉，炉火把四周照得一片通红，墙角堆满了已经完工和未完工的菜
刀、镰刀、渔叉等物。两位年轻铁匠满头大汗挥舞着铁锤，专心致志地在
打铁。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"jingnanlu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}