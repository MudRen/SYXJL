//jueqing-chenfa.c  绝情尘法
// csy 1999.05.29
inherit SKILL;
mapping *action =
({
([
"action" : "只见$N纤腰急转，皓腕轻抖，一式「天地双飞」，$w在身畔化作两道飞虹",
"dodge"  : 50,
"damage" : 40,
"parry"  : 15,
"lvl"         : 0,
"skill_name"  : "天地双飞",
"damage_type" : "割伤",
]),
([
"action" : 
"$N默运冰心决，使出「几回寒暑」，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉",
"dodge"  : 40,
"damage" : 50,
"parry"  : 25,
"lvl"         : 10,
"skill_name"  : "几回寒暑",
"damage_type" : "内伤",
]),
([
"action" : 
"$N一式「君应有语」，神色凄楚惘然，$w斜斜舞出，$n心中一凛，只觉得这目光似曾相识，却又说不上来",
"dodge"  : 55,
"damage" : 60,
"parry"  : 25,
"lvl"         : 20,
"skill_name"  : "君应有语",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N霞袖慢垂，莲步急趋，手中$w似影随形，一招「只影向谁」愈显落落欲往，矫矫不群",
"dodge"  : 30,
"damage" : 70,
"parry"  : 10,
"lvl"         : 30,
"skill_name"  : "只影向谁",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N徐徐舞动$w，却是一招「万里层云」，只见招断意连，缠绵婉转，一尘未绝，便隐隐有万尘相随",
"dodge"  : 40,
"damage" : 80,
"parry"  : 20,
"lvl"         : 40,
"skill_name"  : "万里层云",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「千山暮雪」，$w挥洒自如，霎时间绛雪纷纷，娇如柳絮，弱似梨花，密密裹住$n全身"
,
"dodge"  : 10,
"damage" : 90,
"parry"  : 30,
"lvl"         : 50,
"skill_name"  : "千山暮雪",
"damage_type" : "刺伤",
]),
([
"action" : 
"只见$N一路「寂寞箫鼓」，$w回风舞雪，暗合韵理，虽无丝竹之音，反倒别有幽愁暗恨生，此时无声胜有声",
"dodge"  : 10,
"damage" : 100,
"parry"  : 10,
"lvl"         : 60,
"skill_name"  : "寂寞箫鼓",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「荒烟平楚」，手中$w吞吐不定，仿佛一层轻烟薄雾飘上$n肩头，若即若离，似真似幻，极尽悱恻哀艳之美",
"dodge"  : 20,
"damage" : 110,
"parry"  : 0,
"lvl"         : 70,
"skill_name"  : "荒烟平楚",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一声娇叱，$w上内劲贯注，矫夭飞舞，一路「莺燕黄土」所过之处落英缤纷，红消香断，劲风只刮得$n脸颊生痛",
"dodge"  : 30,
"damage" : 120,
"parry"  : 10,
"lvl"         : 80,
"skill_name"  : "莺燕黄土",
"damage_type" : "内伤",
]),
([
"action" : 
"忽然间$N尘势陡变，$w浏漓顿挫，古意盎然，一式「千秋万古」如月之曙，如气之秋，纵有千载情愁，亦化于这一招之中",
"dodge"  : 10,
"damage" : 130,
"parry"  : 0,
"lvl"         : 90,
"skill_name"  : "千秋万古",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一式「情是何物」，尘意缱绻缠绵，如泣如诉，犹似双丝网，中有千千结，直教$n剪之不断，理之还乱",
"dodge"  : 30,
"damage" : 140,
"parry"  : 10,
"lvl"         : 100,
"skill_name"  : "情是何物",
"damage_type" : "割伤",
]),
([
"action" : 
"$N袖舞时幻起花雨满天，尘落处化作断霞千缕，一式「生死相许」尘人合一，着着抢攻，全然不顾$n进招",
"dodge"  : 20,
"damage" : 150,
"parry"  : 10,
"lvl"         : 110,
"skill_name"  : "生死相许",
"damage_type" : "刺伤",
]),
});

