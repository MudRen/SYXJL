// shanlu4  ..angle
inherit ROOM;

void create()
{
        set("short", "山腰");
        set("long", @LONG
你来到了这座小山的半山腰，可以长长地舒口气了，呼吸一下清新的
空气。路边一些嶙峋的怪石无规则的摆在地上，游人可以坐下来歇歇脚，
在树荫下乘乘凉，倒也是十分的惬意！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  "westup" : __DIR__"shanlu5", 
  "eastdown" : __DIR__"shanlu3",]));
        set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",40);
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",40);
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",40);
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",40);
	setup();
}



