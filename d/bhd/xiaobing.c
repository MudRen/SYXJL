inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
����һ��С�����������ֽŻ���������Զ֮������һ����ʯ����
������Ե���½�ء�

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"bingshan2",
]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
          add_action("do_tiao", "tiao");
}
int do_tiao(string arg)
{
        object ob;
        int new_jing;
        ob = this_player();
        new_jing = random( ob->query("max_jing")*3 );
        if ( new_jing > ob->query("jing") ) new_jing = ob->query("jing") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "yanshi" )
                return notify_fail("�㲻Ҫ���ˣ�Ҫ��ɱ����suicide -f��һ�㣺P��\n");
        if( (ob->query("dex") < 20) && ((int)ob->query_skill("dodge")<30) )
                return notify_fail("�������ڵ����֣�������ʯȥֻ����·һ����\n");
       message_vision("$N�������ǣ����������һ������һ������������ȥ��\n", ob);
       environment(ob), ({ob});
       message_vision("$N���б任���Σ�һ���շ�����ƮƮ��������ʯ�ϣ�\n", ob);
       environment(ob), ob;  
       ob->add("jing", 0 - new_jing);
	ob->move("/d/bhd/yanshi");
       return 1;
}



