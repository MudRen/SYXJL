// dagou-bang.c �򹷰���

#include <ansi.h>;
inherit SKILL;
#include "/u/hate/skill/msg.h";

string *xue_name = ({ 
"ǿ��Ѩ","�縮Ѩ","����Ѩ","��̨Ѩ","����Ѩ",}); 

string  *msg = ({

"$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",

"$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",

"$Nʩ�����������졹��$w����������$n��ȥ",

"$Nʹ��һ�С�����˫Ȯ�������ð����Ȼ����ɨ$n��$l",

"$Nٿ�����$w����ͷ����$n��$l�ϣ�һ�С�ѹ�繷�������������°���",

"$N����$w�߸�����һ�С�����������������$n��$l",

"$N����$w��ɨ���ң�һ�С�ɨ�ظϹ���������һƬ��Ӱ",

"$N�ֱ�һ�죬����$w��$n�������һ�С����Ŵ򹷡�",
 
"$N$w���Եݳ���һ�С�����·��������බ�Բ�������б˦",

"$Nһ�С���۵�����������$w���������������$n��$l",

});


int valid_enable(string usage) { return (usage == "stick") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query_skill("stick", 1) < 30)
                return notify_fail("��Ļ�������̫��, ����᲻�˴򹷰�����\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("��Ļ���������Ϊ������\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������������\n");
        
    if ((me->query_skill("dagou-bang",1)>20) && (me->query_skill("begging",1)<180))
        if (me->query_skill("dagou-bang", 1) > me->query_skill("begging", 1)+20)
        return notify_fail("�򹷰�����Ҫ��Ӧ�ȼ��Ľл����\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
                i=me->query_skill("begging",1);
                level=me->query_skill("dagou-bang",1);
        if (i>140) i=140+i/10;
                if (level>140) level=140+level/10;

        if ( random(10) > 6
        &&      ( (int)me->query_skill("stick", 1) >= 120 ) 
        &&      ( (int)me->query_skill("dagou-bang", 1) >= 120 )
        &&      ( (int)me->query_skill("force",1) >= 120 )
        &&      ( (int)me->query("neili") >= 500 )
        &&      ( (int)me->query_skill("begging", 1) >= 100 )
        &&      ( (string)weapon->query("id") == "yuzhu zhang" ) ) {
                me->add("neili", -50);
                return ([
                "action": HIG"$N�������һ����â������$wʹ��"RED"�������޹���"HIG"������ǵذ㹥��$n"NOR,
                "damage": 300,
                "dodge":50,
                "parry":80,
                "force": 600,
                "damage_type": "����"]);
        }
return ([
                "action":msg[random(sizeof(msg))],
                "damage":random(50)+i/2+level/2+50,
                "parry":random(i/8)+20+random(level/8),
                                "dodge":random(i/5)+20,
                "force":level+i/2+50+random(50),
                "damage_type": "����",
        ]);
       
}

int practice_skill(object me)
{
        object weapon;
     if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "stick")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("jing") < 40)
                return notify_fail("��������������򹷰�����\n");  


        me->receive_damage("jing",30);
        me->add("neili", -15);  
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg,name;
    int i,j,damage;
    object weapon, weapon1;     
         name = xue_name[random(sizeof(xue_name))];
    weapon = me->query_temp("weapon");
    weapon1 = victim->query_temp("weapon");
    i = me->query_skill("begging", 1);
    j = me->query_skill("dagou-bang", 1);

    if( damage_bonus < 100 ) return 0;
    

    if(!victim->is_busy() && i > 100 &&
       victim->query("neili") && j > 100 &&
       me->query_skill_mapped("parry") == "dagou-bang" &&
       me->query("neili") > 400 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("parry",1))){
       if (random(20)>13){
              switch(random(4)){
            case 0 :
               message_vision(GRN"$N"+weapon->name()+"�ӳ����ԡ����־��ŵ�ɨȥ��һ���У������������������̣������������\n"NOR,me, victim);
               victim->start_busy(3);
                           if (!random(2))
                           message_vision(HIR"$n������������"+weapon->name()+"��������һ����������һ�����˵ص��ˡ�\n"NOR,me, victim);             
               else
                           message_vision(HIR"$n��δ��أ���"+weapon->name()+"����һ��һ��$n���㲻ס������һ��ˤ����\n"NOR,me, victim);             
               break;
            case 1 :
                message_vision(GRN"$Nʹ���������־�������������"+weapon->name()+"���籩���Ĵ�ȥ��\n"NOR,me, victim);
                damage = damage_bonus/10 + random(damage_bonus)/5;
                victim->receive_danage("qi",damage/5);
                                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/5);
                            break;
                        case 2 :
              message_vision( GRN"$Nʹ���������־�������"+weapon->name()+"ֱ��ֱ�£��㶫������������$n��Ҫ����ȥ��\n"NOR,me, victim);
                damage = damage_bonus/5 + random(damage_bonus)/10;
                victim->receive_wound("qi", damage/2);
                me->add("neili", -damage/2);
              break;
            case 3 :
             message_vision( GRN"$N�����ٱ䣬ʹ���ˡ�ת���־�������"+weapon->name()+"������һ�ű�Ӱ���͵�$n���ĸ���ҪѨ��\n"NOR,me, victim);
                           if((!random(5)))
                                {
                                victim->start_busy(2);
                                me->add("neili",-40);
                                victim->receive_damage("qi", me->query_skill("dagou-bang",1)/5+damage_bonus/5);
                                victim->receive_wound("qi", me->query_skill("dagou-bang",1)/10+damage_bonus/5);       
                                 message_vision(HIR"$n��"+weapon->name()+"����"RED+name+HIR"�����˵��ˣ�\n" NOR,me, victim);
                        }                 
               break;
            }
           } else if (weapon1 && random(20)<7) 
                   {
             switch(random(2)){
            case 0 :
                           if (random(2)!=1){ 
                message_vision( GRN"$N"+weapon->name()+"����������"+weapon1->name()+"����֮�������������־���˳������ǣ��! \n"NOR,me, victim);
               } else {
              message_vision( GRN"$N"+weapon->name()+"���أ�ʹ�������־�����ס"+weapon1->name()+"����˦������$n��������������"+weapon1->name()+"��! \n"NOR,me, victim);
                           }
                           victim->start_busy(1);
                           if (!random(4)){
                         message_vision( HIR"$nֻ��"+weapon1->name()+"�������ַɳ���һ�����ղ�ס�����б������Է����˹�ȥ��\n"NOR,me, victim);            
               weapon1->unequip();
               weapon1->move(environment(victim));
                           }
                           break;
            case 1 :
              message_vision( GRN"$Nʹ���������־�,"+weapon1->name()+"�ӵ�����"+weapon->name()+"���򶫣�"+weapon1->name()+"������"+weapon->name()+"�浽������Ӱ���Σ������ƵС�\n"NOR,me, victim);
               damage = damage_bonus/10 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage) 
                                 { victim->set("jing",0); }
                                 else {
                 victim->receive_damage("jing", damage); 
                                 }
                victim->start_busy(3);  
                me->add("neili", -damage);    
                           break;
                          }
                  }
           }
}
