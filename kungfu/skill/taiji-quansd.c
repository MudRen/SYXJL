// taiji-quan.c ̫��ȭ
#include <ansi.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([  "action" : "$N��̫��������ʽ����˫���´����ֱ����⣬��������������������ǰ",
    "force" : 75,
    "dodge" : 0,
    "parry" : -5,
    "lvl" : 0,
    "skill_name" : "����ʽ",
    "damage_type" : "����"
]),
([  "action" : "$N����һ�С���ȸβ����˫�ֻ��˸���Ȧ����������������$n��$l",
    "force" : 155,
    "dodge" : -5,
    "parry" : -10,
    "lvl" : 5,
    "skill_name" : "��ȸβ",
    "damage_type" : "����"
]),
([  "action" : "$N���$n��һ�С����ޡ���������ȭ�������ϻ�����һǰһ�����ƽ��",
    "force" : 125,
    "dodge" : 5,
    "parry" : -10,
    "lvl" : 10,
    "skill_name" : "����",
    "damage_type" : "����"
]),
([  "action" : "$N���С��������ơ�������������������ǰ����۰뻷���ұ�ֱ�죬����$n��$l",
    "force" : 115,
    "dodge" : -2,
    "parry" : -10,
    "lvl" : 15,
    "skill_name" : "��������",
    "damage_type" : "ץ��"
]),
([  "action" : "$N���Ŷ����������鰴������ʹһ�С��׺����᡹����ȭ��ץ��$n��$l��ȥ",
    "force" : 125,
    "dodge" : 10,
    "parry" : -5,
    "lvl" : 20,
    "skill_name" : "�׺�����",
    "damage_type" : "ץ��"
]),
([  "action" : "$N����΢�����鲽��һ�ǡ�§ϥ��������������ǰ�����»�������$n$l��",
    "force" : 200,
    "dodge" : 7,
    "parry" : -3,
    "lvl" : 25,
    "skill_name" : "§ϥ����",
    "damage_type" : "����"
]),
([  "action" : "$N�ұ۰뻷������������һ�С��ֻ����á���ʮָ���ţ���������$n��$l",
    "force" : 150,
    "dodge" : 5,
    "parry" : -6,
    "lvl" : 30,
    "skill_name" : "�ֻ�����",
    "damage_type" : "ץ��"
]),
([  "action" : "$N������ֱ�������黮�������ұ��������һ�ǡ�����������������$n��$l",
    "force" : 230,
    "dodge" : 5, 
    "parry" : -10,
    "lvl" : 35,
    "skill_name" : "����������",
    "damage_type" : "����"
]),
([  "action" : "$N�����������������黮���������»�����ȭ��һ�ǡ�ָ�ɴ�������$n���ɲ�",
    "force" : 180,
    "dodge" : 10,
    "parry" : -20,
    "lvl" : 40,
    "skill_name" : "ָ�ɴ�",
    "damage_type" : "����"
]),
([  "action" : "$N˫���»���ȭ�������ǰ������Ȧ��һ�С�˫�������������������$n��̫��Ѩ",
    "force" : 300,
    "dodge" : 20, 
    "parry" : -10,
    "lvl" : 45,
    "skill_name" : "˫����",
    "damage_type" : "����"
]),
([  "action" : "$N�󲽳��飬���������鰴�����ֳ�����ʹһ�С��������š�����$n��$l��ȥ",
    "force" : 155,
    "dodge" : 4,
    "parry" : -5,
    "lvl" : 50,
    "skill_name" : "��������",
    "damage_type" : "ץ��"
]),
([  "action" : "$N������ȸβ�����ҽ�ʵ������飬�����־���ճ��ճ�棬��ס$n���ᾢ����",
    "force" : 250,
    "dodge" : 10,
    "parry" : -12,
    "lvl" : 55,
    "skill_name" : "��ȸβ",
    "damage_type" : "����"
]),
([  "action" : "$N�ҽ����������ֻ�Ȧ�󸧣�һ�С���̽��������Բת��ǰ����$n���Ż�ȥ",
    "force" : 220,
    "dodge" : 10,
    "parry" : -15,
    "lvl" : 60,
    "skill_name" : "��̽��",
    "damage_type" : "����"
]),
([  "action" : "$Nʩ��������ʽ�����������⻮��ס$n��������������ָ������$n��$l",
    "force" : 250,
    "dodge" : 20,
    "parry" : -10,
    "lvl" : 65,
    "skill_name" : "����ʽ",
    "damage_type" : "����"
]),
([  "action" : "$N���ֱ��ƺ�����ǰ��������ȭ�����´�����һ�С���׿�����������$n��$l",
    "force" : 220,
    "dodge" : 8,
    "parry" : 5,
    "skill_name" : "��׿���",
    "lvl" : 70,
    "damage_type" : "����"
]),
([  "action" : "$N���ǰ̤�벽����������ʹһ�С������롹����ָ�������ϴ���$n���ɲ�",
    "force" : 240,
    "dodge" : 6,
    "parry" : 5,
    "skill_name" : "������",
    "lvl" : 75,
    "damage_type" : "ץ��"
]),
([  "action" : "$Nһ�С���ͨ�ۡ������һ������������$n��ǰ�������Ͼ���Ʋ������̫����������$n", 
    "force" : 260,
    "dodge" : 8,
    "parry" : -10,
    "skill_name" : "��ͨ��",
    "lvl" : 80,
    "damage_type" : "����"
]),
([  "action" : "$N�ҽ�̤������������ȭ�黮�����ƻ��б��£���ǡ������ơ�һ�����㽫$n����̫��Ȧ��",
    "force" : 300,
    "dodge" : 10,
    "parry" : -2,
    "lvl" : 85,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N�����������ȡ��ɿ衢��������ϥ������������һ�С�������������$n��$l",
    "force" : 280,
    "dodge" : 10,
    "parry" : -20,
    "skill_name" : "����",
    "lvl" : 90,
    "damage_type" : "����"
]),
([  "action" : "$N���������ҽŶ�����ʹһ�С��𼦶�������˫ȭ����������̫��ȦȦ��$n��$l",
    "force" : 200,
    "dodge" : 8,
    "parry" : -5,
    "skill_name" : "�𼦶���",
    "lvl" : 95,
    "damage_type" : "����"
]),
([  "action" : "$N������̤��˫����ȭ�����ӳ���ʹһʽ����Ů���󡹣�˳��$n�ֱ�ֱ�ϣ�����$nǰ��",
    "force" : 300,
    "dodge" : 16,
    "parry" : -10,
    "skill_name" : "��Ů����",
    "lvl" : 100,
    "damage_type" : "����"
]),
([  "action" : "$N���ֻ�Ȧ�����־���ǰ��������ǰƲ����ʹһ�С�����Ʋ��������$n��$l��ȥ",
    "force" : 220,
    "dodge" : 5,
    "parry" : -10,
    "skill_name" : "����Ʋ��",
    "lvl" : 105,
    "damage_type" : "����"
]),
([  "action" : "$N�����鰴�����ֱ���������黮һ�С�ת����ȡ��������������$n��$l",
    "force" : 220,
    "dodge" : 5,
    "parry" : -5,
    "skill_name" : "ת�����",
    "lvl" : 110,
    "damage_type" : "����"
]),
([  "action" : "$N����һ�С��Դ��������ֻ�̫��Ȧ§��ϥ��������ȭ���»���������$n��$l",
    "force" : 240,
    "dodge" : 8, 
    "parry" : -6,
    "skill_name" : "�Դ�",
    "lvl" : 115,
    "damage_type" : "����"
]),
([  "action" : "$N��̤���Ƿ�λ�������ң�˫ȭ�����ʮ�֣�һ�С��������ǡ�����$n��$l��ȥ",
    "force" : 400,
    "dodge" : 10,
    "parry" : -10,
    "skill_name" : "��������",
    "lvl" : 120,
    "damage_type" : "����"
]),
([  "action" : "$N����΢ת��������ֱ���ұ�΢����������ϣ�ʹһ�С�����������$n���ֱ˦��ȥ",
    "force" : 300,
    "dodge" : 5,
    "parry" : -5,
    "skill_name" : "�����",
    "lvl" : 125,

    "damage_type" : "����"
]),
([  "action" : "$N˫���쿪������������һ����Բ����һ�С�ת�����������$n������������������̫��Ȧ��",
    "force" : 300,
    "dodge" : 15,
    "parry" : 10,
    "skill_name" : "ת�����",
    "lvl" : 130,
    "damage_type" : "����"
]),
([  "action" : "$N���ֻ������գ�������ȭ��ǰ�Ƴ���ȭ�������һ�С��乭�仢����ֱ��$n$l��ȥ",
    "force" : 240,
    "dodge" : 15,
    "parry" : -10,
    "skill_name" : "�乭�仢",
    "lvl" : 135,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$n$l��ס��̫���ᾢ�漴����",
    "force" : 400,
    "dodge" : -10, 
    "parry" : -20,
    "lvl" : 140,
    "skill_name" : "����",
    "damage_type" : "����"
]),
([  "action" : "$N����һ�������Ծ����˫�ֻ�̫��Ȧ����$n�Ĺ�������������ץ��$n������������",
    "force" : 220,
    "dodge" : -10,
    "parry" : -5,
    "lvl" : 145,
    "skill_name" : "���Ծ",
    "damage_type" : "����"
]),
([  "action" : "����$Nһ�С�б���ơ�����$n������ƫ��˫ȭ�ڻ������������ɾ���һ������$n",
    "force" : 200,
    "dodge" : -10,
    "parry" : -10,
    "lvl" : 150,
    "skill_name" : "б����",
    "damage_type" : "����"
]),
([  "action" : "����$N���С�������ɽ����˫ȭ����������бת����$n���һ�ƣ���������Ҫ��$n�Ƴ�",
    "force" : 210,
    "dodge" : 0, 
    "parry" : -20,
    "lvl" : 155,
    "skill_name" : "������ɽ",
    "damage_type" : "����"
]),
([  "action" : "$N������Ұ����ס���ת��$n�����ǰ�������ƽ����$n����һ�����뽫�����",
    "force" : 340,
    "dodge" : 5,
    "parry" : -15,
    "lvl" : 160,
    "skill_name" : "Ұ�����",
    "damage_type" : "����"
]),
([  "action" : "$Nʩ������ת�����������������ת����ȭ�����������ȭ����$n��$l",
    "force" : 210,
    "dodge" : 5, 
    "parry" : -15,
    "lvl" : 165,
    "skill_name" : "��ת�������",
    "damage_type" : "����"
]),
([  "action" : "$N�����ֱ��������ƣ����ֽ��棬�̶����ҷֿ����ɰ��С�����Ʊա�����$n$l",
    "force" : 410,
    "dodge" : 20,
    "parry" : -10,
    "lvl" : 170,
    "skill_name" : "����Ʊ�",
    "damage_type" : "����"
]),
([  "action" : "$Nʩ����ת�����������������ת����ȭ�������Ͼ�����ڲ����$n��$l",
    "force" : 160,
    "dodge" : 5,
    "parry" : -5,
    "lvl" : 175,
    "skill_name" : "ת�������",
    "damage_type" : "����"
]),
([  "action" : "$Nʩ������ת�������������������ת����ϥ��������ȭ������ȭ��ǰ���$n",
    "force" : 270,
    "dodge" : 10,
    "parry" : -15,
    "lvl" : 180,
    "skill_name" : "��ת�������",
    "damage_type" : "����"
]),
([  "action" : "$N���ֱ�������������ǰ�������������������ϣ���������Ʊա���ǰ��������$n",
    "force" : 450,
    "dodge" : 5, 
    "parry" : -10,
    "lvl" : 185,
    "skill_name" : "����Ʊ�",
    "damage_type" : "����"
]),
([  "action" : "$N����΢��ת����ϥ���裬���С�ʮ���֡�����ֻ�ֱ�΢�������ֱ��������໮������",
    "force" : 480,
    "dodge" : 5,
    "parry" : -10,
    "lvl" : 190,
    "skill_name" : "ʮ����",
    "damage_type" : "����"
]),
([  "action" : "$N����΢��ת�����С�ʮ���֡�����������������������ǰ�����ϱ����أ�������ʮ����",
    "force" : 500,
    "dodge" : 5,
    "parry" : -10,
    "lvl" : 195,
    "skill_name" : "ʮ����",
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ������ǰ�죬���ҷֿ�����΢���������ƽ��������������������$n$l",
    "force" : 100,
    "dodge" : 10,
    "lvl" : 200,  
    "parry" : -30,
    "skill_name" : "����",
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
    mapping fam  = me->query("family");
    if (fam["family_name"] != "�䵱��" || fam["generation"] != 2)
         return notify_fail("̫��ȭֻ�ܴ������ᴦѧ����\n");
    if( me->query("gender") == "����")
        return notify_fail("��һ�����в�Ů֮�ˣ���ô��ѧ��̫��ȭ��ô������书��\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��̫��ȭ������֡�\n");
    if ((int)me->query_skill("yinyun-ziqi", 1) < 100)
        return notify_fail("�����������򲻹����޷�ѧ̫��ȭ��\n");
    if ((int)me->query("max_neili") < 500)
        return notify_fail("�������̫�����޷���̫��ȭ��\n");
    if(me->query("taiji_quest") > me->query("taiji_zsf"))

        return notify_fail("����ö�̫��ȭ��������⣬�޷�������ϰ̫��ȭ��\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];    
}
void skill_improved(object me)
{
   int skill = me->query_skill("taiji-quan", 1);
   if(skill == 50 && !me->query("taiji_quest")) me->set("taiji_quest", 1);
   if(skill == 80 && me->query("taiji_zsf") < 2) me->set("taiji_quest", 2);
   if(skill == 110 && me->query("taiji_zsf") < 3) me->set("taiji_quest", 3);
   if(skill == 140 && me->query("taiji_zsf") < 4) me->set("taiji_quest", 4);
   if(skill == 170 && me->query("taiji_zsf") < 5) me->set("taiji_quest", 5);
   if(skill == 200 && me->query("taiji_zsf") < 6) me->set("taiji_quest", 6);   
   me->add("shen", me->query("combat_exp")/30);
}
mapping query_action(object me, object weapon)
{
    int i, j, level;
    object target; 
    level = (int) me->query_practice_skill("taiji-quan",1);

    if (random(me->query_con()) > 30 && random(5) == 4 &&
        level > 120 && me->query("neili") > 500){   
           me->add("neili", -50);    
                return ([
                "action": HIY"$N����������������Ŀ�����������ֱۣ�����������£������������ɽ��ȴ����������"NOR,
                "force" : 650,
                "dodge" : 10,
                "damage_type" : "����"                
                ]); 

        }         

       for(i = sizeof(action); i > 0; i--)
            if(level > action[i-1]["lvl"])
                 return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        int lvl = me->query_skill("taiji-quan", 1);
        int i = sizeof(action);

        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["taiji-quan"])
                while (i--) 
                        if (lvl == action[i]["lvl"])
                                return notify_fail("�㽫�Ѿ�ѧ���������ʽ��ϰ��һ�飬���������ȥ��ʦ��ѧ�µ���ʽ���޷���ý����ˡ�\n");
        while (i--) 
        if (lvl < 200 && lvl == action[i]["lvl"]) 
        return 0;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��̫��ȭʱ���ﲻ����������\n");                  
        if( me->query("gender") == "����")
        return notify_fail("����˸����ƣ�������ϰ̫��ȭ����ʱ��������ֻ�����ա�\n");                
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�������������̫��ȭ��\n");
        me->receive_damage("qi", 30);                      
        if(me->query_skill("juehu-shou", 1))
        me->add("neili", -(me->query_skill("juehu-shou", 1)/10));       
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
    return __DIR__"taiji-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j;
    j = me->query_skill("taiji-quan", 1);
   
    if( damage_bonus < 100 ) return 0;
    if(random(20) >= 15 && !victim->is_busy() && j > 120 &&
       me->query("neili") > victim->query("neili") &&
       me->query_skill_mapped("parry") == "taiji-quan" &&
       me->query("neili") > 600 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("dodge",1))){
          switch(random(4)){
            case 0 :
               msg = YEL"$N�������־���ճ��ճ�棬�����Ѵ�ס$n�����ɾ��漴������\n"NOR;
               victim->start_busy(2);             
               break;
            case 1 :

               msg = YEL"$N�����־���˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�\n"NOR;
               victim->start_busy(3);               
               break;
            case 2 :
               msg = YEL"$N��ճ���־���˫�ֻ�������Ȧ��Χ��һ������һ����̫��ԲȦ����������\n"NOR;
               victim->start_busy(4);     
               break;
            case 3 :
               msg = YEL"������$N����̫��ȭ��ճ����������������ʽ���뽫$n���Ӵ��ᣡ\n"NOR;
               victim->start_busy(3);              
               break;
            }
        switch(random(4)){
         case 0 : msg += HIR"���$n����������ǰһ�壬�����������ʼվ����\n"NOR; break;
         case 1 : msg += HIR"���$n����������ԭ�ؼ�ת���߰��£���ת���ݣ������Ĵ���\n"NOR; break;
         case 2 : msg += HIR"��ʱ���׵�$n����ײײ�������������㲻�ȣ������оƻ��ԡ�\n"NOR; break;
         case 3 : msg += HIR"$n��ʹ��ǧ��׹֮����ס���Σ�ȴ�������͵�ͨ�죬���ɼ����Ǳ���״��\n"NOR; break;
         }
        message_vision(msg, me, victim);
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        int p,j,skill, neili, neili1;
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

      if(me->query_temp("taiji-quan")){
           me->delete_temp("taiji-quan");
           return 1;
           }
      if(me->query("jiali") && random(skill) > random(ob->query_skill("parry", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query("jiali") > ob->query("jiali")/2
         && me->query_skill("yinyun-ziqi", 1) > 50
         && neili > 300 && skill > 50 && living(me)){        
         if(random(2)==1) me->add_temp("taiji-quan", 1);    
         if(wp1) msg = "$N˫��������̫��ԲȦ��$n��"+wp1->name()+"��һ�ƣ�";
         else msg = "$N˫�ֻ������������̫��ԲȦ��";
           if(neili >= neili1*2+damage){
              msg += "���$n��������̫��ȭ������������������\n",
              ob->receive_damage("qi", damage/2);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*3+skill);
              }             
           else if(neili >= random(neili1)*2+damage){
              msg += "���$n��������̫��ȭ��������ж��һ�ԣ�\n", 
              j = -(damage*2+skill*2);
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              msg += "���$n��������̫��ȭ��������ж����һ�룡\n", 
              j = -damage/2;               
              }
           else{
              msg += "���$n��������̫��ȭ��������ж����һС�룡\n", 
              j = -damage/4; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}
