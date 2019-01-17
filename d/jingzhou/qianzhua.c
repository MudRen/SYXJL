
// Room: /jingzhou/qianzhuang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "钱庄");
        set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，跟山西的钱庄大户门经
常有着往来，一样在全国各地都有分店。它发行的银票信誉非常好，通行
全国。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"xidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}