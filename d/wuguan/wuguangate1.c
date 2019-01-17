// Room: /d/wuguan/wuguangate.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "武馆大门");
        set("long", @LONG
这里是一个大宅子，门口高悬一个大匾“扬州武馆”，立了两个石狮，
你从大门口瞧进去，好象里面人来人往，都很繁忙的样子，门口站着两个
门卫，神情威严。
LONG );
        set("exits", ([
                  "north" : __DIR__"wuguangate",
        ]));
        set("objects", ([
                 __DIR__"npc/xiaoliumang" : 1,
        ]));
        setup();
}

