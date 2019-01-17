
// Room: /chang'an/diyilouerlou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "第一楼二楼");
        set("long", @LONG
走上楼来，酒肉的香味扑鼻而来，令你忍不住也想坐下来要上一份酒
菜才好。这里的顾客很多，几乎已经座无虚席了，几名跑堂的前后吆喝，
简直忙不过来了。看来要吃饭你得快找个桌子坐(zuo)下来。桌子上有一份
菜单(caidan)。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"diyilou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}