//amber 1999.10.18
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if (me->query_temp("jinshe/tuwu"))
                return notify_fail("����õĽ�������û�����žͳ��С�\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe zhui")
           return notify_fail("��û�ý���׶������ʹ�þ��У�\n");
//        if( target->is_busy() )
//                return notify_fail(target->name() + "�Ѿ���������ס�ˣ��㻹��ʲô�����붾�Լ�������\n");   
        if( (int)me->query_skill("jinshe-zhuifa", 1) < 150 )
                return notify_fail("��Ľ���׶��������죬����ʹ�ý�������\n");
//        if( (int)me->query_skill("jinshe-jianfa",1) < 150)        
//                return notify_fail("��Ľ��߽���������죬����ʹ�ý�������\n");
        if( (int)me->query_skill("dodge") <150)
                return notify_fail("����Ṧ��Ϊ������ʹ������������\n");
        if( (int)me->query_skill("throwing") <150)
                return notify_fail("��Ļ�������û������ô�ܷ���������������\n");
        if((int)me->query_dex() < 30)
                return notify_fail("������ô���ȥ�İ����ܴ������𣡣��� \n");
        if((int)me->query_skill("force") < 150)
                return notify_fail("�������ڵ��ڹ���Ϊ����ȥ�İ����������ˣ����� \n");        
        if( (int)me->query_str() < 30 )
                return notify_fail("�����ô�����������İ���Ҳ�����ˣ�����\n");                
        if( (int)me->query("jing") <50)
                return notify_fail("�㾫�������ˡ�\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("�����������ˡ�\n");   
                   
        message_vision(HIG"ֻ��һ����ɨҶ���������,$N���е�"HIY"����׶"HIG"������Ŀ�Ĺ�â����ҫ��$n��ð��
        ����\n" NOR,me,target);
        
        if( random( (int)me->query_skill("jinshe-zhuifa",1))
          > random(target->query_skill("dodge")*2/3 ) ) 
          {
        msg = WHT"������������������"HIG"������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR,me, target;
        skill = me->query_skill("jinshe-zhuifa", 1);

        me->add("jing",-30);
        me->add("neili", -300);
        target->receive_damage("qi", (int)skill* 3);
        target->receive_damage("jing",(int)skill/ 3);
        target->receive_wound("jing",(int)skill/ 4);
        target->receive_wound("qi",(int)skill* 2);
        me->set_temp("jinshe/tuwu", 1);
        target->set_temp("block_msg/all",1);
        call_out("tuwu_end", (int) skill/20, me, target);
        me->start_busy(random(2));
        target->start_busy( (int)me->query_skill("jinshe-zhuifa",1) / 40 ) + random( (int)me->query_skill("jinshe-zhuifa",1) / 100 );


        } else {
                msg = HIW"����$p�����������ͼ����������˫�������һ���ڼ�������ɢ��Ũ�����˿�ȥ��\n" NOR;
                me->start_busy((2)+random(2));
                me->add("jing",-10);
                me->add("neili",-100);
        }
        message_vision(msg, me, target);
        return 1;
        }
void tuwu_end(object me, object target)
{
        target->enable_player();
        message_vision("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n" NOR, target);
        target->set_temp("block_msg/all", 0);
        write(HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
        me->delete_temp("jinshe/tuwu");

        return;
}

