// liusheng-xinyinliu.c ����������
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "ֻ��$n˫���ᵶ�������ڶԷ��Ĺ�������һ�ʣ����$P��ǿ��������Ƶò��ò����з��ء�\n",
        BLU"$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����$P��ι�����ֻ�˷����Ϳ���ɱ��$Pֻ�з���������\n"NOR,
        HIW"$n���б�����һ��б�ã�Ӳ�ǽ�$P�Ĺ������˻�ȥ��\n"NOR,
        HIM"$n�ۼ�$Pһ�й��������Ų�æ�ķ�����$P��$l�����$P��æ�мܡ�\n"NOR,
        HIG"$n�������ܣ����Ӳ��Ӳ�����ĸ���$P�Ĺ��ơ�\n"NOR,
        YEL"$n����$Pһ�й���������бָ���µı���ͻȻ���϶����£�$P����һ������æ�س���\n"NOR,
        CYN"$n���ֽ�$P���ֱ�����һ�ƣ�$P���ʧȥ���ġ�\n"NOR,
        MAG"ֻ��$n����ֱ�����У��þ�ȫ���ܿ���$P�Ĺ�����\n"NOR,
        RED"$nͻȻ�����׼$P������ֱ�̹�ȥ��$P��֮�£���æ�ջع��ƣ�ת����ء�\n"NOR,
});

