
// Room: /jingzhou/mujiangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "木匠铺");
        set("long", @LONG
这是一家简陋的木匠铺，一个中年木匠正蹲在地上钉东西。地上和墙角
凌乱地堆放着一些桌子，椅子，拐棍什么的，还有几件似乎是锯子，刨子一
类的木匠工具。也不知道为什么，听说这里的木匠打造出来的木刀木剑很受
欢迎。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"yingdulu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}