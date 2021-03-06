#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);

mapping *action = ({
  ([
    "action":
"$N忽然纵声长啸，横跃于空，$w已到$n左肩，眼看就要对穿而过！\n"
"这招「李广射石」果然有穿石之力",
    "force":       250,
    "damage":      25,
    "dodge":      -20,
    "parry":       10,
    "damage_type": "毒伤",
    "post_action": (: throw_weapon :),
    "name":        "声东击西",
    ]),
  ([
    "action":
"$N手交背后，俯身一招「廉颇负荆」，$w已带呼啸声向$n前胸飞去",
    "force":    300,
    "damage":   35,
    "dodge":    20,
    "parry":    20,
    "damage_type": "毒伤",
    "post_action":      (: throw_weapon :),
    "name":             "廉颇负荆",
    ]),
  ([
    "action":
"突然间，$N几个筋斗倒翻而去，已在$n数丈之外。\n"
"$n正待追击，$N忽然转身，好一个「百步穿杨」，\n"
"$w已带着破空之声，直射$n面门",
    "force":       350,
    "damage":       20,
    "dodge":       -10,
    "parry":       -10,
    "damage_type": "毒伤",
    "post_action":      (: throw_weapon :),
    "name":             "百步穿杨",
    ]),
  ([
    "action":
"$N对准$n的左臂虚晃一箭。$n纵起闪避，突然发现并无羽箭射来。正在无处可去时，\n"
"$N仰天长叹，只见一支$w向$n的$l疾飞而至",
    "force":    400,
    "damage":   25,
    "dodge":    -20,
    "parry":    10,
    "damage_type": "毒伤",
    "post_action":      (: throw_weapon :),
    "name":             "声东击西",
    ]),
  ([
    "action":
"$N手指微动，$n只听到「嗖」地一声，$w已到$l前数寸。\n"
"$n没放到这招「后翌落日」来势如此之快，不禁手足无措",
    "force":    450,
    "damage":   35,
    "dodge":    10,
    "parry":    -10,
    "damage_type": "毒伤",
    "post_action":      (: throw_weapon :),
    "name":             "后翌落日",
    ]),
  ([
    "action":
"$N马步站稳，劲力透背，$w飞一般冲向$n的$l",
    "force":    500,
    "damage":   40,
    "dodge":    20,
    "parry":    20,
    "damage_type": "毒伤",
    "post_action":      (: throw_weapon :),
    "name":             "流星赶月",
    ]),
  ([
    "action":
"$n纵身而起，正待凌空一击。$N作势似要逃跑，突然扭腰回身，\n"
"一招「犀牛望月」，手中$w如同长眼一般，直刺向$n的$l",
    "force":        680,
    "damage":       30,
    "dodge":       -10,
    "parry":       -10,
    "damage_type": "毒伤",
    "post_action":  (: throw_weapon :),
    "name":         "犀牛望月",
    ]),
});
 
int valid_learn(object me)
{
  object ob;
  
  if(me->query_skill("throwing",1) < 20)
    return notify_fail("如果基本功不扎实，怎能在激战中射敌？\n");
  if( (int)me->query("max_neili") < 50 )
    return notify_fail("你的内力不够，不能练习！\n");
  if( !(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "throwing" )
    return notify_fail("手中没有玉蜂针怎能领悟师父所教？\n");
  return 1;
}

mapping query_action(object me)
{
  int max=me->query_skill("throwing") / 3;
  
  if (max>sizeof(action)) max=sizeof(action);
  return action[random(max)];
}

string learning_message(int level)
{
  if (level / 3 >= sizeof(action) ) return "";
  else return "对「" + action[level/3]["name"] + "」这招有所领悟";
}

int valid_enable(string usage)
{
  return (usage=="throwing");
}

int practice_skill(object me)
{
  object weapon;

  if( !objectp(weapon = me->query_temp("weapon"))
     ||      (string)weapon->query("skill_type") != "throwing" )
    return notify_fail("没有玉蜂针如何练准头？\n");

  if( (int)me->query("qi") < 40 || (int)me->query("neili") < 10)
    return notify_fail("你的体力不足！\n");
  me->receive_damage("qi", 30);
  me->add("neili", -15);
  return 1;
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
  if( objectp(weapon) ) {
    if( (int)weapon->query_amount()==1 ) {
      weapon->unequip();
      tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n");
    }
    weapon->add_amount(-1);
  }
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
            if( random(me->query_skill("yunu-xinjing")) > 15) {
                    victim->apply_condition("bing_poison", random(2) + 1 +
                           victim->query_condition("bing_poison"));
            }
}
