inherit ROOM;

void create()
{
        set("short", "���˶�");
        set("long", @LONG
�߹�����ڣ����ȾͿ���һ��ʯ�����´�Ʈҡ���ɷ���ǣ�ֱ��
�ɼ��½磬�������š�
LONG
        );
//         set("objects", ([
//                __DIR__"npc/xmabu": 1,]) );

        set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"xianren",
]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
        object me,room;
        me = this_player();
        if ( !arg || arg == "") return 0;
        if ( arg != "dong")
                return notify_fail("�ں�����ģ���������ȥ�����ɽ��\n");
//	if ( !me->query_temp("marks/zuan") )
//                return 0;
        if ( !(room== find_object(__DIR__"climb1")) )
                room = load_object(__DIR__"climb1"); 
//	me->delete_temp("marks/zuan");
        message("vision", me->name()+"����һ�²�֪��ʲô�ط����ȥ�ˡ�\n",environment(me), ({me}) );
        me->move(__DIR__"climb1");
        return 1;
}


