
// Room: /jingzhou/nvrenjiepu4.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街店铺");
        set("long", @LONG
这里卖的是些各色丝绸和锦缎，还有一些狐狸，水貂等等贵重的毛皮。
很多少妇和姑娘都偷偷买一些回去搭配了给自己的丈夫或者相好做件风光的
衣裳。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"nvrenjie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}