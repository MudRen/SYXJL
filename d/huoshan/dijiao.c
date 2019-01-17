
// Room: /huoshan/dijiao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "地窖");
        set("long", @LONG
与其他的房间不同，这里的光线很暗淡，只有墙脚的一盏小油
灯燃着跳跃的火花，照得你的影子摇弋不定。顺着墙一溜地整齐地
放着一排排的橡木酒桶，里面都是极端名贵的葡萄美酒。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "up"  : __DIR__"shiwu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}