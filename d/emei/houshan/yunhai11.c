inherit ROOM;

void create()
{
	set("short", "�ƺ�");
	set("long", @LONG
�������������ˣ�������ȥ��������һƬ.��ֻ����ͷ���ƣ�������Ū
�����Լ����ںδ������ܺ����г�·�������ǿ���̫�����
LONG   );
  
	setup();
	
}

void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"yunhai1"+random(3));
  me->set("exits/west",__DIR__"yunhai1"+random(3));
  me->set("exits/north",__DIR__"yunhai1"+random(3));
  me->set("exits/south",__DIR__"yunhai1"+random(3));
}
