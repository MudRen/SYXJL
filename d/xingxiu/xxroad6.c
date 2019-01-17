// xxroad6.c
// by QingP

inherit ROOM;

void create()
{
        set("short", "山间平地");
        set("long", @LONG
    山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一眼清泉(qingquan)。
LONG
        );

        set("resource/water", 1);
        
        set("objects", ([
                __DIR__"obj/yangrouchuan.c" : 3]));


        set("exits", ([
  "south" : __DIR__"xxroad5",
]));

        set("item_desc", ([
                "qingquan" : "泉水潺潺地流着...你看着清澈见底的泉水，觉得自己似乎有点渴了。\n"

        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
