
// Room: /jingzhou/nvrenjiepu5.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街店铺");
        set("long", @LONG
一进门就是一真眩目的珠光宝气，原来这里是一家专门经营珠宝首饰的
地方，老板看起来是个势利的人，对那些衣着光鲜的客人总是热情要多一点
点，一天到晚都堆着笑，因此鱼尾纹和她的实际年龄倒很不相符。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"nvrenjie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}