mapping *action = ({
([      "action":"$Nһ�С�һ�����ϡ���$w���ǰ��ն��$n��$l",
        "force" : 75,
        "dodge" : 0,
        "damage": 70,
        "lvl" : 0,
        "skill_name" : "һ������",
        "damage_type":  "����"
]),     
([      "action":"$Nʹ��һ�С�Сڵ��������ĩ�˵���������һ�ƣ�����ֱ��$n��$l",
        "force" : 95,
        "dodge" : 0,
        "damage": 90,
        "lvl" : 10,
        "skill_name" : "Сڵ",
        "damage_type":  "����"
]),     
([      "action":"$Nʹ��һ�С���ڵ����������һ����ס���������������࣬Ȼ����Ȼǰ��$n��$l",
        "force" : 100,
        "dodge" : 10,
        "damage": 90,
        "lvl" : 20,
        "skill_name" : "��ڵ",
        "damage_type":  "����"
]),     
([      "action":"$Nһ��"HIY"����Ӱ��"+NOR"���������£�����ն��һ������$n��$l",
        "force" : 150,
        "dodge" : 10,
        "damage": 100,
        "lvl" : 30,
        "skill_name" : "��Ӱ",
        "damage_type":  "����"
]),
([      "action":"$Nһ��"HIM"���뿪����"+NOR"�����е�$w���϶��º��������ˮ�ؿ���$n��$l",
        "force" : 190,
        "dodge" : 30,
        "damage": 150,
        "lvl" : 50,
        "skill_name" : "�뿪����",
        "damage_type":  "����"
]),
([      "action":"$N�ҽ�̤ǰ�������̤��һʽ"+HIB"������һζ��"NOR"������$w����$n��$l",
        "force" : 220,
        "dodge" : 40,
        "damage": 170,
        "lvl" : 70,
        "skill_name" : "����һζ",
        "damage_type":  "����"
]),
([      "action":"$N���ϱ���Ծ��һ����ͻȻת��$n�ı���һʽ"+MAG"����ʤ��"NOR"��$w�ͳ�$n��$l��ȥ",
        "force" : 270,
        "dodge" : 70,
        "damage" : 190,
        "lvl" : 90,
        "skill_name" : "��ʤ",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ��һʽ"+BLU"����硹"NOR"���������ּ�ת������ն��$n��$l",
        "force" : 290,
        "dodge" : 10,
        "damage": 220,
        "lvl" : 100,
        "skill_name" : "���",
        "damage_type":  "����"
]),
([      "action":"$N����ǰ�㣬һʽ"+RED"��������"NOR"������$w��ĺ��Ƶ�ˮ��������â��һ������$n��$l",
        "force" : 320,
        "dodge" : 10,
        "damage": 250,
        "lvl" : 110,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N�����ַ���$w��һ��"+HIR"��������"NOR"��$w���¶ζ�������$n��$l",
        "force" : 330,
        "dodge" : 15,
        "damage": 260,
        "lvl" : 120,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N˫�ֽ���$w��һ��"+HIM"�����ơ�"NOR"����׼$n��$l�ɾ������ֱ�̽���ȥ",
        "force" : 350,
        "dodge" : 30,
        "damage": 270,
        "lvl" : 130,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N����$w��ת��һ��"+HIG"�����ϡ�"NOR"��һ�ֳֽ���һ������$w�ĵ�����������������$w�ķ�â����$n��$l",
        "force" : 380,
        "dodge" : 30,
        "damage": 290,
        "lvl" : 150,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"��ɱ�ˣ������Բ���ɱΪʤ��$N��һ��"+HIW"�����˵���"NOR"����Ȼ����ɱ���Ĵ�����޷���$n��$l",
        "force" : 430,
        "dodge" : 40,
        "damage": 300,
        "lvl" : 170,
        "skill_name" : "���˵�",
        "damage_type":  "����"
]),
([      "action":"$nֻ���׹��������·���ǰȫ������$w��Ӱ�ӣ�ͻȻ$Nһ��"+BLU"�����⡹"NOR"��һ������ֱ��$n��$l",
        "force" : 470,
        "dodge" : 40,
        "damage": 350,
        "lvl" : 190,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":HBBLU"ʹ�����칷�������⡪���������������"NOR"$w"+HBBLU"��Ȼ�������д���$N�Ĺ���һ������$n��$l"NOR,
        "force" : (int)this_player()->query("str")*20,
        "dodge" : (int)this_player()->query_skill("dodge")/3,
        "damage": (int)this_player()->query_skill("bushidao",1)*4,
        "lvl" : 200,
        "skill_name" : "���",
        "damage_type":  "����"
]),
([      "action":WHT"$N�����塢������ͻȻ��Хһ����һ�С����ı�ʤ�������е�"NOR"$w"+WHT"�ڵ��ϻ���һ���׹⣬�����š��̴̡�����$n��$lֱ�ƹ�ȥ"NOR,
        "force" : (int)this_player()->query("str")*25,
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "damage": (int)this_player()->query_skill("bushidao",1)*5,
        "lvl" : 210,
        "skill_name" : "�˹w��ʤ",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        int na, nl;
        na = (int)me->query_skill("bushidao", 1);
        nl = (int)me->query_skill("liusheng-xinyinliu", 1);

        if (me->query("family/master_name") == "����ʯ��ի" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("��ʿ�������������ձ��������ɵ�֧�ţ����ܲ�ѧ�ã�\n");
        }

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if (me->query_skill_mapped("force") != "jiangui-xinfa")
                return notify_fail("��ϰ���������������н����ķ�����ϡ�\n");
        if ((int)me->query_skill("jiangui-xinfa", 1) < 20)
                return notify_fail("��Ľ����ķ����̫ǳ��\n");
        if ((int)me->query_skill("bushidao", 1) < 20)
                return notify_fail("�����ʿ�����񼸺�û�С�\n");        
        return 1;
}

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
        level   = (int) me->query_skill("liusheng-xinyinliu",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int na, nl;
        int lvl = me->query_skill("liusheng-xinyinliu", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        na = (int)me->query_skill("bushidao", 1);
        nl = (int)me->query_skill("liusheng-xinyinliu", 1);

        if (me->query("family/master_name") == "����ʯ��ի" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("��ʿ�������������ձ��������ɵ�֧�ţ����ܲ�ѧ�ã�\n");
        }

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query("qi") < 70)
                return notify_fail("�������������������������\n");
         me->receive_damage("qi", 40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liusheng-xinyinliu/" + action;
}



