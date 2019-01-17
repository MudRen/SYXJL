
// Room: /jingzhou/quyuanlu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "屈原路");
        set("long", @LONG
走在崭新光洁的青石路面上，感觉说不出的轻松，这一带往来的人流
看起来要稀疏一些，向南却看得见一家小食摊，倒也有些生意。。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingnanlu",
                "south" : __DIR__"xiaoshitan",
                "north" : __DIR__"quyuanlu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}