inherit ROOM;     

int do_search();  
void end(object);

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
������Ƕ����ɵĺ�ɽ�ˡ�����Ұ�ݴ������߹���ͷ��ż����С��
�Ӳ��д����������ط���ɭ�ֲ���ǰ����һ��Ƭ��ɭɭ�����֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houshan2",
  "south" : __DIR__"shandao",
]));

        set("coor/x",-40);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",110);
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
 // object ob ; 
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
 switch(random(10)){                   
 case 0:
 case 1:
 case 2:
 case 3:
 case 4:  message_vision("$N���˸����������ʲô��û���ҵ���\n",me);
          break;  
 default: ob=new(__DIR__"npc/obj/caoyao");
          ob->move(me);
          message_vision("$N�ҵ���һƬ��ҩ������$N�����ϡ�\n",me);
          break;         
 }
}
