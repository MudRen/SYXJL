// chousui-zhang.c, ������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�߶�����������Ӷ���˫��Ю��һ���ȳ�֮������$n��$l",
        "dodge": 30,
        "force": 160,
        "lvl" : 0,
        "poison": 80,
        "damage_type": "����"
]),

([  "action": "$N������ת����, ͻȻ��˫�Ʒ���������$n��$l",
        "dodge": 30,
        "force": 160,
        "lvl" : 29,
        "poison": 60,
        "damage_type": "����"
]),

([      "action": "$N������ȣ�������ʢ��˫�Ƽ仯��һ������Ļ���, ����$n��$l",
        "dodge": 10,
        "force": 160,
        "lvl" : 59,
        "poison": 40,
        "damage_type": "����"
]),

([  "action": "$N¶�������Ц�ݣ�һ�������ޱȵġ���ʬ����ץ��$n��$l",
        "dodge": 10,
        "force": 160,
        "lvl" : 99,
        "poison": 80,
        "damage_type": "����"
]),

([  "action": "$N����һת������������һ�С����鸯ʬ���������ץ��$n��$l",
        "dodge": -10,
        "force": 200,
        "lvl" : 119,
        "poison": 100,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        if (random(me->query_skill("strike")) > 120 &&
            me->query_skill("force") > 120 &&
            me->query("neili") > 2000 ) {
                me->add("neili", -200);
                return ([
                "action": HIR "$N��ҧ��⣬��Ѫ����, ���������ݰ���ת��ʮ���Ȧ�ӣ�ͻȻ��ۼ�ȫ�����������$n��"NOR,
                "force": 500,
                "damage_type": "����"]);
        }

        level   = (int) me->query_skill("chousui-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����ֲ����������ơ�\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
        return notify_fail("�㻹�������û����󷨰ɡ�\n");
        if ((int)me->query("max_neili") < 100)
        return notify_fail("����������̫��, �����˳����ơ�\n");
        return 1;
}

int practice_skill(object me)
{
        int lvl = me->query_skill("chousui-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jingli") < 40)
        return notify_fail("����Ъ���������ɡ�\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("��û���㹻�������������ơ�\n");

        if ((int)me->query("combat_exp") >= 300000 && (int)me->query("max_neili") >= 2000 && (int)me->query_skill("chousui-zhang", 1) >= 120) {
              me->receive_damage("jingli", 40);
              me->add("neili", -15);
              return 1;}

        if ((int)me->query("combat_exp") >= 200000 && (int)me->query("max_neili") >= 1600 && (int)me->query_skill("chousui-zhang", 1) >= 100 && (int)me->query_skill("chousui-zhang", 1) < 120) {
              me->receive_damage("jingli", 35);
              me->add("neili", -10);
              return 1;}

        if ((int)me->query("combat_exp") >= 100000 && (int)me->query("max_neili") >= 800 && (int)me->query_skill("chousui-zhang", 1) >= 80 && (int)me->query_skill("chousui-zhang", 1) < 100) {
              me->receive_damage("jingli", 30);
              me->add("neili", -10);
              return 1;}

        if ((int)me->query("combat_exp") >= 10000 && (int)me->query("max_neili") >= 400 && (int)me->query_skill("chousui-zhang", 1) >= 30 && (int)me->query_skill("chousui-zhang", 1) < 80) {
              me->receive_damage("jingli", 25);
              me->add("neili", -5);
              return 1;}

        if ((int)me->query("combat_exp") >= 3000 && (int)me->query("max_neili") >= 200 && (int)me->query_skill("chousui-zhang", 1) >= 1 && (int)me->query_skill("chousui-zhang", 1) < 30) {
              me->receive_damage("jingli", 20);
              me->add("neili", -5);
              return 1;}

        return notify_fail("��������ϰ�����ƣ����ǲ�û���κν�����\n");
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
                //if( random(me->query_skill("huagong-dafa")) > (damage_bonus + foo)/3 )
        if(random(me->query_skill("huagong-dafa")) > 30 &&
            me->query_skill("poison") > 50) {
                //victim->receive_wound("qi", (damage_bonus + foo));
                victim->apply_condition("xx_poison", random(2) + 2 +
                        victim->query_condition("xx_poison"));
        }
}