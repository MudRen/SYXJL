inherit ROOM;

void create()
{
        set("short", "ǧ��ʯ");
        set("long", @LONG
����Ȫ������һ����ƺ����ƺ��������һ����̴��̵ľ�ʯ��
��������ǧ��֮�ã�ʯ�ϱ�Ե����֪����������֡�ǧ��ʯ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"baizhang",
]));
        set("objects", ([
                __DIR__"npc/tufeitou": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}

int do_study(string arg)
{
        object me;
        me = this_player();
        if ( !arg || (arg != "stone" ))
               return notify_fail("ʲô��\n");
        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
        me->receive_damage("jing", 30);
        message_vision("$N��ר���ж�ƺ�ϵ�ʯͷ��\n", me);

        if ( (int)me->query_skill("unarmed", 1) < 101)
        {
                me->improve_skill("unarmed", me->query("int"));
                write("�����ʯƺ�ϵġ����֡���ĥ��һ�ض����ƺ��Ի���ȭ�������ĵá�\n");
                return 1;
        }
        write("�����ʯƺ����һ�ض�������������˵��ȭ��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
        return 1;
}

