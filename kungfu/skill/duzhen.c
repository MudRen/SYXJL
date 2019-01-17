#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);

mapping *action = ({
  ([
    "action":
"$N��Ȼ������Х����Ծ�ڿգ�$w�ѵ�$n��磬�ۿ���Ҫ�Դ�������\n"
"���С������ʯ����Ȼ�д�ʯ֮��",
    "force":       250,
    "damage":      25,
    "dodge":      -20,
    "parry":       10,
    "damage_type": "����",
    "post_action": (: throw_weapon :),
    "name":        "��������",
    ]),
  ([
    "action":
"$N�ֽ����󣬸���һ�С����ĸ�������$w�Ѵ���Х����$nǰ�ط�ȥ",
    "force":    300,
    "damage":   35,
    "dodge":    20,
    "parry":    20,
    "damage_type": "����",
    "post_action":      (: throw_weapon :),
    "name":             "���ĸ���",
    ]),
  ([
    "action":
"ͻȻ�䣬$N�����������ȥ������$n����֮�⡣\n"
"$n����׷����$N��Ȼת����һ�����ٲ������\n"
"$w�Ѵ����ƿ�֮����ֱ��$n����",
    "force":       350,
    "damage":       20,
    "dodge":       -10,
    "parry":       -10,
    "damage_type": "����",
    "post_action":      (: throw_weapon :),
    "name":             "�ٲ�����",
    ]),
  ([
    "action":
"$N��׼$n��������һ����$n�������ܣ�ͻȻ���ֲ�����������������޴���ȥʱ��\n"
"$N���쳤̾��ֻ��һ֧$w��$n��$l���ɶ���",
    "force":    400,
    "damage":   25,
    "dodge":    -20,
    "parry":    10,
    "damage_type": "����",
    "post_action":      (: throw_weapon :),
    "name":             "��������",
    ]),
  ([
    "action":
"$N��ָ΢����$nֻ������ಡ���һ����$w�ѵ�$lǰ���硣\n"
"$nû�ŵ����С��������ա��������֮�죬���������޴�",
    "force":    450,
    "damage":   35,
    "dodge":    10,
    "parry":    -10,
    "damage_type": "����",
    "post_action":      (: throw_weapon :),
    "name":             "��������",
    ]),
  ([
    "action":
"$N��վ�ȣ�����͸����$w��һ�����$n��$l",
    "force":    500,
    "damage":   40,
    "dodge":    20,
    "parry":    20,
    "damage_type": "����",
    "post_action":      (: throw_weapon :),
    "name":             "���Ǹ���",
    ]),
  ([
    "action":
"$n��������������һ����$N������Ҫ���ܣ�ͻȻŤ������\n"
"һ�С�Ϭţ���¡�������$w��ͬ����һ�㣬ֱ����$n��$l",
    "force":        680,
    "damage":       30,
    "dodge":       -10,
    "parry":       -10,
    "damage_type": "����",
    "post_action":  (: throw_weapon :),
    "name":         "Ϭţ����",
    ]),
});
 
int valid_learn(object me)
{
  object ob;
  
  if(me->query_skill("throwing",1) < 20)
    return notify_fail("�������������ʵ�������ڼ�ս����У�\n");
  if( (int)me->query("max_neili") < 50 )
    return notify_fail("�������������������ϰ��\n");
  if( !(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "throwing" )
    return notify_fail("����û���������������ʦ�����̣�\n");
  return 1;
}

mapping query_action(object me)
{
  int max=me->query_skill("throwing") / 3;
  
  if (max>sizeof(action)) max=sizeof(action);
  return action[random(max)];
}

string learning_message(int level)
{
  if (level / 3 >= sizeof(action) ) return "";
  else return "�ԡ�" + action[level/3]["name"] + "��������������";
}

int valid_enable(string usage)
{
  return (usage=="throwing");
}

int practice_skill(object me)
{
  object weapon;

  if( !objectp(weapon = me->query_temp("weapon"))
     ||      (string)weapon->query("skill_type") != "throwing" )
    return notify_fail("û������������׼ͷ��\n");

  if( (int)me->query("qi") < 40 || (int)me->query("neili") < 10)
    return notify_fail("����������㣡\n");
  me->receive_damage("qi", 30);
  me->add("neili", -15);
  return 1;
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
  if( objectp(weapon) ) {
    if( (int)weapon->query_amount()==1 ) {
      weapon->unequip();
      tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n");
    }
    weapon->add_amount(-1);
  }
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
            if( random(me->query_skill("yunu-xinjing")) > 15) {
                    victim->apply_condition("bing_poison", random(2) + 1 +
                           victim->query_condition("bing_poison"));
            }
}
