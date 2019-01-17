inherit ROOM;     

int do_search();  
void end(object);

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是峨嵋派的后山，你正处在一片阴森的树林中。茂密的树支遮
挡了阳光，在黑暗的树林里不时有毒蛇游过，好恐怖的地方，但好象低
上长满了不知名的草药。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"houshan1",
]));
 	set("objects",([
          __DIR__"npc/snake" : 3,
      ])); 
      set("shen",1+random(2));
	set("coor/x",-40);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",120);
	set("coor/z",110);
	setup();
	
}



void init()
{         
   add_action("do_search","search");
}                                   

int do_search()
{
  object me = this_player();
  int jing;    
  if( me->is_busy() )
  return notify_fail("你上一个动作还没有完成呢。\n");                       
  jing=me->query("jing");
  if(jing<30)                    
  return notify_fail("你无法集中精力查看！\n");
  message_vision("$N开始查看这里的一草一木，希望能找到一棵草药什么的。\n",me);
  me->start_busy(2); 
  me->set("jing", jing-10); 
  call_out("end",3,me);
  return 1;
}  
                 
void end(object me)
{
 object ob;              
 object obj = environment(me);
  int exp;
 exp = me->query("combat_exp");
 switch(random(5)){
 case 2:  if(obj->query("shen") != 0)
          {ob=new(__DIR__"npc/obj/renshen"); 
          obj->set("shen",obj->query("shen")-1);
       exp += 30;
       me->set("combat_exp",exp);
          ob->move(me);
          message_vision("$N找到了一棵人参，放在$N的身上。\n",me);
          message_vision("$N的经验增加了！\n",me);
          break;                            
          }
 case 1:  message_vision("$N累了个半死，结果什么都没有找到。\n",me);
          break; 
 case 0:  message_vision("$N惊出了一条毒蛇！\n",me);
          ob=new(__DIR__"npc/snake");
          ob->move(environment(me));
          break;  
 default: ob=new(__DIR__"npc/obj/caoyao");
           exp += 5;
           me->set("combat_exp",exp);
          ob->move(me);
          message_vision("$N找到了一片草药，放在$N的身上。\n",me);
           message_vision("$N的经验增加了！\n",me);
          break;         
 }
}

