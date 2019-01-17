inherit ROOM;
void init();
int do_yao();
void end(object);

void create()
{
	set("short", "�ŷ�");
	set("long", @LONG
�����Ƕ����ɵ��ӳԷ��ĵط��ˣ���ʱ�е��ӽ�����������Ȼ��ʱ��
����ʱ��Ҳ�����������������������˳Է��ĵ���������Է���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beilang2",
  "east" : __DIR__"huofang",
]));
	set("objects",([
          __DIR__"npc/obj/bocai-fentiao" : 2,
          __DIR__"npc/obj/mantou" : 1,
          __DIR__"npc/obj/dawancha" : 2, 
            ]));   
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	
}
                  
void init()
{
 add_action("do_yao","yao");
}
                            
int do_yao()
{
 object me = this_player();        
 int jing; 
 if(me->is_busy())            
 return notify_fail("����һ��������û������ء�\n");
 message_vision("$N��һ�������з��𣿡�\n������߳�һ������˵�������˶����������ˣ���Ҫ�Ծͳԣ������Լ�������\n",me); 
 jing=me->query("jing");
 if(jing<30)
 return notify_fail("���������ľ���Ҳû�У�\n");
 message_vision("$N��ʼ������\n",me);
 me->start_busy(5); 
 me->set("jing", jing-30); 
 call_out("end",7,me);
 return 1;
} 

void end(object me)
{
 object ob;
 switch(random(3)){
 case 0:  ob=new(__DIR__"npc/obj/bocai-fentiao");
          ob->move(me);
          message_vision("$N�����˲��˷���������$N�����ϡ�\n",me);
          break;
 case 1:  ob=new(__DIR__"npc/obj/mantou");
          ob->move(me);
          message_vision("$N��������ͷ������$N�����ϡ�\n",me);
          break;
 case 2:
 case 3:  ob=new(__DIR__"npc/obj/dawancha");
          ob->move(me);
          message_vision("$N�����˴���裬����$N�����ϡ�\n",me);
          break;
 }
}
