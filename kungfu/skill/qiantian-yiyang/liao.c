#include <ansi.h>

int exert(object me, object target)
{
// add by cool for need  meet һ��     
        if(!me->query("yd_1",1)) return 0;
        if( !target )
                return notify_fail("��Ҫ��һ��ָΪ˭���ˣ�\n");
        if(target == me)
                return notify_fail("��Ҫ��һ��ָΪ˭���ˣ�\n");

        if(!me->query_skill("kurong-changong",1))
           if((int)me->query_skill("qiantian-yiyang",1) < 120 )
              return notify_fail("���Ǭ��һ����������죬�޷��������ˣ�\n");
        if((int)me->query_skill("yiyang-zhi",1) < 120 )
              return notify_fail("���һ��ָ�񹦲�����죬�޷��������ˣ�\n");
        if (me->query_skill_prepared("finger") != "yiyang-zhi"
        || me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("�������޷�ʹ��һ��ָ�������ˣ�\n");      

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷����ˣ�\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("neili") < 1200 )
                return notify_fail("�������������\n");

        if( (int)target->query("eff_jing") >= (int)target->query("max_jing") )
                return notify_fail( target->name() + "��û�����ˣ�\n");
       
        message_vision(
                HIY "\n$N�������ʳָ��΢һ�����������$n���Եķ縮Ѩ�ϣ�һ��ָ��ԴԴ͸�롣����\n\n"
                HIW"���˲��ã�$Nͷ��ð��˿˿�����������������죬������������$n����ѭ������������һյ��ʱ�֣��ŷſ���ָ��
ֻ��Ƭ��֮�䣬$n˫�ձ����˺��Σ���ɫ������Ҳ�ö��ˡ�\n" NOR,
                me, target );

        target->set("eff_jing", (int)target->query("max_jing"));
        target->clear_condition();
        me->set("neili", 0);
        me->add("max_neili", - (5 + random(5)));
    
        return 1;
}
