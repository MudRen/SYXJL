#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int valid_learn(object me)
{

        if( (int)me->query_skill("shenghuo-lingfa", 1) < 30 )
                return notify_fail("你的圣火令法修为不够，没有办法领会阵法的的变化。\n");

        if( (int)me->query_skill("shenghuo-zhenfa", 1) >= (int)me->query_skill("array", 1) )
                return notify_fail("你的基本阵法修为不够，没有办法领会更高深的圣火阵法。\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
          || (string)weapon->query("id") != "shenghuo ling"
          && (string)weapon->query("id") != "tie ling")
               return notify_fail("你使用的武器不对。\n");

        if( (string)me->query_skill_mapped("blade") != "shenghuo-lingfa" )
                return notify_fail("圣火阵法必须配合圣火令法才能修练。\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练圣火阵法。\n");

        me->receive_damage("qi", 30);

        return 1;
}

int form_array(object leader, object *member)
{
        object weapon;
        int i;

        if( leader->query_temp("array") )
                return notify_fail("你已经布好阵了，如果要解散阵形，请用team array dismiss。\n");

        if(sizeof(member) !=3)
                return notify_fail("圣火令阵法只能由三人组成。\n");

        for(i=0;i< sizeof(member) ;i++ ) {
                if ( !stringp(member[i]->query_skill_mapped("array")) ||
                member[i]->query_skill_mapped("array") != "shenghuo-zhenfa" )
                        return notify_fail("队伍中还有人没有激发这种阵法。\n");

                if ( !stringp(member[i]->query_skill_mapped("blade")) ||
                member[i]->query_skill_mapped("blade") != "shenghuo-lingfa" )
                        return notify_fail("圣火阵法和圣火令法互相配合，你的队伍中有人还没有激发圣火令法。\n");

                if(member[i]->query_skill("shenghuo-zhenfa", 1) < 40
                || member[i]->query_skill("shenghuo-lingfa", 1) < 40)
                        return notify_fail(member[i]->name() + "的武功不足以组阵，请先把他从队伍中开除！\n");

                if (!objectp(weapon = member[i]->query_temp("weapon"))
                  || (string)weapon->query("id") != "shenghuo ling"
                  && (string)weapon->query("id") != "tie ling")
                        return notify_fail("队伍中还有人没有装备令牌做武器，无法启动圣火令阵法。\n");

                if(!present(member[i]->query("id"), environment(leader)))
                        return notify_fail("队伍中还有人没到场，先别急发动阵法。\n");
        }

        message_vision( HIG "$N等三人以奇怪的方位站好，准备用“圣法阵法”迎敌！\n" NOR, leader);
        for(i=0;i< sizeof(member) ;i++ ) {
                member[i]->set_temp("array", "shenghuo-zhenfa");
                member[i]->add_temp("apply/strength", (int)(leader->query_skill("shenghuo-zhenfa")/2) );
                member[i]->add_temp("apply/dexerity", (int)(leader->query_skill("shenghuo-zhenfa")/2) );
                member[i]->add_temp("apply/damage", (int)leader->query_skill("shenghuo-zhenfa"));
                member[i]->add_temp("apply/armor",(int)(leader->query_skill("shenghuo-zhenfa")*2));
        }

        remove_call_out("array_running");
        call_out("array_running", 2, leader, member);

        return 1;
}

void array_running(object leader, object *member)
{
        int i, j;
        object *enemy;

        for(i=0;i< sizeof(member) ;i++ ) {
                if( !member[i] || !member[i]->query_temp("array") ) {
                        message("team", HIW "【队伍】：阵法停止运转。\n" NOR, member);
                        for(i = 0;i < sizeof(member);i++) {
                                if( !member[i] )        continue;
member[i]->delete_temp("array");
member[i]->add_temp("apply/strength", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/dexerity", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/damage", -(int)leader->query_skill("shenghuo-zhenfa"));
member[i]->add_temp("apply/armor",-(int)(leader->query_skill("shenghuo-zhenfa")*2));
                        }
                        return ;
                }
                if( environment(member[i]) != environment(leader) ) {
                        leader->add_temp("array_async_times", 1);
                        if(leader->query_temp("array_async_times") > (int)leader->query_skill("dagou-zhen", 1)/20 ) {
message("team", HIW "【队伍】：由于" + leader->name() + "领导无方，阵法自动解散了。\n" NOR, member);
                                for(i = 0;i < sizeof(member);i++) {
member[i]->delete_temp("array");
member[i]->add_temp("apply/strength", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/dexerity", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/damage", -(int)leader->query_skill("shenghuo-zhenfa"));
member[i]->add_temp("apply/armor",-(int)(leader->query_skill("shenghuo-zhenfa")*2));
                                }
                                return ;
                        }
                        if( ((int)leader->query_temp("array_async_times") % 3 ) == 1 )
message("team", HIW "【队伍】：阵法队形开始有些乱了，领袖赶快稳住阵形！\n" NOR, member);

                        remove_call_out("array_running");
                        call_out("array_running", 2, leader, member);
                        return ;
                }
        }
        enemy = leader->query_enemy();
        if( !sizeof(enemy) ) {
                for(i = 0;i < sizeof(member);i++) {
                        if( member[i] == leader )       continue;
                        if( sizeof(enemy = member[i]->query_enemy()) )  break;
                }
        }
        if( sizeof(enemy) ) {
                for(i = 0;i < sizeof(member);i++) {
                        member[i]->clean_up_enemy();
                        for(j = 0;j < sizeof(enemy);j++)
                                member[i]->fight_ob(enemy[j]);
                }
        }

        leader->set_temp("array_async_times", 0);
        remove_call_out("array_running");
        call_out("array_running", 2, leader, member);
}

int dismiss(object leader, object *member)
{
        int i;

        if( !leader->query_temp("array") )
                return notify_fail("你的队伍目前并没有组成任何阵形。\n");

        message("team", MAG "【队伍】：" + leader->name() + "把圣火阵法解散了。\n" NOR, member);
        for(i=0;i< sizeof(member) ;i++ ) {
member[i]->delete_temp("array");
member[i]->add_temp("apply/strength", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/dexerity", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/damage", -(int)leader->query_skill("shenghuo-zhenfa"));
member[i]->add_temp("apply/armor",-(int)(leader->query_skill("shenghuo-zhenfa")*2));
        }

        return 1;
}

// This function is called by COMBATD.C, to provide co-protect within array
int protect(object me, object who, int damage_bonus)
{
        return 0;
}