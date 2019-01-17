// yijin-jing ��Ħ�׽

inherit FORCE;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
#include "/kungfu/skill/force.h"

int valid_enable(string usage)
{
    if((int)this_player()->query_skill("yijin-jing", 1) < 199)
         return usage == "force";
    else return (usage == "force") || (usage == "parry");
}

int valid_learn(object me)
{
        int i, nb, nh;
        nb = (int)me->query_skill("buddhism", 1);
        nh = (int)me->query_skill("yijin-jing", 1);

        if ( me->query("gender") != "����" )
                return notify_fail("���ͯ��֮�壬������ϰ�׽�ڹ���\n");

        if ((int)me->query_skill("buddhism", 1) < 100 && nb <= nh )
                return notify_fail("��������ķ���Ϊ�������޷�����������׽�ڹ���\n");

        if ((int)me->query_skill("force", 1) < 15)
                return notify_fail("��Ļ����ڹ���򻹲������޷�����׽�ڹ���\n");

        if ((int)me->query("guilty") > 0 )
                return notify_fail("���ŷ�ɮ�����䣬�޷�����������׽�ڹ���\n");

        return valid_public(me);
}


int practice_skill(object me)
{
        return notify_fail("�׽�ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"yijin-jing/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"���Ϻ�����֣�����ׯ��" NOR,
    "start_my_msg" : "���������죬�ų�һ�������Ϣ˳��������������\n",
    "start_other_msg" : me->name()+"�������죬һ�Ṥ�򣬴ӿڱǴ������³�����������Խ��ԽŨ������������ȫ��\n",
    "halt_msg" : "$N����һ����������Ϣ�������˻�ȥ��վ��������\n",
    "end_my_msg" : "�㽫��Ϣ���˸�С���죬���ص���չ�վ��������\n",
    "end_other_msg" : "ֻ������"+me->name()+"�İ���������ɢ���ִӿڱǴ����˻�ȥ��\n"
    ]);
}

string *fanzhen_msg = ({
"ֻ���$n���ڸ��У���������һ�뷭ת��\n",
"���ȷ��𣬽�$n��������ֽ��ȫ��Ѫɫ��\n",
"���$n�ķ����ѣ�����������������\n",
"�����Ѳ���ȫ����$n�����������ȥ��\n",
"���$n������ת�������������߰˲���\n",
"��$nһײ��ֻ���$p�ؿ���Ѫ��ӿ��\n",
"$n����ײ��һ���޻����棬����Ϊ��ĺ�ǽ��һ�㣬����������\n",
"$n������$P��ͻȻ����һ�𣬵�ʱ���˳�ȥ��\n",
});

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int p, skill, neili, neili1,  i;
        object weapon;
        skill = me->query_skill("yijin-jing", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

        if(living(me) /*&&
           me->query_temp("fanzhen") &&
           random(skill)+30 > ob->query_skill("parry", 1)/2 &&
           me->query("combat_exp") > ob->query("combat_exp")/2 &&
           skill > 199 &&
           neili > 500 &&
           living(ob) &&
           ob->query("jiali") &&
           !ob->query("env/invisibility")*/)
        {
                if(!objectp(weapon = ob->query_temp("weapon")))
                {
                         me->add("neili", -(10+random(70)));
                         msg = random(2)?HIR"$N��������һ�ɷ���֮����":HIR"$N���Ͻ�ղ����������Ķ���";

                         if(neili1 > neili*3 || damage > 3000)
                         {
                             msg += "��ȴ��$n�ľ���һ�����飡\n"NOR;
                             me->delete_temp("fanzhen");
                             damage = random(damage);
                             printf("damage = %d\n", damage);
                         }
                         else if(neili1 > neili*2) msg += "��ȴ�����޷��赲$n�ľ�����\n"NOR;
                         else if(neili1 > neili)
                         {
                                msg += "��������˲���$n�ľ�����\n"NOR;
                                damage = -damage/2;
                         }
                        else
                        {
                                 msg += fanzhen_msg[random(sizeof(fanzhen_msg))]+NOR;
                                 if(neili > neili1*4) i = 4;
                                 else if(neili > neili1*3) i = 3;
                                 else if(neili > neili1*2) i = 2;
                                 else i = 1;
                                 i *= damage/2;
                                 if(ob->query_skill("force") > me->query_skill("force")) i = i*2/3;
                                 if(i < 10) i = 10;
                                 ob->receive_damage("qi", i, me);
                                 ob->receive_wound("qi", i/5);
                                 p = ob->query("qi")*100/ob->query("max_qi");
                                 msg += "( $n"+eff_status_msg(p)+" )\n";
                                 if(wizardp(me)) tell_object(me, "Fanzhen damage: "+i+"��\n");
                                 damage = -damage;
                         }
                         message_vision(msg, me, ob);
                         return damage;
                 }
                 else
                 {
                         msg = HIR"������һ�����ε�ǽ��$N��ǰ�赲�ţ�";
                         if(neili > neili1*3)
                         {
                                 msg += "���$n"HIR"һ���ӱ����������"+ob->name()+HIR"�ֱ۷��飡\n"NOR;
                                 ob->start_busy(1+random(3));
                                 damage = -damage*5;
                         }
                         else if(neili > neili1*2)
                         {
                                 msg += "���$n"HIR"����ǰ��һ˿һ����\n"NOR;
                                 printf("damage = %d\n", -damage);
                                 damage = -damage*4;
                         }
                         else if(neili > neili1)
                         {
                                 msg += "���������$n"HIR"ǰ�����ٶȣ�\n"NOR;
                                 damage = -damage/2;
                         }
                         else if(neili*2 > neili1)
                         {
                                 msg += "����û����ʲô���ã�\n"NOR;
                                 damage = 0;
                         }
                         else
                         {
                                 msg += "��ȴ��$n"HIR"һ�´��ƣ�\n"NOR;
                                 me->delete_temp("fanzhen");
                                 damage = -weapon->query("weapon_prop/damage");
                         }
                         if(wizardp(me)) tell_object(me, "Fanzhen damage: "+i+"��\n");
                         damage = -damage;
                         message_vision(msg, me, weapon);
                         return damage;
                }
        }
}
