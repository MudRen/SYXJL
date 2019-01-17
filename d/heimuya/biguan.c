inherit ROOM;
int do_study(string arg);

void create()
{
        set("short", "�չ���");
        set("long", @LONG
�������������ڵ������������ҡ�������С��ȴҲ�����ȫ����ʱ����
�а����´�Ȩ�����������ܺ󣬾�������������Ǵ󷨡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "up" : __DIR__"xiaosiwu",
]));

        set("objects",([
                __DIR__"obj/book4" : 1,
        ]));

        set("item_desc", ([
                "ʯ��" : "����һ������������ɵ�ʯ�ڣ��������Щ��ֵ�ͼ�Ρ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_study", "study");
}

int do_study(string arg)
{
        object me;

        me = this_player();

        if ( !arg || ( arg != "ʯ��" ) )
                return notify_fail("ʲô��\n");

        if ( (int)me->query_skill("literate", 1) < 60)
                return notify_fail("��ĺ���ѧʶ̫�٣��޷�����ͼ���ϵĸ���ĵ�����\n");

        
        if ( (int)me->query_skill("blade",1) < 50 )
                {
                write("��ĵ������̫ǳ���޷�����ͼ���ϵĸ���ĵ�����\n");
                return 1;
                }

        me->add("jing", (-1)*random(40));

        message_vision("$N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n", me);

        switch( random(1) )
        {
            case 0:
                if ( (int)me->query_skill("blade", 1) < 100)
                {
                        me->improve_skill("blade", me->query("int"));
                        write("�����ʯ���ϵ�ͼ����ĥ��һ�ض����ƺ��Ե����е��ĵá�\n");
                        me->set_temp("stone_learned",1);
                }
        }

        if ( !me->query_temp("stone_learned") )
        {
                                write("�����ʯ���ϵ�ͼ����ĥ��һ�ض�������ûʲô��˼�����ܶ�������˵̫ǳ�ˡ�\n");
        }
        return 1;
}
