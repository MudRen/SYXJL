#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","藏经阁");
         set ("long",@long
这里是曼陀罗山庄的藏经阁, 天下武功皆荟粹与此, 包罗万象,可与 "燕子
坞" 的藏书相辟敌。 屋子四周全是一排排高大的书架。
long);
	set("no_fight", 1);
	set("exits",([
	       "down" : __DIR__"yunjinlou",
	]));
        set("coor/x",120);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
