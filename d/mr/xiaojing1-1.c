#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小径");
         set("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，北面是小径的延
伸，南面就到了岸边。
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"anbian1",
             "north" : __DIR__"xiaojing1-0",
]));
        set("coor/x",80);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
