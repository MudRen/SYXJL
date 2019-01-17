// Room: houdian.c 后殿

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "后殿");
        set("long", @LONG
这里是全真教的后殿，殿正中挂着全真教创教祖师王重阳的遗像，靠墙
放着几张太师椅，地上放着几个蒲团，供后辈第子叩拜。往南是三清殿，
往北是第三殿。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"disandian",
            "south" : __DIR__"sanqingdian",
            "west" : __DIR__"xilang3",
            "east" : __DIR__"donglang3",
            ]));
	
        set("no_clean_up", 0);

        set("coor/x",-90);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",260);
	set("coor/z",190);
	setup();
        replace_program(ROOM);
}