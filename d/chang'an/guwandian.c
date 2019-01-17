
// Room: /chang'an/guwandian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "古玩店");
        set("long", @LONG
这里的老板刚打咸阳搬来，一脸的和善之气。但有人谣传说他就是当
年横行大沙漠的“黄旋风”，对于这些谣言，黄老板也是无可奈何。听说官
府暗中调查了他好久，一直没有什么证据，也就罢了。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"yaowangdong",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}