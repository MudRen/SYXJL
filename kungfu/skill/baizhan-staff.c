// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// lks
// ����
// ����ɽ�ɵڶ�������
// 2143602
// ����
// staff
// ��ս����





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N���ַ���$w�����һ����������������ڿն�������$nȫ��",
"force" :650,
"dodge" :50,
"parry" :50,
"damage_type": "����",
"damage": 300,
"lvl" : 0,
"skill_name" : "�ǻ���ԭ"
]),
// ZHAOSHI :1

([
"action" :"�������ڴ��У�$w������ʺ�������ڰ��˳���������$Nǰ��Ĳ���,��ΪѸ�����磬\n�ι���������Ŀռ䣬�������Դ���$n��$l��ȥ��",
"force" :680,
"dodge" :80,
"parry" :80,
"damage": 400,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "Ѹ������"
]),
// ZHAOSHI :2

([
"action" :"$N���е�$w��������ҽǣ�ȥ�����Σ���⼱������������,���羪�κ��˰����$n��$l��ȥ��",
"force" :700,
"dodge" :100,
"parry" :100,
"damage_type": "����",
"damage": 500,
"lvl" : 20,
"skill_name" : "���κ���"
]),
// ZHAOSHI :3

([
"action" :"$N������ǣ���������ҽ��£�һ����Х��ͦ����ȥ��ɭɭ���ˣ����ų�ǰ�Ĳ��ƣ�\n���ֶ��������ֺ��˵ĸо�������̩ɽ������$n����������ʹ���������������ĸо���",
"force" :730,
"dodge" :150,
"parry" :150,
"damage_type": "����",
"damage": 400,
"lvl" : 30,
"skill_name" : "�������"
]),
// ZHAOSHI :4

([
"action" :"$Nգ���۵Ĺ�����$n�����Ƕȵ������׵ľŵ������ϲ����Ļ���һ����â�⣬����$n��$l��",
"force" :760,
"dodge" :200,
"parry" :200,
"damage_type": "����",
"damage": 400,
"lvl" : 40,
"skill_name" : "��ת����"
]),
// ZHAOSHI :5

([
"action" :"$N��$w�ɼ��ϵ�����Ȼ������̫���ˣ������͵ؼ��٣���׾ʵ��,����$n�ı����㡣",
"force" :1000,
"dodge" :300,
"parry" :300,
"damage": 500,
"damage_type": "����",
"lvl" : 50,
"skill_name" : "��׾ʵ��"
]),

([
"action":"$Nһ�����죬�����Ҳ�б��һ����Ť��$w���б��������$n����������֮��--$l��",
"force":1100,
"dodge":350,
"parry":350,
"damage":600,
"damage_type": "����",
"lvl" : 60,
"skill_name" : "б��ϸ��"
]),

([
"action":"$N̤ǰ�벽��һ����ȣ��ٵ�б��$n��$l��������Х�������̶���\n������ǧ��˺ɱ��ս��֮�ϡ�",
"force":1100,
"dodge":350,
"parry":350,
"damage":600,
"damage_type": "����",
"lvl" : 70,
"skill_name" : "����ǧ��"
]),

([
"action":"$N������ǰ�����˴���$w��$nײȥ��������Ӱէ���ַ֣�ֻ��$N��$w�ؿ����ϣ�\n����¶�����޵İ�Թ��",
"force":1200,
"dodge":400,
"parry":400,
"damage":800,
"damage_type": "����",
"lvl" : 80,
"skill_name" : "��Ȼ����"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��ս����"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "staff" || usage=="parry" || usage=="blade"; }
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
    level = (int)me->query_skill("baizhan-staff",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
       me->receive_damage("qi", 5);
	return 1;
} //total 34 lines!
