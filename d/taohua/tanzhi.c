// tanzhi.c ��ָ��

inherit ROOM;

int do_tan(string arg);

void create()
{
	set("short", "��ָ��");
	set("long", @LONG
�������һ���Ψһ��һ��ɽ��,������ȥ,����������һ�����׳������
�������Ĵ�.���е����±�����һ���޴�İ���ӡ(bagua).
LONG
	);
	set("exits", ([
              "north" : __DIR__"houyuan",
		 ]));	
	set("item_desc", ([
		"bagua" : "����һ���޴�İ���ӡ,������һЩָӡ,������������ǿ����ָ������ȥ�ġ�\n",
	]));

	set("coor/x",50);
	set("coor/y",-250);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_tan", "tan");
}


int do_tan(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "bagua" ) )
		return notify_fail("ʲô��\n");

	jing_cost = (-1) * random(20);
	if((int)me->query("jing") < jing_cost)
		return notify_fail("�����ھ����޷����У�\n");

	me->add("jing", jing_cost);
	message("vision",
			me->name() + "��׼�����ϵ����ָӡ���˹�ȥ��\n",
			environment(me), ({me}) );
	
	if ( (int)me->query_skill("finger", 1) < 101)
	{
		me->improve_skill("finger", me->query("int"));
		write("����ָ���Ű���ӡ����ȥ,����ĥ��һ�ض����ƺ���ָ���е��ĵá�\n");
		me->set_temp("bagua_learned",1);
	}
	    

	if ( !me->query_temp("bagua_learned") )
	{
		write("����Ű���ӡ��ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}