/*
mapping *action_male =
({
([
"action" : "只见$N身形疾转，手腕轻抖，一式「天地双飞」，$w在身畔化作两道飞虹",
"dodge"  : 20,
"damage" : 20,
"force"  : 125,
"lvl"         : 0,
"skill_name"  : "天地双飞",
"damage_type" : "割伤",
]),
([
"action" : 
"$N默运冰心决，使出「几回寒暑」，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉",
"dodge"  : 20,
"damage" : 30,
"force"  : 150,
"skill_name" : "几回寒暑",
"damage_type" : "内伤",
]),
([
"action" : 
"$N一式「君应有语」，神色凄楚惘然，$w斜斜挥出，$n心中一凛，只觉得这目光似曾相识，却�
炙挡簧侠�",
"dodge"  : 25,
"damage" : 40,
"force"  : 175,
"lvl"         : 20,
"skill_name"  : "君应有语",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N云袖慢垂，莲步急趋，手中$w如影随形，一招「只影向谁」愈显落落欲往，矫矫不群",
"dodge"  : 25,
"damage" : 50,
"force"  : 200,
"lvl"         : 30,
"skill_name"  : "只影向谁",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N徐徐舞动$w，却是一招「万里层云」，只见招断意连，缠绵婉转，一尘未绝，便隐隐有万尘�
嗨�",
"dodge"  : 30,
"damage" : 60,
"force"  : 225,
"lvl"         : 40,
"skill_name"  : "万里层云",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「千山暮雪」，$w挥洒自如，霎时间绛雪纷纷，柔如柳絮，弱似梨花，密密裹住$n全身"
,
"dodge"  : 30,
"damage" : 70,
"force"  : 250,
"lvl"         : 50,
"skill_name"  : "千山暮雪",
"damage_type" : "刺伤",
]),
([
"action" : 
"只见$N一路「寂寞箫鼓」，$w回风舞雪，暗合韵理，虽无丝竹之音，反倒别有幽愁暗恨生，此�
蔽奚び猩�",
"dodge"  : 35,
"damage" : 80,
"force"  : 275,
"lvl"         : 60,
"skill_name"  : "寂寞箫鼓",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「荒烟平楚」，手中$w吞吐不定，仿佛一层轻烟薄雾飘上$n肩头，若即若离，似真似幻�
°а拗�",
"dodge"  : 35,
"damage" : 80,
"force"  : 300,
"lvl"         : 70,
"skill_name"  : "荒烟平楚",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一声清啸，$w上内劲贯注，矫夭飞舞，一路「莺燕黄土」所过之处落英缤纷，红消香断，劲�
缰还蔚�$n脸颊生痛",
"dodge"  : 40,
"damage" : 90,
"force"  : 325,
"lvl"         : 80,
"skill_name"  : "莺燕黄土",
"damage_type" : "内伤",
]),
([
"action" : 
"忽然间$N尘势陡变，$w浏漓顿挫，古意盎然，一式「千秋万古」如月之曙，如气之秋，纵有千�
厍槌睿嗷谡庖徽兄�",
"dodge"  : 40,
"damage" : 90,
"force"  : 350,
"lvl"         : 90,
"skill_name"  : "千秋万古",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一式「情是何物」，尘意缱绻缠绵，如泣如诉，犹似双丝网，中有千千结，直教$n剪之不断�
碇孤�",
"dodge"  : 45,
"damage" : 100,
"force"  : 375,
"lvl"         : 100,
"skill_name"  : "情是何物",
"damage_type" : "割伤",
]),
([
"action" : 
"$N袖舞时幻起花雨满天，尘落处化作断霞千缕，一式「生死相许」尘人合一，着着抢攻，全然�
还�$n进招",
"dodge"  : 45,
"damage" : 100,
"force"  : 400,
"lvl"         : 110,
"skill_name"  : "生死相许",
"damage_type" : "刺伤",
]),
});
*/
mapping *action_sanshou =
({
([
"action" : 
"第一招「无孔不入」，乃是向对手全身各处大穴进攻，$n只觉得香风袭袭，周身百骸都是$w的�
白�",
"dodge"  : 30,
"damage" : 160,
"force"  : 350,
"lvl"         : 100,
"skill_name"  : "无孔不入",
"damage_type" : "刺伤",
]),
([
"action" : 
"紧跟着$N使出「无所不至」，虽为一招，其实千头万绪，$w同时点向$n周身诸处偏门穴道",
"dodge"  : 30,
"damage" : 170,
"force"  : 375,
"lvl"         : 100,
"skill_name"  : "无所不至",
"damage_type" : "刺伤",
]),
([
"action" : 
"第三招「无所不为」，不再点穴，而专击$n眼睛、咽喉、小腹、下阴等诸般柔软之处，阴毒无�
�",
"dodge"  : 30,
"damage" : 180,
"force"  : 400,
"lvl"         : 100,
"skill_name"  : "无所不为",
"damage_type" : "刺伤",
]),
});

int valid_enable(string usage) {
    return usage == "whip" || usage == "parry";
}

int valid_learn(object me) {
    if ((int)me->query_skill("force",1) < 150 )
        return notify_fail("你的内功心法修为尚浅，没法学绝情尘法！\n");
    if ((int)me->query_skill("dodge", 1) < 150)
        return notify_fail("你的轻功修为尚浅，没法学绝情尘法！\n");
    return 1;
}

string query_skill_name(int level) {
    int i;
    for (i=sizeof(action)-1; i>=0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}


mapping query_action(object me, object weapon) 
{

    int level = (int)(me->query_skill("jueqing-chenfa", 1));
    int i;
    for (i=sizeof(action); i>=1; i--)
        if (level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
        return action[random(sizeof(action))];

}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "whip")
        return notify_fail("你这才想起手里没拂尘，怎么练绝情尘法啊？ :)\n");
    if ((int)(me->query("qi")) < 50)
        return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("qi", 30);
    return 1;
}

