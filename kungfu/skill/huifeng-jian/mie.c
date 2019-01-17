// mie.c ��

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, int improve);
private void remove_effect(object me, int improve);

int perform(object me)
{
      string msg;    
      object target;                               
      object weapon = me->query_temp("weapon");
      int skill;
      if( !target ) target = offensive_target(me);
     
      if( !target || !target->is_character() ||!me->is_fighting(target) )
      return notify_fail("��ֻ����ս���жԶ���ʹ�á�\n");
             
      if( (int)me->query_skill("huifeng-jian",1) < 90 )
      return notify_fail("��Ļط������������죬����ʹ�𽣣�\n");
      
      if( (int)me->query_skill("linji-zhuang",1) < 90 )
      return notify_fail("����ټ�ʮ��ׯ�ȼ�����������ʹ���𽣣�\n");  
      
      if (!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "huifeng-jian")
      return notify_fail("�������޷�ʹ�á�����˸ա���߷�������\n");
      
      if( (int)me->query_dex() < 25 )
      return notify_fail("����������ߣ�����ʹ���𽣣�\n");
      
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("�������̫��������ʹ���𽣣�\n");
      
      if( (int)me->query("neili") < 350 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó��𽣣�\n");   
                                                                                 
      if( me->query_temp("mie")   )
      return notify_fail("������ʹ���𽣣�\n");
       
      msg = HIY"$N��Хһ���������ڿ����������Ҿ������𽣡��ķ�����ط��������֮�У�
��������������������$n�ۻ����ң������˸����ֲ�����\n" NOR;
      message_vision(msg, me, target);                                                                   

      skill = (int)me->query_skill("huifeng-jian", 1);

      me->add_temp("apply/defense",  skill/10);
      me->add_temp("apply/attack",  -skill/10);
  
      me->start_call_out( (: call_other, this_object(), "check_fight",  me, target, skill :), 1);
      me->add("neili", -200);
      me->set_temp("mie", 1);
      me->start_busy(1);
      return 1;                                                   

}

void check_fight(object me, object target, int improve) 
{ 
        object weapon;                                                                      
             
        if ( me->query_temp("mie") && !me->is_fighting(target))             
        {
                remove_effect(me, improve);
        }
        else if( target->query("qi") <= 50 && me->is_fighting(target) ) 
        {
                remove_effect(me, improve);
        }
        else if( !target->is_fighting() || !me->is_fighting() 
        || !living(me) || target->is_ghost() || me->is_ghost() ) 
        {
                remove_effect(me, improve);
        }
        else if( !objectp(weapon = me->query_temp("weapon")) 
        || me->query_skill_mapped("sword") != "huifeng-jian"
        || (string)weapon->query("skill_type") != "sword" ) 
        {
                remove_effect(me, improve);
        }
        else 
        {
                call_out("check_fight", 1, me, target, improve); 
                return;
        }
        tell_object(me, HIR"���[��]�Ѿ�ʹ�ù��ˡ�\n"NOR); 
}

private void remove_effect(object me, int improve)
{     
      me->delete_temp("mie");
      me->add_temp("apply/defense", -improve/10);                                                        
      me->add_temp("apply/attack", improve/10);
      return 0;
}
