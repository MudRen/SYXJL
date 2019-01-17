// room: /kunlun/damen.c
inherit ROOM;

void create()
{
        set("short", "三圣堂大门");
        set("long", @LONG
这里是昆仑派根本之地三圣堂的大门，昆仑派自从祖师昆仑三圣何足道开
山以来, 近年声名鹊起, 已经成为威镇西域的大门派，当今昆仑派掌门人铁琴
先生也是武林中的顶级高手。此大门虽装璜简洁, 却气势宏伟，几名佩剑的弟
子在门口侍立。门上有一块巨大的匾额(bian)。
LONG
        );

set ("objects",(["/d/kunlun/npc/kl-dizi3.c":2]));
        set("item_desc", ([
               "bian"    : "上书三个苍劲雄伟的大字“三 圣 堂”\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"qianting",
                "south" :__DIR__"shanmen",
        ]));

        set("coor/x",-180);
	set("coor/y",50);
	set("coor/z",30);
	set("coor/x",-180);
	set("coor/y",50);
	set("coor/z",30);
	set("coor/x",-180);
	set("coor/y",50);
	set("coor/z",30);
	setup();
//       "/clone/board/kunlun_b"->foo();
        replace_program(ROOM);
}

