// shenghuo-lingfa ʥ���
// 1997-5-14
inherit SKILL;

string  *msgl = ({
"$Nһʽ���������󡹺��ط��֣�$w��β�����ϵ��������벻����λ������$n��ȥ",
"$Nƽƽһ�������һʽ�����·ת����$w�ڰ�չŹŹֵֹ�ת�˸��䣬����$n��$l",
"$NͻȻһ����Х��˫��һ�С�������ʵ������ʵʵ�����Ƕ��ǵĻ���$n��$l",
"$N��Ȼ��ͷ��һʽ��ͷͷ�ǵ�����һ��ͷ����$nײȥ������$wȴ���е���$n��$l��ȥ",
"$NͻȻ�������һʽ�����������������������Ľ���׹������һ����$n��$l��ȥ",
"$N���ش��أ�һʽ������������������صĿ޺ţ�ͻȻ����߷�ɳ��$w��$n����",
"$NĬ��ھ���$wһ�С�Ӧ����󡹣���ָǰ�أ�ͻ��ת����$n��������ȥ",
"$N��ʥ�����е�һ�С�������ǰ��������ұۣ�$w��$n����ǰ�Ĵ�Ѩ��ȥ",
"$Nһ�С��������С�����֪��Σ����е�$w�ѿ����ޱȵĴ���$n��$l",
"$N���е�$w����һ����Ȧ�ӣ�һ�С��췽��԰������$n��$n��ʱ�ۻ�����"
});
string  *msgc = ({
"$N����Ϊ����һ�С�������ʤ��������б�ɣ���������$n�߳��Ľ�",
"$Nһʽ��������ȫ���������ڵ���һ�������ֱ���$n��$l�����ֻ����ж���Ѩ",
"$NͻȻ��һʽ���Խ�Ϊ�ˡ���������ǰһ�����Ľ��������£�˫����$n$l��ȥ",
"$N����һ����һʽ��������ա��������շ��˼������Ľ�������$n��$lץȥ",
"$Nһ�����һʽ���������ڡ������ڰ�գ�����ʱ�ҽŵ�ϥ����$n�ض�һ��",
"$N��ǰһ����һʽ��Ͷ���ͱ�����ײ��$n�Ļ��У�˫����$n$l��Ѩ��ײȥ",
"$N���ش��أ�һʽ����ɳ��ʯ�����������صĿ޺ţ�ͻȻ����߷�ɳ��������$n����"
});
int valid_enable(string usage)
{
        return usage == "blade" || usage== "cuff" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        if (!weapon)
        return ([
                "action":msgc[random(sizeof(msgc))],
                "damage":(random(3)+1)*40,
                "damage_type":"����",
                "dodge":random(20)-random(8),
                "force":random(160)+100
        ]);
        if (weapon->query("id")=="shenghuo ling"||weapon->query("id")=="tie ling")
                return ([
                "action":msgl[random(sizeof(msgl))],
                "damage":(random(3)+1)*45,
                "damage_type":random(2)?"����":"����",
                "dodge":random(35)-random(10),
                "force":random(260)+100,
                "post_action":
                (: call_other, WEAPON_D, "bash_weapon" :)
        ]);
        return ([
                "action":"$N����$w��׼$n$lһ���ҿ�",
                "damage":30,
                "damage_type":"����",
                "dodge":30,
        ]);
}
int practice_skill(object me)
{    
       object weapon = me->query_temp("weapon");
       int i;
       if (!weapon)
               return notify_fail("��û��ʹ�õ�������\n");
       if(weapon->query("id") == "shenghuo ling")
            i = 35;
       else if(weapon->query("id") == "tie ling")
            i = 50;
       else return notify_fail("�����ʹ�����ơ�\n");
       if ((int)me->query("qi") < 50)
               return notify_fail("�������������ʥ�����\n");         
       if ((int)me->query("neili") < 50)
               return notify_fail("�������������ʥ�����\n");
       me->receive_damage("qi", i);
       me->receive_damage("neili", 35);
       return 1;
}

int valid_learn(object me)
{
    int skill = me->query_skill("shenghuo-lingfa", 1);
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������������\n");
       if ((int)me->query_skill("shenghuo-shengong", 1) < (skill-10))
               return notify_fail("���ʥ���񹦻��̫ǳ��\n");      
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"shenghuo-lingfa/" + action;
}
