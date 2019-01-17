
// Room: /jingzhou/duchang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "赌场");
        set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。由于江
汉平原物产较为丰富，近些年又未糟天灾，百姓们手头都略有赢余，所以
好赌成风，来来往往的人不少，大多却垂头丧气地埋怨自己糟糕的手气。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"xidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}