inherit SKILL;
 
 mapping *action = ({
 ([

"action":"$NԾ�ڰ�գ�һ�С��ɺ�չ������ɽ��������$w�ѻ���������Ӱ����$n
�ۻ����ң���֪���룬��������",
         "force" : 350,
         "dodge" : 10,
         "parry" : 10,
         "damage": 70,
         "lvl" : 20,
         "skill_name" : "�ɺ�չ������ɽ",
         "damage_type":"����"
 ]),
 ([

"action":"$Nͦ$w��$n��$W��ס��˳��һ�С������λ����ɹ�����$w�������ҷɿ�
������������ߣ���$nѹ������",
         "force" : 380,
         "dodge" : 10,
         "parry" : 15,
         "damage": 75,
         "lvl" : 25,
         "skill_name" : "�����λ����ɹ�",
         "damage_type":"����"
 ]),
 ([

"action":"$Nһ�С���¹̤�����ɲݡ�����ϥ��������$w����$n���̣�ȴδ���������ϣ��͵�
һ�ᣬ��$n���ظ����ȥ",
         "force" : 420,
         "dodge" : 15,
         "parry" : 20,
         "damage": 70,
         "lvl" : 30,
         "skill_name" : "��¹̤�����ɲ�",
         "damage_type":"����"
 ]),
 ([

"action":"$NͻȻ�����ڵأ�$n��㵼䣬һ�С�����ԾˮǱ��ء�������$n�����´ܹ���������ͷ��
$w����ɨ��$n��$l",
         "force" : 450,
         "dodge" : 20,
         "parry" : 25,
         "damage": 75,
         "lvl" : 40,
         "skill_name" : "����ԾˮǱ���",
         "damage_type":"����"
 ]),
 ([

"action":"$Nһ�С���Գ�׹�����������������磬����$n�ɿ챼�ܣ�����$wһ�п���һ�У�
ɲ�Ǽ���$n�����ʮ����",
         "force" : 480,
         "dodge" : 30,
         "parry" : 30,
         "damage": 70,
         "lvl" : 50,
         "skill_name" : "��Գ�׹�������",
         "damage_type":"����"
 ]),
 ([

"action":"$N��̤����ǰ������˫�ۣ�����$w�󿪴��أ�����������һ�С���ӥ����ɨǬ����
ɨ��$n������",
         "force" : 490,
         "dodge" : 30,
         "parry" : 40,
         "damage": 70,
         "lvl" : 70,
         "skill_name" : "��ӥ����ɨǬ��",
         "damage_type":"����"
 ]),
 ([

"action":"$N���һ����һ�С�������ˮ�����桹��$w���ַɳ������ž�������$n��ǰ�ģ��漴��
��$n����������ְ�$w��������",
         "force" : 530,
         "dodge" : 50,
         "parry" : 40,
         "damage": 80,
         "lvl" : 100,
         "skill_name" : "������ˮ������",
         "damage_type":"����"
 ]),
 ([
"action":"$N˫ĿԲ��������Ĭ�����ԣ�һ�С�������ƺ���������$w����ǧ���������
�ֻ�����$n�ĵ�ͷ����",
         "force" : 550,
         "dodge" : 60,
         "parry" : 50,
         "damage": 100,
         "lvl" : 120,
         "skill_name" : "������ƺ�����",
         "damage_type":"����"
 ]),
 });
 
 int valid_enable(string usage) { return  (usage == "club") || (usage ==
 "parry"); }
 
 int valid_learn(object me)
 {
         if ((int)me->query("max_neili") < 100)
                 return notify_fail("�������������\n");
         if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                 return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
         level   = (int) me->query_skill("weituo-chu",1);
         for(i = sizeof(action); i > 0; i--)
                 if(level > action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
 }
 
 int practice_skill(object me)
 {
         object weapon;
 
         if (!objectp(weapon = me->query_temp("weapon"))
                  || (string)weapon->query("skill_type") != "club")
                 return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query("jing") < 50)
                  return notify_fail("�������������Τ���ơ�\n");
           me->receive_damage("jing", 20);
         return 1;
}

