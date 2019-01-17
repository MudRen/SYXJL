
// Room: /jingzhou/jingzhonglu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "荆中路");
        set("long", @LONG
这里是荆州城内最为宽阔的路面，往来的人流仍然显得十分拥挤。西
面是城中心的标志建筑花台，南面是此地守备的将军府，往北走就到了本
地的武馆了。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingzhonglu2",
                "north" :"/d/wuguan/wuguangate",
                "west"  : __DIR__"huatai",
                "south" : __DIR__"jiangjunfu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
