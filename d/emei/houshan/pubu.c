inherit ROOM;

int do_zuan();

void create()
{
	set("short", "瀑布");
	set("long", @LONG
逆着小溪向前走，随着水声越来越大，眼前出现了一个大瀑布，水从
上百米高的悬崖上直泻而下，溅起漫天的水花，再加上水气，整个天空都
是灰蒙蒙的。瀑布后面隐隐有一个山洞。
LONG
	);
	set("exits", ([ 
  "northwest" : __DIR__"xiaoxi2",
]));
	
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",110);
	setup();
	
}
        
void init()
{
  add_action("do_zuan","zuan");
}                              

int do_zuan()
{                                                           
  object me = this_player();
  if((int)me->query_skill("dodge",1)<10)
    message_vision("$N一弯腰，足尖用力一点地，向瀑布冲过去。\n结果$N被水流给冲了回来。\n",me);
  else 
    {message_vision("$N一弯腰，足尖用力一点地，向瀑布冲过去。\n$N成功的钻进了瀑布！\n",me);
     me->move(__DIR__"shdong1");
    } 
  return 1;
}