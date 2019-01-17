#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action" : RED"$Nһ�С����߳�����������"NOR"$w"RED"�����������$n��$l��ȥ"NOR,
        "force" : 200,
        "dodge" : 0,
//        "parry" : -5,
        "damage" : 30,
        "lvl" : 0,     
        "skill_name" : "���߳���",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIW"$Nһ�С�ѩ�ط��ߡ���Խ��$n�����"NOR"$w"HIW"������Ϣ����$n��$l"NOR,
        "force" : 220,
        "dodge" : 20,
//        "parry" : 0,
        "damage" : 40,
        "lvl" : 15,     
        "skill_name" : "ѩ�ط���",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : WHT"$Nб�������һ�С�������Ӱ����������ö"NOR"$w"WHT",��ֱ����$n��$l"NOR,
        "force" : 240,
        "dodge" : 40,
//        "parry" : 5,
        "damage" : 50,
        "lvl" : 30,     
        "skill_name" : "������Ӱ",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIC"$Nһ�С��������硹��"NOR"$w"HIC"���ַɳ������Բ���˼��ĽǶȣ�����$n��$l"NOR,
        "force" : 270,
        "dodge" : 60,
//        "parry" : 10,
        "damage" : 60,
        "lvl" : 50,     
        "skill_name" : "��������",
        "damage_type" : "",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIG"$Nһ�С�����Ϸˮ��������"NOR"$w"HIG"��������ˮ����ͷ��������$n��$l"NOR,
        "force" : 300,
        "dodge" : 80,
//        "parry" : 15,
        "damage" : 70,
        "lvl" : 70,     
        "skill_name" : "����Ϸˮ",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIR"$N����ǰ��Խһ��,һ�С��������š�������"NOR"$w"HIR"���¶�����Ѹ�ײ����ڶ�֮ʽ����$n��$l"NOR,
        "force" : 330,
        "dodge" : 100,
//        "parry" : 15,
        "damage" : 90,
        "lvl" : 90,     
        "skill_name" : "��������",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIY"$Nһ�С�����������"NOR"$w"HIY"��˸������ʱ��ʱ���������ǧ�Ĵ���$n��$l"NOR,
        "force" : 370,
        "dodge" : 120,
//        "parry" : 15,
        "damage" : 110,
        "lvl" : 110,     
        "skill_name" : "��������",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIM"$N�ڿ�Ծ��һ�С�Ⱥ�����衹����ö"NOR"$w"HIM"���ֶ�����һö��һö����������������$n��$l��ȥ"NOR,        
        "force" : 450,
        "dodge" : 130,
//        "parry" : 20,
        "damage" : 130,
        "lvl" : 140,     
        "skill_name" : "Ⱥ������",
        "damage_type" : "����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
        ([      "skill_name":         "ǧ����",
                "action":HIB"$N˫��һ�Σ�һ�С�ǧ���򻯡������е�"NOR"$w"HIB"�ó������⣬
��һ�����������$n��$l"NOR,
                "dodge":        160,
                "force":        650,
//                "parry" :       25,
                "damage":       160,
                "lvl" : 170,                
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
       ([      "skill_name":         "���Ī��",
                "action":MAG"$N����һ����һ�����ð����ֻһɲ�Ǽ䣬����"NOR"$w"MAG"Ѹ�װ�Խ
�����ֵ�"NOR"$w"MAG"������һ�С����Ī�⡹�����ȷ���$n��$l"NOR,                
                "dodge":        200,
                "force":        800,
//                "parry" :       30,
                "damage":       200,
                "lvl" : 200,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������������û�а취������׶����\n");
        if ((int)me->query_skill("throwing", 1) < 50)
                return notify_fail("��Ļ���������û�����Ҿ���ѧ��ô����Ĺ���!!!\n");      
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("���������һЩ��������������׶����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level   = (int) me->query_skill("jinshe-zhui",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 40)
                 return notify_fail("�����������û�а취��ϰ����׶����\n");
        if( (int)me->query("neili") < 40)
        return notify_fail("�������������û�а취��ϰ����׶����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        write("�㰴����ѧ����һ�����׶����\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhui/" + action;
}
