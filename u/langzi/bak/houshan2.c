inherit ROOM;     

int do_search();  
void end(object);

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�����Ƕ����ɵĺ�ɽ����������һƬ��ɭ�������С�ï�ܵ���֧��
�������⣬�ںڰ��������ﲻʱ�ж����ι����ÿֲ��ĵط����������
�ϳ����˲�֪���Ĳ�ҩ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"houshan1",
]));
 	set("objects",([
          __DIR__"npc/snake" : 3,
      ])); 
     set("shen",random(2));
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
  return notify_fail("����һ��������û������ء�\n");                       
  jing=me->query("jing");
  if(jing<30)                    
  return notify_fail("���޷����о����鿴��\n");
  message_vision("$N��ʼ�鿴�����һ��һľ��ϣ�����ҵ�һ�ò�ҩʲô�ġ�\n",me);
  me->start_busy(2); 
  me->set("jing", jing-10); 
  call_out("end",3,me);
  return 1;
}  
                 
void end(object me)
{
 object ob;              
 object obj = environment(me);
 switch(random(5)){
 case 2:  if(obj->query("shen") != 0)
          {ob=new(__DIR__"npc/obj/renshen"); 
          obj->set("shen",obj->query("shen")-1);
          ob->move(me);
          message_vision("$N�ҵ���һ���˲Σ�����$N�����ϡ�\n",me);
          break;                            
          }
 case 1:  message_vision("$N���˸����������ʲô��û���ҵ���\n",me);
          break; 
 case 0:  message_vision("$N������һ�����ߣ�\n",me);
          ob=new(__DIR__"npc/snake");
          ob->move(environment(me));
          break;  
 default: ob=new(__DIR__"npc/obj/caoyao");
          ob->move(me);
          message_vision("$N�ҵ���һƬ��ҩ������$N�����ϡ�\n",me);
          break;         
 }
}

