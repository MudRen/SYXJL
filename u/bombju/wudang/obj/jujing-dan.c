// jujing-dan.c �۾���

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"����۾���"NOR, ({"jujing dan","dan"}));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"����һ��ҩ�����˵�"HIY"����۾�����\n"NOR);
                set("value", 10000);
                set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "���������������ˡ�\n");
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        if ( me->query_skill_mapped("force") != "taiji-shengong" )
        {
                if( me->query("max_jingli")>=10)
                {
                   me->add("max_jingli", -10);
                   message_vision(HIR "$N����һ������۾�����ֻ����ͷ�����ѣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
                   me->unconcious();
                }
                else
                {
                   me->set("max_jingli", 0);
                   message_vision(HIR "$N����һ������۾�����ֻ����ͷ�����ѣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
                   me->unconcious();
                }
                destruct(this_object());
                return 1;
        }

 if ( me->query("max_jingli") < 150 )
        {
                if( me->query("max_jingli")>1)
                {
                   me->add("max_jingli", -1);
                   message_vision(HIR "$N����һ������۾�����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
                 }
                 else
                 {
                   message_vision(HIR "$N����һ������۾�����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
                   me->unconcious();
                 }

        }
        else if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                if( me->query("max_jingli")>1)
                {
                   me->add("max_jingli", -1);
                   message_vision(HIR "$N�ֳ���һ������۾�����ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
                 }
                 else
                 {
                   message_vision(HIR "$N�ֳ���һ������۾�����ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
                   me->unconcious();
                 }
        }
        else
        {
                me->add("max_jingli", random(me->query("kar")*2));
                message_vision(HIY "$N����һ������۾�����ֻ��������ƮƮ���ɣ��پ�����ٱ���\n" NOR, me);
                me->apply_condition("bonze_drug", 20);
        }
        
        destruct(this_object());
        return 1;
}
