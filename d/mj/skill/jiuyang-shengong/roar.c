// roar.c ����ʨ�Ӻ�

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if ( !wizardp(this_player()) && (me->query("family/family_name") != "������"))
                return notify_fail("�㲻�����ֵ��Ӳ���ʹ�þ�����.\n
                                    �����񹦲�����, �����ֵ��Ӳ���, �治֪��������ôѧ���!\n
                                    ����, ����, �����ڵ��з����Ƿ���Ҫ�ٺú�ѧһѧ.\n");

        if( ((int)me->query("neili") < 600 ) || ( (int)me->query_skill("jiuyang-shengong") < 20) )
                return notify_fail("���������\"��\"�ĺ���һ��, ��������˼�ֻ����\n");


        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 10);

        me->start_busy(1);
        message_vision(
                HIY "$N�������һ�����������ŷ�������һ�����춯�صľ޺�\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
                
                damage = skill * 3 - ((int)ob[i]->query("max_neili") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage * 2 );
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage);
                        tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
                }
                if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
        }

        return 1;
}
