// jing.c ��

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int i, l;
        i = me->query_skill("qiantian-yiyang", 1);   
        l = me->query_skill("buddhism", 1);  
    
        if( !target ) target = me;

        if (me->query("class") != "bonze" )
               return notify_fail("��Ƿ��ŵ��ӣ���ȴ�ȴ󱯸л�����֮�£����ǲ��˽�ġ�\n");
        
        if(me->is_fighting())
              return notify_fail("������ս���У���ο��Ծ���������\n");
        if((int)me->query_skill("qiantian-yiyang",1) < 120 )
              return notify_fail("���Ǭ��һ����������죬�����ĳ�ײʹ�㾲����������\n");
        if( (int)me->query_skill("buddhism",1) < 110 )
              return notify_fail("��ķ�ѧ��Ϊ�������޷�����������\n");
        
        if( (int)me->query("max_neili") < 1200  ) 
                return notify_fail("�������������\n");     
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if((int)target->query_condition("dali_kong") > 0 )
                return notify_fail("����������������֮����\n");
       
        me->add("neili", -1000);

        message_vision(
        HIW "\n$N��Ŀ��ϥ���£�����ĥȥ��������漴��������������$NĿ��������ͣ������˱���֮�⡣\n" NOR, me);

        me->apply_condition("dali_kong", (i + l)/15);  
       
        
        return 1;
}
> cat kong.c
// jing.c ��

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int i, l;
        i = me->query_skill("qiantian-yiyang", 1);   
        l = me->query_skill("buddhism", 1);  
    
        if( !target ) target = me;

        if (me->query("class") != "bonze" )
               return notify_fail("��Ƿ��ŵ��ӣ���ȴ�ȴ󱯸л�����֮�£����ǲ��˽�ġ�\n");
        
        if(me->is_fighting())
              return notify_fail("������ս���У���ο��Ծ���������\n");
        if((int)me->query_skill("qiantian-yiyang",1) < 120 )
              return notify_fail("���Ǭ��һ����������죬�����ĳ�ײʹ�㾲����������\n");
        if( (int)me->query_skill("buddhism",1) < 110 )
              return notify_fail("��ķ�ѧ��Ϊ�������޷�����������\n");
        
        if( (int)me->query("max_neili") < 1200  ) 
                return notify_fail("�������������\n");     
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if((int)target->query_condition("dali_kong") > 0 )
                return notify_fail("����������������֮����\n");
       
        me->add("neili", -1000);

        message_vision(
        HIW "\n$N��Ŀ��ϥ���£�����ĥȥ��������漴��������������$NĿ��������ͣ������˱���֮�⡣\n" NOR, me);

        me->apply_condition("dali_kong", (i + l)/15);  
       
        
        return 1;
}