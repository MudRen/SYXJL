inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ɮ��˼��������ң����˵����м��������⣬ֻʣ�¹�ͺͺ��ǽ���ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanwugong",
	]));
        set("no_fight", 1);
	set("no_steal",1);

	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("dodge", me->query("int"));
	}

        add_action("do_mianbi","���");	
        add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	object me = this_player();

	message_vision("$N�������������ߵ�ʯ�ڵ�����˼�����ã���������\n", me);
	
	me->set_busy(10);
	me->set("shen",0);

	return 1;
}
