// shanlu3  ..angle
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
  "westup" : __DIR__"shanlu4", 
  "southdown" : __DIR__"shanlu2",]));
        set("coor/x",40);
	set("coor/y",-30);
	set("coor/z",30);
	set("coor/x",40);
	set("coor/y",-30);
	set("coor/z",30);
	set("coor/x",40);
	set("coor/y",-30);
	set("coor/z",30);
	set("coor/x",40);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
}


