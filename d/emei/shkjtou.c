inherit ROOM;
 
void init();
void setxia2(object);

void create()
{
	set("short", "�߿߾�ͷ");
	set("long", @LONG
�����ڴ����߿��ˣ��������߿ߵľ�ͷ�ˣ�����һƬ�ڰ������Һ���
������һ����ɭ�ֲ�����������������ڰ�������ԼԼ�����ڿ����㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sheku",
]));
	set("no_clean_up", 0);

	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",110);
	setup();
}

void init()
{     
  object me = this_player();
  if( me->query_temp("xia1") ==1 && !me->query_temp("xia2") )  
  {remove_call_out("setxia2");
   call_out("setxia2",1,me);
  } 
}
void setxia2(object me)
{ 
  message_vision("�Ӻڰ����߳�һ���ϸ��˶�$N˵�����ܺã�����������Ÿ����ˡ���",me);
  me->set_temp("xia2",1);
}