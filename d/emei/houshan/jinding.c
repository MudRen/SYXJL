inherit ROOM;                        

int jingzuo();
void end(object);

void create()

{
        set("short", "���ҽ�");
        set("long", @LONG

������Ƕ���ɽ�����Ľ��ˣ�������ȥ�����ƴӽ���Ʈ����������
��������Ư���ƺ��е�С�ۣ��������Կ��������Ľ𶥷�⡣
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
  return notify_fail("����һ��������û������ء�\n");  
  jing=me->query("jing");
 if(jing<10) 
  return notify_fail("���޷����о���������\n");
  if(environment(me)->query("short")!="���ҽ�")
      return notify_fail("�㲻�ڽ���ξ������أ�\n");
  message_vision("$N��ʼ�ڶ��Ҿ����Ͼ�������\n",me);
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
 message_vision("$N��Ǳ�������ˣ�\n",me);
}

