inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������Ԩ��վ�ڴ˼䣬��һ��������������ǣ������ڴˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"houhuayen",
]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
          add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object ob;
        int new_jing;
        ob = this_player();
        new_jing = random( ob->query("max_jing")*3 );
        if ( new_jing > ob->query("jing") ) new_jing = ob->query("jing") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("��Ҫ����ȥ������ɱ����suicide -f��һ�㣺P��\n");
        if( (ob->query("dex") < 20) && ((int)ob->query_skill("dodge")<30) )
                return notify_fail("�������ڵ����֣�����ȥֻ����·һ����\n");
       message_vision("$N�������ǣ�һ������������ȥ��\n", ob);
       environment(ob), ({ob});
       message_vision("$N���б任���Σ�һ���շ�����ƮƮ�����ڵ��ϣ�\n", ob);
       environment(ob), ob;  
       ob->add("jing", 0 - new_jing);
       ob->move(__DIR__"dashikuai");
       return 1;
}
