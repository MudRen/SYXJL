// tyroad1.c 石阶

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
这是一条宽大坚实的石阶路，不时地有进香客和游人从你的身边走过。抬头西
望，雄伟的三清殿顶浮现在香烟袅绕之中，巍峨壮观。南边一条石阶通往山下，
隐约可见远处桃花片片，赏心悦目。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"shanmen",
                "northup" : __DIR__"tyroad2",
        ]));
        set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	setup();
        replace_program(ROOM);
}
