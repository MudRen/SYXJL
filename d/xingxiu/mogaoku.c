inherit ROOM;

void create()
{
        set("short", "Ī�߿�");
        set("long", @LONG
����ǽ���ϻ�����������صĻ���(picture)������Ů���죬���з������á�
���л��кܶ����;��顣�㱻��Щ�������Ļ�֮�������ˡ�
LONG
        );
        set("exits", ([ 
             "north" : __DIR__"yueerquan",
]));

        set("item_desc", ([
                "picture" : read_file("/u/csy/photo")
// snicker csy xixi:)
        ]) );

        set("no_clean_up", 0);

        setup();
}
/*
void init()
{
        if (!this_player()->query_temp("think_times"))
                this_player()->set_temp("think_times",
                        7+random(this_player()->query_skill("literate", 1)/10));
        add_action("do_think", "think");
}
*/
int do_think(string arg)
{
        object me = this_player();
                
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

	if ( !arg || arg != "picture" )
		return notify_fail("����˼��ʲô��\n");

	if ( me->query("int")+(int)me->query_skill("literate",1)/10 < 42 )
		return notify_fail("�������̫�ͣ��޷����������Ůͼ�ĺ��塣\n");
	
        if ( (int)me->query("jing")<20)
                return notify_fail("��̫���ˣ�Ъ������ɣ�\n");

	if ( (int)me->query_skill("qimen-dunjia", 1) > 130 )
		return notify_fail("����ŷ�����Ůͼڤ˼���룬����û��ʲôֵ��������ˡ�\n");

	if ( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("���Ǳ���Ѿ����ӵ����ޣ��޷����������Ůͼ�ĺ��塣\n");

        if ( me->query_temp("think_times") == 0 )
        {
                tell_object(me,"����ŷ�����Ůͼڤ˼���룬����������Ѫ���������ۡ���һ���³�һ�����Ѫ...\n");
                message("vision",me->name()+"��Ȼ���ۡ���һ���³�һ�����Ѫ�����˹�ȥ��\n",environment(me),me);
                me->set_temp("think_times", 7+random(me->query_skill("literate", 1)/10));
                me->unconcious();
                return 1;
        }

       if (!me->query_skill("qimen-dunjia",1))
              me->set_skill("qimen-dunjia",0);
        me->add_temp("think_times", -1);
        me->add("jing", -(10+random(15)));
        me->add("learned_points", 1);
        me->improve_skill("qimen-dunjia", random((int)me->query_skill("literate", 1)/2)+1);
	
	tell_object(me, "����ŷ�����Ůͼڤ˼���룬ڤڤ���ƺ���������...\n������Ŷݼ׽����ˣ�\n");
	message("vision",me->name()+"���ŷ�����Ůͼ�����ķ�������֪���ڸ�ʲô��\n", environment(me), me);

        return 1;
}
