
// Room: /jingzhou/caishikou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "菜市口");
        set("long", @LONG
往里走就是菜场了，这里却是官府处置死囚用来砍头的位置，刑台上还
有些没洗干净而留下来一些暗红的血迹，听说行刑的侩子手老张是有名的一
把快刀，但死囚却害怕的是他唯一的徒弟“锈锯子”林威，都想老张一刀来
个痛快，老张自然喜欢他这个驽钝的徒弟得很，因为有了这个徒弟，私下跟
他塞红包的人不知有多少，又不怕竞争下岗了
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "northwest" : __DIR__"zhangjuzhengjie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}