// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// zqsh
// ��ˮ��
// [1;36m��һ�ٶ�ʮ�ߴ���������[2;37;0m
// 3134570
// ����
// sword
// ��ˮ����





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N������һ��������΢ǰ�㣬һʽ������֮ˮ������㺮������$n��$n�ٸик������ˣ���������žŰ�ʮһ�����硣",
"force" :50,
"dodge" :20,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����֮ˮ"
]),
// ZHAOSHI :1

([
"action" :"$NͻȻ����ˣ�������н���һʽ����ˮ֮������$n�پ���׹���ߣ�����$N�˵Ŀ죬��Ȼ���ٺ٣���������",
"force" :80,
"dodge" :10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "��ˮ֮��"
]),
// ZHAOSHI :2

([
"action" :"$Nһʽ�����컨�꡹��Ծ�����࣬���н������ӳ���������������������$n",
"force" :100,
"dodge" :10,
"damage_type": "����",
"lvl" : 20,
"skill_name" : "���컨��"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��ˮ����"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("hanshui-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
