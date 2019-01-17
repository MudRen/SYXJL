#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小径");
         set ("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。远处的一座小屋子映入你的眼帘，阵阵炊烟从小屋后面的烟囱
中冒出。
long);
         set("outdoors","mr");
         set("exits",([
             "northeast" : __DIR__"xiaojing4",
             "west" : __DIR__"xiaoshe",
]));
         set("coor/x",150);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
         replace_program(ROOM);
}
