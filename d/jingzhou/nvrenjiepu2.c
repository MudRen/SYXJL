
// Room: /jingzhou/nvrenjiepu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街店铺");
        set("long", @LONG
你还未跨进这家店铺的门，一位体态丰韵的老板娘便娇笑着迎了上来，
忙不迭地向你介绍本店的胭脂花粉是如何地好，不过从老板娘身上也看得出
来，要不是打扮得当，她那里能吸引到顾客！
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"nvrenjie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}