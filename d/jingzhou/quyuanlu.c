
// Room: /jingzhou/quyuanlu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "屈原路");
        set("long", @LONG
这里的路面好象刚刚翻新过，整齐的青石条铺砌得整整齐齐，向西往
去便是本地的首富万震山的宅院了，听说他的七个徒弟都是本地的一些望
族子弟。。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"quyuanlu2",
                "west"  : __DIR__"wanjiadazhai",
                "north" : __DIR__"jingzhonglu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}