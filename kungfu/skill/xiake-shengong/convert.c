// heal.c

#include <ansi.h>
#include <cond.h>

int exert(object me, object target)
{
 string *poison;
 int i; 
        if( me->is_fighting() )
            {
              if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(HIR"��ս�����˹������������߻���ħ��\n"NOR);
             }
        if ((int)me->query_skill("xiake-shengong", 1) < 40)
                return notify_fail("��������񹦻�򲻹���\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
            {
              if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
             }
      if(! can_convert(me))
      return notify_fail(HIC"��Ŀǰ���ڲ�û�п���ת����������ҩ��\n"NOR);
      poison=keys(my_cond);
     for(i=0;i<sizeof(poison);i++)
      {
        me->apply_condition(poison[i],0);
        }
      tell_object(me,HIC"�㿪ʼ�˶������񹦻������ڵĶ�ҩ��\n"NOR);
      tell_object(me,HIY"��ҩ��ת��ʱ���������еĶ�ҩ���Զ���������\n"NOR);
    tell_object(me,HIY"��Ҫ�ϳ�ʱ�䣬�����ڼ����㲻��enforce�������\n"NOR);
    tell_object(me,HIY"ͬʱ���뱣֤ ���г���������������������\n"NOR);
    tell_object(me,HIY"�߻���ħ��\n"NOR);
    me->set("jiali",0);
    me->apply_condition("convert",my_cond);  
        return 1;
}
