inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
һ����ķ��䣬�յ�����û���κΰ��裬�������Ų�ͬ��С��ɳ��(dai)��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"liangongfang2",
]));
        set("no_clean_up", 0);

set("item_desc", ([
                "dai" : "��Щɳ�����ھ��������ڴ������(da),ɳ���쳣ƽ����\n",
        ]));

        setup();
        
}
void init()
{
        add_action("do_da", "da");
}


int do_da(string arg)
{
        int xianzhi;
        object me;

        me = this_player();

        if ( !arg || ( arg != "dai" ) )
                return notify_fail("ʲô��\n");
        if ( (int)me->query("combat_exp") >0) xianzhi=10;
        if ( (int)me->query("combat_exp") >800) xianzhi=20;
        if ( (int)me->query("combat_exp") >900) xianzhi=30;
        if ( (int)me->query("combat_exp") >6400) xianzhi=40;
        if ( (int)me->query("combat_exp") >12500) xianzhi=50;

        if ( (int)me->query("jing") < 40)
                return notify_fail("���Ѿ����۵��ˣ�����Ϣһ�°ɡ�\n");


        me->add("jing", (-1)*random(40));

        message_vision("$Nƴ��ȫ���ɳ���ȭ������ɳ����,ɳ�����һ��˻Ρ�\n", me);

        if ( (int)me->query_skill("unarmed", 1) < xianzhi)
        {
        me->improve_skill("unarmed", me->query("int"));
        write("����ƴ������������������ƺ��Ի���ȭ���е��ĵá�\n");
        me->set_temp("stone_learned",1);
        }
        else
        {
 write("��ƴ���ش�����ȥ��ȴ�о������κν�չ���������㾭\n"
       "�鲻������ȭ���Ѿ�������ʮ���ˡ�\n");
        }
        return 1;
}
