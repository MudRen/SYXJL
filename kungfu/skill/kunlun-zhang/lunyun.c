luiyun.c ����ˮ��
luiyun.c ����ˮ��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
//        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( !me->is_fighting() )
        return notify_fail("������ˮ�䡹ֻ����ս����ʹ�á�\n");

    if( (int)me->query("neili") < 400 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("��Ļ����Ʒ��������ң��޷�ʹ������ˮ�䣡\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("��û�м��������ƣ��޷�ʹ������ˮ�䣡\n");
        
        
msg = HIR "$N���һ��ʹ���������еľ�ѧ������ˮ�䡹��������Ȼ���ӣ������ɨ���˵����ţ�\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("kunlun-zhang",1) / 3);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

        if(qi > (maxqi * 0.4))
        {       
        message_vision(msg, me, target);
                
                me->add_temp("str", count * 2); 
                me->add_temp("dex", 0-d_count);
                me->set_temp("liuyun", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

                me->add("neili", -80);
        return 1;
        }
        else{
                msg = HIR "$Nƴ����������ʹ�����������е��ռ�����������ˮ�䡹�� ȫ�����һ����, �������ͬ���ھ�!\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("str", count * 9);
                me->set_temp("liuyun", 1);

                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0:), 2);

                me->add_temp("str",  -(count * 29));            
                me->delete_temp("liuyun");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set("neili",0);
                me->add("max_neili",-10);

                msg = HIR "$N�þ������һ������, ���һ����Ѫ, һͷ�Ե��ڵ�!\n" NOR;
                message_vision(msg, me, target);

                me->set("jing",0);
                me->set("qi",0);

                me->unconcious();


                return 1;
        }
}

void remove_effect(object me, int aamount, int damount)
{
        
        if ( (int)me->query_temp("liuyun") ) 
        {
                me->add_temp("str", -aamount);
                me->add_temp("dex", damount);
                me->delete_temp("liuyun");
                tell_object(me, HIY "��ġ�����ˮ�䡹��������ϣ��������ջص��\n" NOR);
                me->start_busy(random(4));
        }
}




#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
//        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( !me->is_fighting() )
        return notify_fail("������ˮ�䡹ֻ����ս����ʹ�á�\n");

    if( (int)me->query("neili") < 400 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("��Ļ����Ʒ��������ң��޷�ʹ������ˮ�䣡\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("��û�м��������ƣ��޷�ʹ������ˮ�䣡\n");
        
        
msg = HIR "$N���һ��ʹ���������еľ�ѧ������ˮ�䡹��������Ȼ���ӣ������ɨ���˵����ţ�\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("kunlun-zhang",1) / 3);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

        if(qi > (maxqi * 0.4))
        {       
        message_vision(msg, me, target);
                
                me->add_temp("str", count * 2); 
                me->add_temp("dex", 0-d_count);
                me->set_temp("liuyun", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

                me->add("neili", -80);
        return 1;
        }
        else{
                msg = HIR "$Nƴ����������ʹ�����������е��ռ�����������ˮ�䡹�� ȫ�����һ����, �������ͬ���ھ�!\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("str", count * 9);
                me->set_temp("liuyun", 1);

                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0:), 2);

                me->add_temp("str",  (count * 29));            
                me->delete_temp("liuyun");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set("neili",0);
                me->add("max_neili",-10);

                msg = HIR "$N�þ������һ������, ���һ����Ѫ, һͷ�Ե��ڵ�!\n" NOR;
                message_vision(msg, me, target);

                me->set("jing",0);
                me->set("qi",0);

                me->unconcious();


                return 1;
        }
}

void remove_effect(object me, int aamount, int damount)
{
        
        if ( (int)me->query_temp("liuyun") ) 
        {
                me->add_temp("str", -aamount);
                me->add_temp("dex", damount);
                me->delete_temp("liuyun");
                tell_object(me, HIY "��ġ�����ˮ�䡹��������ϣ��������ջص��\n" NOR);
                me->start_busy(random(4));
        }
}



