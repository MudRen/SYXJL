
// Room: /chang'an/yuqihang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "玉器行");
        set("long", @LONG
这是一家专门经营蓝田玉的店铺，南墙上还张贴着“沧海明月珠有泪，
蓝田日暖玉生烟”的字幅，也不知道是出自谁的手笔。由于长安东蓝田地
带盛产蓝田玉，到此一游的客人一般都会捎点这种玉器回去。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"dongdajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}