// shanlu5  ..angle
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条窄窄的山路蜿蜒而上，路旁尽是又矮又密的灌木丛，一些碎石铺
成的小路却是格外的搁脚！马上就要到山顶了，加把力呦！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  "eastup" : __DIR__"shanlu6", 
  "eastdown" : __DIR__"shanlu4",]));
        set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",50);
	setup();
}

