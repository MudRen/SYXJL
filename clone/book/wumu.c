inherit ITEM;
#include <ansi.h>

void init();
int do_read(string arg);

void create()
{
        set_name(HIG"〖武穆遗书〗"NOR, ({"wumu yishu","yishu","book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
   set("long",
   "这是一本当年岳武穆的行军用兵的心得，后来流传的江湖，是武林人士梦寐以求的好东西。\n");
        set("material", "paper");
        set("value", 500);   
        }
}

void init()
{
  add_action("do_read", "yanjiu");
}

int do_read(string arg)
{
   object me;
   int jing_cost, gain;
   
   me=this_player();

       if( !this_object()->id(arg) ) return 0;
       if( me->is_busy() )
             return notify_fail("你现在忙着呢，没空看兵书。\n");
      if( me->is_fighting() )
             return notify_fail("有没有搞错？打架时还有时间翻兵书...\n");
   
   if( (int)me->query_skill("literate",1)<200 )
     return notify_fail("你照着武穆遗书摇头晃脑地哼了几句，不过没明白是啥意思。\n");
   if( (int)me->query_skill("literate",1)>250 )
     return notify_fail("你在文字方面已经很有造诣，这本书不会让你长进多少。\n");
   if( (int)me->query_skill("shen",1)<20000 )
     return notify_fail("你照着武穆遗书哼了几句，不过没明白为什么正派人士要抢这本破仁义道德的书。\n");

   jing_cost = 10 + (50-(int)me->query("int"));
   if( (int)me->query("jing")<jing_cost )
     return notify_fail("你现在头晕脑胀，该休息休息了。\n");   
   me->receive_damage("jing", jing_cost);

   gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")+1;
   me->improve_skill("literate", gain);

       message_vision("$N仔细学习揣摩武穆遗书所记载的内容，似乎有点领悟。\n", me);
     
   return 1;
}
