inherit ROOM;

int do_zuan();

void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
����СϪ��ǰ�ߣ�����ˮ��Խ��Խ����ǰ������һ�����ٲ���ˮ��
�ϰ��׸ߵ�������ֱк���£����������ˮ�����ټ���ˮ����������ն�
�ǻ����ɵġ��ٲ�����������һ��ɽ����
LONG
	);
	set("exits", ([ 
  "northwest" : __DIR__"xiaoxi2",
]));
	
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",110);
	setup();
	
}
        
void init()
{
  add_action("do_zuan","zuan");
}                              

int do_zuan()
{                                                           
  object me = this_player();
  if((int)me->query_skill("dodge",1)<10)
    message_vision("$Nһ�������������һ��أ����ٲ����ȥ��\n���$N��ˮ�������˻�����\n",me);
  else 
    {message_vision("$Nһ�������������һ��أ����ٲ����ȥ��\n$N�ɹ���������ٲ���\n",me);
     me->move(__DIR__"shdong1");
    } 
  return 1;
}