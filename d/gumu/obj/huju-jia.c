#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "护具架" NOR, ({ "huju jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", "一个木头制成的架子，上面挂着铁甲(armor)等护具。\n
命令格式: na armor from jia。\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}

void init()
{
       add_action("do_get","na");
}

int do_get(string arg)
{
      object me,ob;
      string arg1,arg2;
      me=this_player();
      if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
          return notify_fail("命令格式: na <护具名称> from jia。\n");
      if (arg2!="jia")
          return notify_fail("命令格式: na <护具名称> from jia。\n");
      if(me->query_temp("marks/拿"))
          return notify_fail("你怎么这么贪心，拿过了还要拿？\n");
      if(me->query("combat_exp") > 120000)
          return notify_fail("你武艺已到一定程度，还是自食其力吧。\n");
      if (arg1 =="armor"){
           ob=new("/d/city/obj/tiejia"); 
          ob->move(me);
          message_vision("$N从护具架上拿出一件$n。\n",me, ob); 
          me->set_temp("marks/拿",1);
          return 1;
          }     
     return notify_fail("护具架上没有你想要拿的东西。\n");
}

