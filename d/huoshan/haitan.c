
// Room: /huoshan/haitan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "海滩");
        set("long", @LONG
银白色的沙滩软软的，走在上面，身后便留下自己一串清晰的
脚印。在和暖的阳光下，这里的海风吹得头发顺风飞扬，让人感觉
很舒服。深沉的海涛拍打着暗边的礁石发出澎湃的声音，湛蓝的大
海和瓦蓝的天空在目尽处连成了一线。朵朵的白云下一群群白色的
海鸟扇动着翅膀，时而发出一阵阵高昂的叫声。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"shandong7",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}