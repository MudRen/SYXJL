
// Room: /chang'an/laosunjia.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "小食店");
        set("long", @LONG
这是一家很小的小吃店，看起来也算干净，店里到处充斥着羊膻味道。
墙角的桌子居然还有一块小小的匾额，隐约还能辨认上面写着“第一碗”，
布满了灰尘。听说这里的老板姓孙，是打老远的陕北来的。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"nanyuanmen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}