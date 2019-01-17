#include <weapon.h>
#include <ansi.h>

inherit SWORD;
int do_du(string arg);

void create()
{
        set_name(HIC"���佣"NOR, ({ "zhenwu jian","jian", "sword"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
     set("no_sell", 1);
     set("long", "һ����������ı������������ƺ�����һЩͼ������֪��ʲô��˼��\n");
     set("wield_msg", "$N��ﬡ���һ����һ�������������γ�һ��$n��\n");
     set("unwield_msg", "$N��$n������У����¶��һ˿Ц�⡣\n");
                set("material", "iron");
        }
        init_sword(160);
        setup();
}


void init()
{
        add_action("do_du", "kan");
}

int do_du(string arg)
{       int gain;
        object me=this_player();
        object ob=this_object();

        if(! ob->query("OK_to_STUDY"))
                return notify_fail("���޷�������������ѧ���κζ�����\n");

        if( (int)me->query_skill("sword", 1) >= 200)
                return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˡ�\n");
        if( (int)me->query_skill("literate", 1) < 20)
                return notify_fail("�����������ʶ�ֲ������޷���������ͼ����\n");

        if( (int)me->query_skill("literate", 1) < (int)me->query_skill("sword", 1) )
                return notify_fail("�����������ʶ�ֻ������ʱ�����򲻳�����һ��Ľ�����\n");

        if( (int)me->query("qi") < 30)
                return notify_fail("��̫���ˣ�ЪЪ�����ɡ�\n");
        if( (int)me->query("jing") < 30)
                return notify_fail("��̫ƣ���ˣ�ЪЪ�����ɡ�\n");
        gain= (int)me->query_skill("literate", 1)/3 + 1 + random((int)me->query_int());

        me->improve_skill("sword", gain);
   me->receive_damage("qi", 30);
   me->receive_damage("jing", 30);

        write("�����洧Ħ�����佣�ϵ�ͼ�ģ��ƺ��ԡ������������������˽⡣\n");
        tell_room( environment(me), me->name() +"˫�۶������佣�����ﻹ��֪�ڱȻ�ʲô��\n", ({me}));
        return 1;
}

