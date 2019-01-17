// jiuyin-zhao.c �����׹�צ

#include <ansi.h>
inherit SKILL;
mapping *action_claw = ({
([ "action" : BLU"$N�����転������аħ��˫צ���ץ�������������󷭴������ּ��죬�����ָץ��$n$l"NOR,
   "force" : 150,
   "damage" : 30,
   "dodge" : 5,
   "lvl" : 0,
   "damage_type" : "ץ��"
]),
([ "action" : BLU"ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n$l������ȥ"NOR,
   "force" : 200,
   "weapon" : "��ָ",
   "damage" : 50,
   "dodge" : 10,
   "lvl" : 10,
   "damage_type" : "����"
]),
([ "action" : BLU"$N�ֱ۹ؽڿ���һ�죬�ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���"NOR,
   "force" : 250,
   "weapon" : "��ָ",
   "damage" : 60,
   "dodge" : 5,
   "lvl" : 20,
   "damage_type" : "����"
]),
([ "action" : BLU"$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�æ��ͻȻ�����צ����ָ�͵ز���"NOR,
   "force" : 300,
   "weapon" : "��צ",
   "damage" : 70,
   "dodge" : 5,
   "lvl" : 30,
   "damage_type" : "����"
]),
([ "action" : BLU"$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l"NOR,
   "force" : 350,
   "weapon" : "�����ָ",
   "damage" : 80,
   "dodge" : 5,
   "lvl" : 40,
   "damage_type" : "����"
]),
});

mapping *action_strike = ({
([ "action" : HIC"$N˫�Ʋ�ס�غ���������ֱ۹ؽڿ������죬����һ��������ž��һ�³�$n$l��ȥ"NOR,
   "force" : 150,
   "dodge" : 15,
   "lvl" : 0,
   "damage_type" : "����"
]),
([ "action" : HIC"$N���δ춯���������������ų�$n�������ƣ�һ�ƿ���һ�ƣ�һ������һ��"NOR,
   "force" : 250,
   "dodge" : 5,
   "lvl" : 10,
   "damage_type" : "����"
]),
([ "action" : HIC"$N���ر�צΪ�ƣ����Ӳ������ұ۶�����Ǳ��������һ�Ƴ�$n$l��ȥ"NOR,
   "force" : 300,
   "weapon" : "��Ե",
   "damage" : 30,
   "dodge" : 5,
   "lvl" : 20,
   "damage_type" : "����"
]),
([ "action" : HIC"$Nһ����Х������Ʈ�磬����������е�ֿ������$n����δ������������Ѹ���Ѽ�"NOR,
   "force" : 350,
   "dodge" : 10,
   "lvl" : 30,
   "damage_type" : "����"
]),
});
int valid_enable(string usage)
{ 
     return usage=="claw" || usage=="parry" 
            || usage=="strike"; 
}

int valid_learn(object me)
{
       if( (int)me->query_skill("jiuyin-zhengong", 1 ) >= 140 )
               return notify_fail("�����ڲ���ѧϰ�����湦��\n");
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("�������湦������֡�\n");
       if ((int)me->query_skill("claw", 1) < 41)
               return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
       if ((int)me->query_skill("strike", 1) < 41)
               return notify_fail("��Ļ����Ʒ���򲻹����޷�ѧϰ��\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������̫�����޷��������湦��\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_claw)-1; i >= 0; i--)
                if(level >= action_claw[i]["lvl"])
                        return action_claw[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("jiuyin-zhengong",1);

        if (me->query_temp("9yin_claw")) {
                me->add_temp("9yin_claw", -1);
                for(i = sizeof(action_claw); i > 0; i--)
                  if(level >= action_claw[i-1]["lvl"])
                    return action_claw[NewRandom(i, 20, level/5)];
        }
        else{
             if(random(5) >= 3)
                me->add_temp("9yin_claw", 1);
             for(i = sizeof(action_strike); i > 0; i--)
               if(level > action_strike[i-1]["lvl"])
                  return action_strike[NewRandom(i, 20, level/5)];      
        }
}

int practice_skill(object me)
{
       object *ob;   
       int i;
       if( me->query("family/master_name") != "������")
               return notify_fail("�����ڲ�����ϰ�����湦��\n");
       if( !present("corpse", me))
               return notify_fail("������û�к��ǣ����ڲ�����ϰ�����湦��\n");
       if( (int)me->query_skill("jiuyin-zhengong", 1 ) >= 140 )
               return notify_fail("�����ڲ�����ϰ�����湦��\n");
       if ((int)me->query("qi") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("������������������湦��\n");

       ob = all_inventory(environment(me));
       for(i=0; i<sizeof(ob); i++) {
       if( !living(ob[i]) || ob[i]==me ) continue;
       message_vision(HIR"$N��������ָ�������еĺ��ǣ��������������ˣ�$N����Ҫɱ����ڡ�\n"NOR, me);
       if( !ob[i]->is_killing(me) )  me->kill_ob(ob[i]);
       }
       me->receive_damage("qi", 30);
       me->add("neili", -10);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyin-zhengong/" + action;
}


void skill_improved(object me)
{
    tell_object(me, "���������ź�Ȼ���ĵ�����һ��а�\n");
    me->add("shen", -(me->query_skill("jiuyin-zhengong", 1)*50));
}
