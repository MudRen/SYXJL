// shanlu2  ..angle
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条窄窄的山路蜿蜒而上，路旁尽是又矮又密的灌木丛，一些碎石铺
成的小路却是格外的搁脚！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  "northup" : __DIR__"shanlu3", 
  "westdown" : __DIR__"shanlu1",]));
        set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
}


