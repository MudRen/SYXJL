inherit ROOM;
int do_work(); 
void end(object);

void create()
{
	set("short", "�﷿");
	set("long", @LONG
�����Ƕ����ɵĻ﷿�������ջ���������æ�������������������ӣ�
��ʱ���ж����ɵ��ӽ�����æ�ġ�һ����������Ĺ���ģ��������ָ��
�����˸ɻ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shanfang",
]));
	

	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	
}
                     
void init()
{
   add_action("do_work","work");
}                               

int do_work()
{
  object me = this_player();
  if( me->is_busy())
     return notify_fail("����һ��������û������ء�\n");
  if(me->query("qi") < 50 )
     return notify_fail("�������̫���ˣ����ܸ������\n");
  me->set("qi",me->query("qi")-50);
  message_vision("$N����˵����������ɻ����Ǯ����\nһ�������߹���˵�����ðɡ���\n$N��ʼ�ɻ\n",me);
  me->start_busy(5); 
  call_out("end",7,me);
  return 1;
}          

void end(object me)
{ 
  object ob;
  message_vision("$N���ڰѻ�����ˡ�\nһ�������߹������˿���˵����������\n���¸���һЩ���ӡ�\n",me);
  ob=new("/clone/money/silver");
  ob->move(me);
}
