//jueqing-chenfa.c  ���鳾��
// csy 1999.05.29
inherit SKILL;
mapping *action =
({
([
"action" : "ֻ��$N������ת������ᶶ��һʽ�����˫�ɡ���$w�����ϻ��������ɺ�",
"dodge"  : 50,
"damage" : 40,
"parry"  : 15,
"lvl"         : 0,
"skill_name"  : "���˫��",
"damage_type" : "����",
]),
([
"action" : 
"$NĬ�˱��ľ���ʹ�������غ����һ�ƺ�����ȵ�������$w�����������͸$n�������",
"dodge"  : 40,
"damage" : 50,
"parry"  : 25,
"lvl"         : 10,
"skill_name"  : "���غ���",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ����Ӧ�������ɫ����Ȼ��$wбб�����$n����һ�ݣ�ֻ������Ŀ��������ʶ��ȴ��˵������",
"dodge"  : 55,
"damage" : 60,
"parry"  : 25,
"lvl"         : 20,
"skill_name"  : "��Ӧ����",
"damage_type" : "����",
]),
([
"action" : 
"$Nϼ����������������������$w��Ӱ���Σ�һ�С�ֻӰ��˭�����������������ýò�Ⱥ",
"dodge"  : 30,
"damage" : 70,
"parry"  : 10,
"lvl"         : 30,
"skill_name"  : "ֻӰ��˭",
"damage_type" : "����",
]),
([
"action" : 
"$N�����趯$w��ȴ��һ�С�������ơ���ֻ���ж�������������ת��һ��δ������������������",
"dodge"  : 40,
"damage" : 80,
"parry"  : 20,
"lvl"         : 40,
"skill_name"  : "�������",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ��ǧɽĺѩ����$w�������磬��ʱ���ѩ�׷ף����������������滨�����ܹ�ס$nȫ��"
,
"dodge"  : 10,
"damage" : 90,
"parry"  : 30,
"lvl"         : 50,
"skill_name"  : "ǧɽĺѩ",
"damage_type" : "����",
]),
([
"action" : 
"ֻ��$Nһ·����į��ġ���$w�ط���ѩ��������������˿��֮�������������ĳ��������ʱ����ʤ����",
"dodge"  : 10,
"damage" : 100,
"parry"  : 10,
"lvl"         : 60,
"skill_name"  : "��į���",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ������ƽ����������$w���²������·�һ�����̱���Ʈ��$n��ͷ���������룬�����ƻã������������֮��",
"dodge"  : 20,
"damage" : 110,
"parry"  : 0,
"lvl"         : 70,
"skill_name"  : "����ƽ��",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ����߳��$w���ھ���ע����ز���裬һ·��ݺ�����������֮����Ӣ�ͷף�������ϣ�����ֻ�ε�$n������ʹ",
"dodge"  : 30,
"damage" : 120,
"parry"  : 10,
"lvl"         : 80,
"skill_name"  : "ݺ�����",
"damage_type" : "����",
]),
([
"action" : 
"��Ȼ��$N���ƶ��䣬$w���ٴ죬���ⰻȻ��һʽ��ǧ����š�����֮�����֮�����ǧ�����໯����һ��֮��",
"dodge"  : 10,
"damage" : 130,
"parry"  : 0,
"lvl"         : 90,
"skill_name"  : "ǧ�����",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ�����Ǻ����������繲��࣬�������ߣ�����˫˿��������ǧǧ�ᣬֱ��$n��֮���ϣ���֮����",
"dodge"  : 30,
"damage" : 140,
"parry"  : 10,
"lvl"         : 100,
"skill_name"  : "���Ǻ���",
"damage_type" : "����",
]),
([
"action" : 
"$N����ʱ���������죬���䴦������ϼǧ�ƣ�һʽ�������������˺�һ������������ȫȻ����$n����",
"dodge"  : 20,
"damage" : 150,
"parry"  : 10,
"lvl"         : 110,
"skill_name"  : "��������",
"damage_type" : "����",
]),
});

