// xinjing.c �ľ�

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

int exert(object me, object target)
{
        int i, l, skill;
        i = me->query_skill("qiantian-yiyang", 1);   
        l = me->query_skill("buddhism", 1);  
        skill = (i + l)*2;

        if( !target ) target = me;
        
         if(me->is_fighting())
              return notify_fail("������ս���У���ο��Ծ���������\n");
        if(!me->query_skill("qiantian-yiyang",1))
          if((int)me->query_skill("qiantian-yiyang",1) < 60 )
              return notify_fail("����ڹ���������ʵ�������ĳ�ײʹ�㾲����������\n");
        if( (int)me->query_skill("buddhism",1) < 100 )
              return notify_fail("��ķ�ѧ��Ϊ�������޷���������Ǳ�ޣ�\n");
             
        if( (int)me->query("max_neili") < 1100  ) 
                return notify_fail("�������������\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if(me->query_temp("dali_jing"))
                return notify_fail("�����ھ���Ǳ�ޡ�\n");
       
        me->add("neili", -1000);

        message_vision(
        GRN "\n$N��Ŀ��ϥ���£�ֻ�������徲ƽ�ͣ�������������֮����\n" NOR, me);

        me->start_busy(3);
        me->add_temp("apply/intelligence", (int)me->query("int"));
        me->set_temp("dali_jing",1);  
       
        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/intelligence", -(int)me->query("int"));
        me->delete_temp("dali_jing");
        tell_object(me, HIY"�����������������޷�����Ǳ���ˡ�\n"NOR);
}