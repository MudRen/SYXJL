inherit ROOM;                        

int jingzuo();
void end(object);

void create()

{
        set("short", "峨嵋金顶");
        set("long", @LONG

这里就是峨嵋山著名的金顶了，放眼望去，白云从脚下飘过，整个金
顶就象是漂在云海中的小舟，甚至可以看到著名的金顶佛光。
LONG );

        set("exits",([
          "south" : __DIR__"yhchkou",
           ]));

        setup();

}

void init()

{
  add_action("jingzuo","jingzuo");
}           

int jingzuo()

{
  object me = this_player();
  int jing;
  if( me->is_busy() )
  return notify_fail("你上一个动作还没有完成呢。\n");  
  jing=me->query("jing");
 if(jing<10) 
  return notify_fail("你无法集中精力静坐！\n");
  if(environment(me)->query("short")!="峨嵋金顶")
      return notify_fail("你不在金顶如何静坐了呢？\n");
  message_vision("$N开始在峨嵋绝顶上静坐参悟。\n",me);
         me->start_busy(3);
  me->set("jing", jing-10);
   call_out("end",5,me);
  return 1;
}          

void end(object me)

{
 int potential;
 int skill_lvl;
 if (me->query_skill("mahayana",1)>me->query_skill("buddhism",1))
     skill_lvl=me->query_skill("mahayana",1);
 else 
     skill_lvl=me->query_skill("buddhism",1);
 potential = me->query("potential");
 potential += (random(skill_lvl/2+me->query("kar"))/2);
 me->set("potential",potential); 
 message_vision("$N的潜能增加了！\n",me);
}

