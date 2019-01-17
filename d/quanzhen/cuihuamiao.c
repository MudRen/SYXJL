// cuihuamiao.c 翠华庙

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "翠华庙");
	set("long", @LONG
隐藏于群山丛林中的一座小庙，有当地人集资而建。庙中供奉着城隍
爷。庙的四周都是一片片的松树林。庙前是一清石铺成的广场，零星分部
着几个石墩子，供游客歇脚。往上是抱子岩。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"west" : __DIR__"songlin3",
		"northup" : __DIR__"baoziyan",
                "east": __DIR__"songlin2", 
                "north": __DIR__"songlin1",
                "south": __DIR__"taiyihu",
	]));
	setup();
	replace_program(ROOM);
}


