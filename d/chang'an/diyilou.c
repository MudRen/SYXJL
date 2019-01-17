
// Room: /chang'an/diyilou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "第一楼");
        set("long", @LONG
长安城里没有不知道“第一楼”的。由于这里是西部要冲，来往公务繁
多，富商大贾云集，所以生意非常兴隆。楼下布置相对要简易一些，顾客
多是匆匆的行人，买点干粮、烤羊腿、酒袋就赶路去了。楼上是雅座。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"dongdajie1",
                "up"    : __DIR__"diyilouerlou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}