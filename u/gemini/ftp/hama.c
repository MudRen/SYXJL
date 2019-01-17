#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/hamagong/test.h";


int exert(object me, object target)
{
        int damage, p;
        string msg;

	 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ĸ�󡹦����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("hamagong", 1) < 100 )
                return notify_fail("��ĸ�󡹦����������������ʹ�ø����жԵУ�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á���󡹦����\n");

        if (me->query_skill_mapped("force") != "hamagong")
                return notify_fail("����ڹ����޴˹���\n");
/*
//add by cool
        if (interactive(me)&&(int)me->query_condition("hama_po"))
                 return notify_fail(RED "���������ƣ��޷�ʹ�á���󡡹���С�"NOR);

        if (me->query_skill_prepared("strike") != "hamagong" ||
            me->query_skill_mapped("strike") != "hamagong")
                return notify_fail("������Ƚ���󡹦�������Ʒ�֮�в��С�\n");
*/
        if( (int)me->query("max_neili", 1) < 1500 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

       // if( (int)me->query_skill("strike", 1) < 100 )
         //       return notify_fail("����Ʒ�������죬ʹ������󡹦�ľ��У�\n");

        if (me->query_str() < 30 )
                return notify_fail("�������̫С��ʹ�����ø����У�\n");

        msg = BLU "\n$N���Ӷ��£�����ƽ�ƶ�����ʹ������$N��ƽ�����ġ���󡹦�����У��Ʒ�ֱ��$n��ȥ��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") /3 )
        {                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("qi", -20);
                damage = (int)me->query_skill("hamagong", 1);                
               // damage = damage*2 + random(damage);
                damage = damage + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
        } else 
        {
                me->start_busy(3);
                target->start_busy(1);
                me->add("neili", -100);
    msg += HIY"\n$p����һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg;

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = BLU "\n$N���ƾ���δ��������Ҳ�����Ƴ����������������󡹦���Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hamagong", 1) > 124 )
        {                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -400);
                me->add("qi", -30);                
                damage = (int)me->query_skill("hamagong", 1);                
                //damage = damage*3 + random(damage);
                damage = damage + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);    
        } else 
        {
                me->start_busy(4);
                me->add("neili", -200);
    msg += HIY"\n$p��Ϣδ�����־�һ�ɾ��������������æԾ�����ߣ��Ǳ��رܿ���\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg;
  
        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = BLU "\n$N˫��һ�ǣ�˫���ಢ��ǰ�����Ƴ���$n��ͬ��ǰ��Բ����ȫ�ڡ���󡹦����������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 2 &&
            me->query_skill("hamagong", 1) > 149 )
        {
                me->start_busy(4);
                target->start_busy(random(2));
                me->add("neili", -600);
                me->add("qi", -40);                
                damage = (int)me->query_skill("hamagong", 1);                
                //damage = damage*3 + random(damage);
                damage = damage*2 + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);

                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
                
        } else 
        {
                me->start_busy(5);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("qi", -100);
    msg += HIY"\n$p�þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}


