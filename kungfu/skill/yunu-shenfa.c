// yunu-shengfa 玉女身法
#include <ansi.h>;
inherit SKILL;

string *dodge_msg = ({
HIW"$n一招「洛神凌波」，长袖舞动，掩住身形去处，轻飘飘腾身丈外，躲过了$N这一招。\n"NOR,
HIR"$n嫣然一笑，风姿绝代，$N惊为天人，手下不由一顿，$n已借这「一笑倾国」之势，
避开了$N的凌厉攻势。\n"NOR,
 HIG"$n使出「贵妃醉酒」，满面红晕，脚步踉跄中已饶至$N的身后。\n"NOR,
HIC"$n左足点地，眼看$N杀招堪堪袭来，左膝一弯，右腿踢出，正是一招「红拂夜奔」，
身躯已借势平移，闪过一旁。\n"NOR,
HIY"$n一式「绿珠坠楼」，身体贴地滑行，真叫人匪夷所思，令$N的攻击已然扑空。\n"NOR,
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me)
{
          if((int)me->query("qi") < 30 )
         return notify_fail("你该休息一下了，等会再练玉女身法吧。\n");
          me->receive_damage("qi", 30);
        return 1;
}

