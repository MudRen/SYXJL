
// Room: /jingzhou/jiulou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "酒楼");
        set("long", @LONG
在此地内提起狮子楼可以说是无人不知，无人不晓。单是看着人家桌上
的酒菜已经令你食指大动了，实在让人按耐不住自己的食欲想去叫上一壶酒
几样特色菜才好。楼下布置相对要简单一些，顾客多是普通百姓。楼上是雅
座，城里的几个有名的公子哥儿几乎天天都要到上面饮酒作乐。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "up"  : __DIR__"jiulouerlou",
                "west"  : __DIR__"sanyijie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}