/*
mapping *action_male =
({
([
"action" : "ֻ��$N���μ�ת�������ᶶ��һʽ�����˫�ɡ���$w�����ϻ��������ɺ�",
"dodge"  : 20,
"damage" : 20,
"force"  : 125,
"lvl"         : 0,
"skill_name"  : "���˫��",
"damage_type" : "����",
]),
([
"action" : 
"$NĬ�˱��ľ���ʹ�������غ����һ�ƺ�����ȵ�������$w�����������͸$n�������",
"dodge"  : 20,
"damage" : 30,
"force"  : 150,
"skill_name" : "���غ���",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ����Ӧ�������ɫ����Ȼ��$wбб�ӳ���$n����һ�ݣ�ֻ������Ŀ��������ʶ��ȴ�
�˵������",
"dodge"  : 25,
"damage" : 40,
"force"  : 175,
"lvl"         : 20,
"skill_name"  : "��Ӧ����",
"damage_type" : "����",
]),
([
"action" : 
"$N������������������������$w��Ӱ���Σ�һ�С�ֻӰ��˭�����������������ýò�Ⱥ",
"dodge"  : 25,
"damage" : 50,
"force"  : 200,
"lvl"         : 30,
"skill_name"  : "ֻӰ��˭",
"damage_type" : "����",
]),
([
"action" : 
"$N�����趯$w��ȴ��һ�С�������ơ���ֻ���ж�������������ת��һ��δ���������������
���",
"dodge"  : 30,
"damage" : 60,
"force"  : 225,
"lvl"         : 40,
"skill_name"  : "�������",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ��ǧɽĺѩ����$w�������磬��ʱ���ѩ�׷ף����������������滨�����ܹ�ס$nȫ��"
,
"dodge"  : 30,
"damage" : 70,
"force"  : 250,
"lvl"         : 50,
"skill_name"  : "ǧɽĺѩ",
"damage_type" : "����",
]),
([
"action" : 
"ֻ��$Nһ·����į��ġ���$w�ط���ѩ��������������˿��֮�������������ĳ���������
�����ʤ����",
"dodge"  : 35,
"damage" : 80,
"force"  : 275,
"lvl"         : 60,
"skill_name"  : "��į���",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ������ƽ����������$w���²������·�һ�����̱���Ʈ��$n��ͷ���������룬�����ƻã
������������֮��",
"dodge"  : 35,
"damage" : 80,
"force"  : 300,
"lvl"         : 70,
"skill_name"  : "����ƽ��",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ����Х��$w���ھ���ע����ز���裬һ·��ݺ�����������֮����Ӣ�ͷף�������ϣ����
�ֻ�ε�$n������ʹ",
"dodge"  : 40,
"damage" : 90,
"force"  : 325,
"lvl"         : 80,
"skill_name"  : "ݺ�����",
"damage_type" : "����",
]),
([
"action" : 
"��Ȼ��$N���ƶ��䣬$w���ٴ죬���ⰻȻ��һʽ��ǧ����š�����֮�����֮�����ǧ�
����໯����һ��֮��",
"dodge"  : 40,
"damage" : 90,
"force"  : 350,
"lvl"         : 90,
"skill_name"  : "ǧ�����",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ�����Ǻ����������繲��࣬�������ߣ�����˫˿��������ǧǧ�ᣬֱ��$n��֮���ϣ
���֮����",
"dodge"  : 45,
"damage" : 100,
"force"  : 375,
"lvl"         : 100,
"skill_name"  : "���Ǻ���",
"damage_type" : "����",
]),
([
"action" : 
"$N����ʱ���������죬���䴦������ϼǧ�ƣ�һʽ�������������˺�һ������������ȫȻ�
���$n����",
"dodge"  : 45,
"damage" : 100,
"force"  : 400,
"lvl"         : 110,
"skill_name"  : "��������",
"damage_type" : "����",
]),
});
*/
mapping *action_sanshou =
({
([
"action" : 
"��һ�С��޿ײ��롹�����������ȫ�������Ѩ������$nֻ�������ϮϮ������ٺ�����$w���
���",
"dodge"  : 30,
"damage" : 160,
"force"  : 350,
"lvl"         : 100,
"skill_name"  : "�޿ײ���",
"damage_type" : "����",
]),
([
"action" : 
"������$Nʹ������������������Ϊһ�У���ʵǧͷ������$wͬʱ����$n�����ƫ��Ѩ��",
"dodge"  : 30,
"damage" : 170,
"force"  : 375,
"lvl"         : 100,
"skill_name"  : "��������",
"damage_type" : "����",
]),
([
"action" : 
"�����С�������Ϊ�������ٵ�Ѩ����ר��$n�۾����ʺ�С�����������������֮���������ޱ
�",
"dodge"  : 30,
"damage" : 180,
"force"  : 400,
"lvl"         : 100,
"skill_name"  : "������Ϊ",
"damage_type" : "����",
]),
});

int valid_enable(string usage) {
    return usage == "whip" || usage == "parry";
}

int valid_learn(object me) {
    if ((int)me->query_skill("force",1) < 150 )
        return notify_fail("����ڹ��ķ���Ϊ��ǳ��û��ѧ���鳾����\n");
    if ((int)me->query_skill("dodge", 1) < 150)
        return notify_fail("����Ṧ��Ϊ��ǳ��û��ѧ���鳾����\n");
    return 1;
}

string query_skill_name(int level) {
    int i;
    for (i=sizeof(action)-1; i>=0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}


mapping query_action(object me, object weapon) 
{

    int level = (int)(me->query_skill("jueqing-chenfa", 1));
    int i;
    for (i=sizeof(action); i>=1; i--)
        if (level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
        return action[random(sizeof(action))];

}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "whip")
        return notify_fail("�������������û��������ô�����鳾������ :)\n");
    if ((int)(me->query("qi")) < 50)
        return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
    me->receive_damage("qi", 30);
    return 1;
}

