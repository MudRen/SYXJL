// �ط������

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ�����Ϯ�¡�������ƽָ��������磬һ�ɽ���ֱ�ӳ���$n�����������͹�$n��$l",
        "force" : 160,
        "dodge" : 20,
        "parry" : 5,
        "damage" : 25,              
        "skill_name" : "���Ϯ��",
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ��Ʈѩ���ơ���$w�Ľ������һƬѩ����ֱ��$n��$l",
        "force" : 220,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 30,                                                
        "skill_name" : "Ʈѩ����",
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$N����$wбָ���죬һʽ��ǧ�徺�㡹���������������⣬��������������$N������$n��$l",
        "force" : 250,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 40,                              
        "skill_name" : "ǧ�徺��",
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������ڡ���$w���϶��»�������һ���󻡣���һ�п��ƻ�������ͻȻ������$n��$l�̳�",
        "force" : 300,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 50,              
        "skill_name" : "��������",
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N����š����һʽ��������������$w����ƽ�����������棬ʵ�����̲ؾ�������������������$n��$l",
        "force" : 330,
        "parry" : 5,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 40,                           
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��������ɳ����ȫ������ƽ�ɣ�����һ����ʱ�䱼��$n�����������ش���$n��$l��",
        "force" : 380,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 70,              
        "skill_name" : "������ɳ",
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�����������Ρ���$w���ַɳ����������㰿������ƿ�֮��է�죬����$n��$l��",
        "force" : 440,
        "dodge" : 20,
        "parry" : 15,
        "damage" : 85,              
        "skill_name" : "��������",
        "lvl" : 65,
        "damage_type" : "����"
]),
([      "action" : "$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų�������ѩ����â����ҫ��ʣ�ʹ��$n�޿��ʴ�",
        "force" : 500,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 90,                        
        "skill_name" : "��غ���",
        "lvl" : 80,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}               
/*
string *hit = ({
"$Nһʽ�����Ϯ�¡�������ƽָ��������磬һ�ɽ���ֱ�ӳ���$n�����������͹�$n��$l",
"$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ��Ʈѩ���ơ���$w�Ľ������һƬѩ����ֱ��$n��$l",
"N����$wбָ���죬һʽ��ǧ�徺�㡹���������������⣬��������������$N������$n��$l",
"$Nһʽ���������ڡ���$w���϶��»�������һ���󻡣���һ�п��ƻ�������ͻȻ������$n��$l�̳�",
"$N����š����һʽ��������������$w����ƽ�����������棬ʵ�����̲ؾ�������������������$n��$l",
"$Nһʽ��������ɳ����ȫ������ƽ�ɣ�����һ����ʱ�䱼��$n�����������ش���$n��$l��",
"$Nʩ�����������Ρ���$w���ַɳ����������㰿������ƿ�֮��է�죬����$n��$l��",      
"$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų�������ѩ����â����ҫ��ʣ�ʹ��$n�޿��ʴ�",
});             
                       
private string *limb = ({
                "ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
                "�ұ�", "����", "����", "����", "С��", "����", "����",
                "���", "�ҽ�", "���", "�Ҷ�", "����", "����", "�ɲ�",
});*/
string query_skill_name(int level)
{
    int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        level   = (int) me->query_skill("huifeng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 20)
                return notify_fail("��������������ط��������\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������ط��������\n");
        me->receive_damage("neili",5);
        me->receive_damage("qi", 20);   
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wa, wb;
        string msg, type1, hit;
        int i, j, p, skill, neili;
        wa = me->query_temp("weapon");
        wb = ob->query_temp("weapon");
        skill = (int)me->query_skill("huifeng-jian", 1);
        neili = (int)me->query("neili");
        type1 = wa->query("skill_type");
     if( type1 == "sword" && wa && skill > ((int)ob->query_skill("parry", 1)/2)
         && (int)me->query("combat_exp") > (int)ob->query("combat_exp")/10
         && me->query_skill_mapped("parry") == "huifeng-jian"
         && me->query_skill_mapped("sword") == "huifeng-jian"
         && me->query_skill_mapped("force") == "linji-zhuang"
         && (int)me->query_skill("linji-zhuang", 1) > 50
         && neili > 300 && skill > 50 && living(me)
         && (int)me->query("qi") > 500
         && userp(me))
         {
                if(random(2) >= 1)
                {
                i = random(sizeof(action));// if(i=0) i=2;
                msg = "$N����$n�Ľ�������Ӱ��ӯһ������������\n";
                msg += "����$n����֮ʱ��"+action[i]["action"]+"��\n";
                msg += "$nû���ϵ�$N��������Ȼ����������æ֮�䣬�����޴룡\n";
                ob->receive_damage("qi", damage*3/2);
                p = ob->query("qi")*100/ob->query("max_qi");
                msg += damage_msg(damage*3/2, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                j = -(damage*3);                
                }
                else{                                                
                 msg = "����$n����֮ʱ��"+action[i]["action"]+"��\n";
                 msg += "$n���һ��������$p�����ϵ�����$P���˹����������ŷ����ַ�һ�С�\n";
                 j = -damage/4; 
               }           

         message_vision(msg, me, ob);
         return j;
         }
}
