
// Room: /jingzhou/xiaoshitan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "小食摊");
        set("long", @LONG
此地象这样的小吃摊子很多，由于食品做得很有特色，味道也很不错，
所以吸引很多人都在这里尝个鲜。老板是两夫妻，听说他们做的汤圆在这里
可以称得上一绝了。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"quyuanlu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}