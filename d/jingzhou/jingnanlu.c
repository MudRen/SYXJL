
// Room: /jingzhou/jingnanlu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "荆南路");
        set("long", @LONG
这里的路面不是很好，路边有一些工人正在撬着一些石板，看来是准
备改建了，南边是一家车马行，北边不时可以看见一些驿使骑着快马进进
出出。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingnanlu2",
                "south" : __DIR__"chehang",
                "west"  : __DIR__"quyuanlu",
                "north" : __DIR__"yizhan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}