//guizhen.c  ����һ��
// renee

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
string* xuedao1 = ({
        "С��",
        "�ؿ�",
        "̫��Ѩ",
        "�ұ�",
        "�ҽ�",
        "����",
        "���"
});


int perform(object me, object target)
{
        mapping prepare_status;
        string weapon, op_weapon, op_skill, *pname;
        int my_power, op_power, my_li, op_li, my_jing, my_nei, op_jing, op_nei;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !me->query("wudang/guizhen") )
                return notify_fail("������һ�����ľ����㻹û����ᵽ��\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("�����õĲ���̫���񹦣��޷��˾�ʩչ������һ������\n");

        if( me->query_skill("force") < 200 )
                return notify_fail("���̫���񹦻��δ�����޷��˾�ʩչ������һ������\n");

        if( me->query_skill("sword") < 200 )
                return notify_fail("���̫��������Ϊ���㣬������ʹ�á�����һ������\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("�����������ʹ�á�����һ������\n");
        if( me->query("jing") <= 1000 )
                return notify_fail("��ľ�������ʹ�á�����һ������\n");

        weapon = me->query_temp("weapon");

        if ( !objectp(op_weapon = target->query_temp("weapon")) ) {
                if ( mapp(prepare_status = target->query_skill_prepare()) ) {
                        pname  = keys(prepare_status);
                        op_skill = pname[0];
                }
                else op_skill = "unarmed";
        }
        else {
                op_skill = op_weapon->query("skill_type");
        }

        my_jing = me->query("jing") - 100;
        my_nei = me->query("neili") - 700;

        if ( target->query("neili") < me->query("neili") ) {
                op_nei = target->query("neili")*9/10;
        }
        else op_nei = my_nei;

        if ( target->query("jing") < me->query("jing") ) {
                op_jing = target->query("jing")*9/10;
        }
        else op_jing = my_jing;

        message_vision(HIW "\n$N�Ľ������ڽ��ϣ��׹���磬�����ɱ��Ī��תΪƽƽ���档\n"
                          GRN"$N�Ӷ�"+weapon->name()+"��$n��" + xuedao1[random(7)] + "��ȥ��\n\n" NOR, me, target);
        tell_object(target, HIR "��ֻ���õ��������Ͷ����ף�ѹ����͸����������\n" NOR);

        my_power = me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force")
                   + me->query_skill("parry") + me->query("combat_exp") / 1000;

        op_power = target->query_skill(op_skill) + target->query_skill("dodge") + target->query_skill("force")
                   + target->query_skill("parry") + target->query("combat_exp") / 1000;
                
        my_li = me->query("jing") + me->query("neili");

        op_li = target->query("jing") + target->query("neili");

        if ( random(my_power) > op_power/2 ) {

           if ( random(my_li) > random(op_li) ) {
                if ( objectp(op_weapon) ) {
                        message_vision(HIR "$N���ܲ�����ֻ��ҧ������"+op_weapon->name()+"����ȫ��ǿ�ӹ��ơ�\n" NOR, target);
                        message_vision(HIR "Ӳ��֮�£�"+op_weapon->name()+"����Ϊ���أ������費�˹���һ�����ƣ�\n" NOR, target);
                        op_weapon->unequip();
                        op_weapon->move(environment(me));
                        op_weapon->set("name", "�ϵ���" + op_weapon->name());
                        op_weapon->set("value", 0);
                        op_weapon->set("weapon_prop", 0);
                }
                
                message_vision(HIR "$N���޿ɱܣ�����һ�������ĲҺ� ��\n" NOR, target);
//              weapon->move(target);
                target->receive_wound("qi", target->query("max_qi")*9/10);
//              target->die();
           }
           else if ( me->query_str() > target->query_str() ) {
                if ( objectp(op_weapon) ) {
                        message_vision(HIR "Ӳ��֮�£�"+op_weapon->name()+"����Ϊ���أ���춵����˷ɽ����ƣ�\n" NOR, target);
                        message_vision("����һ���������裬�������䡣$N�䵲��һ����ȴҲ���������Һģ�ҡҡ��׹��\n", target);
//                      weapon->move(environment(me));
                        op_weapon->unequip();
                        op_weapon->move(environment(me));
                        op_weapon->set("name", "�ϵ���" + op_weapon->name());
                        op_weapon->set("value", 0);
                        op_weapon->set("weapon_prop", 0);
                }
                else {
                        message_vision(HIR "$N�������㣬��ȴ���в���������һ�������ĲҺ����н����ˣ�\n" NOR, target);
                        target->receive_wound("qi", target->query("max_qi")*6/9);
                }
           }
           else if ( random(2) == 1 && objectp(op_weapon) ) {
                message_vision(HIR "Ӳ��֮�£�$N��"+weapon->name()+"��$n��"+op_weapon->name()+"˫˫���£�\n" NOR, me, target);
                weapon->move(environment(me));
                op_weapon->move(environment(me));
           }
           else if ( objectp(op_weapon) ) {
                message_vision(HIR "Ӳ��֮�£�$N��"+weapon->name()+"��$n��"+op_weapon->name()+"˫˫��٣�\n" NOR, me, target);
                op_weapon->unequip();
                op_weapon->move(environment(me));
                op_weapon->set("name", "�ϵ���" + op_weapon->name());
                op_weapon->set("value", 0);
                op_weapon->set("weapon_prop", 0);
                weapon->unequip();
                weapon->move(environment(me));
                weapon->set("name", "�ϵ���" + weapon->name());
                weapon->set("value", 0);
                weapon->set("weapon_prop", 0);
           }
           else {
                message_vision(HIR "$N�������㣬��ȴ���в���������һ�������ĲҺ����н����ˣ�\n" NOR, target);
                target->receive_wound("qi", target->query("max_qi")*4/9);
           }

           target->add("jing", -op_jing);
           target->add("neili", -op_nei);
        }
        else {
//              weapon->move(environment(me));  
                message_vision(HIY "$N����������ֻ�ز������ò����׽����бܹ������ŵ�����ֱð��\n" NOR, target);
                message_vision(HIY "һ��δ�У�"+weapon->name()+"�Ľ����ӹ������ڡ�\n" NOR, me);
        }

        me->add("neili", -my_nei);
        me->add("jing", -my_jing);
        target->start_busy(2);
        target->kill_ob(me);
        
        return 1;
}
