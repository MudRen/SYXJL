// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tony
// ����
// ��ң�ɵ��Ĵ�����
// 15500583
// ����
// unarmed
// �����󱯸�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N���鱯�ߣ��ι���,һʽ���޷����졹��˫�ִ���������ɫ��������$n��ȫ����ȥ",
"force" :50,
"dodge" :10,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "�޷�����"
]),
// ZHAOSHI :1

([
"action" :"$N������𣬼��������ɳ��һʽ��ħ���콵�����ڿ�����$n���������ɫ����.",
"force" :80,
"dodge" :-10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "ħ���콵"
]),
// ZHAOSHI :2

([
"action" :"$N�û���ʮ������Ӱ,�������ϣ�һʽ��ħӰ�㿡����ֱ�����$n��ʮ�˵���Ѩ .",
"force" :100,
"dodge" :-20,
"damage_type": "����",
"lvl" : 20,
"skill_name" : "ħӰ��"
]),
// ZHAOSHI :3

([
"action" :"$N˫��һ�ţ��ֺ�һ����һʽ������ħ�硹����ʱ���ذ���������ʯ����������Ѹ��������$n.",
"force" :130,
"dodge" :-30,
"damage_type": "����",
"lvl" : 30,
"skill_name" : "����ħ��"
]),
// ZHAOSHI :4

([
"action" :"$N����ȫ��������������ԩ�꣬ʹ�����һʽ�������ɢ����˫�������д�����ԩ��ҹ����$nǰ��������",
"force" :150,
"dodge" :-50,
"damage_type": "����",
"lvl" : 40,
"skill_name" : "�����ɢ"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"�����󱯸�"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�����󱯸�"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("dabeifu-unarmed",1);
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
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
