 // angle
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string display_attr(int gift, int value);
string bar_string = "■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□";
string none_string = "                                  ";
string display_attr(int gift, int value);
string tribar_graph(int val, int eff, int max, string color);
int check_cc(string str);
void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
         string line,my_str,my_dex,my_con,my_int,my_kar,my_per,skill_type,master,couple,killer;
         mapping my,pmap;
         object ob, weapon;
         int i, cc_len, attack_points, dodge_points, parry_points;
         seteuid(getuid(me));
         if(!arg)
                 ob = me;
         else if (wizardp(me)) {
                 ob = present(arg, environment(me));
                 if (!ob) ob = find_player(arg);
                 if (!ob) ob = find_living(arg);
                 if (!ob) return notify_fail("你要察看谁的状态？\n");
                 if( !ob->is_character() || ob->is_corpse() )
                         return notify_fail("连" + ob->query("name") + "的状态都要查看？？你真幽默。\n");
         } else
                 return notify_fail("只有巫师能察看别人的状态。\n");
         my = ob->query_entire_dbase();
         my_str = display_attr(my["str"], ob->query_str());
         my_con = display_attr(my["con"], ob->query_con());
         my_int = display_attr(my["int"], ob->query_int());
         my_dex = display_attr(my["dex"], ob->query_dex());
         if(wizardp(me)||me->query("age")>17)
         {
         	my_kar = display_attr(my["kar"], ob->query_kar());
         	my_per = display_attr(my["per"], ob->query_per());
         }
         else
         {
         	my_kar = "???";
         	my_per = "???";
         }

//         killer = my["kill"]?"「" + my["killer_name"] + "」之手":"你还没被人杀过";
//      killer = this_player()->query("kill/killer_die") ? "「" + this_player()->query("kill/killer_name") + "」之手":"你还没被人杀过";
        killer = ob->query("kill/killer_die") ? "「" + ob->query("kill/killer_name") + "」之手":"你还没被人杀过";
        pmap = me->query_skill_prepare();
         if( objectp(weapon = me->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
         else if ( sizeof(pmap) == 0) skill_type = "unarmed";
         else if ( sizeof(pmap) == 1) skill_type = (keys(pmap))[0];
         else if ( sizeof(pmap) == 2) 
                 {
                         if ( (keys(pmap))[0] >= (keys(pmap))[1] )
                                 skill_type = (keys(pmap))[0];
                         else skill_type = (keys(pmap))[1];
                 }
         attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
         parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
         dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
         master = ob->query("family")?my["family"]["master_name"]:"目前还没有" ;
         couple = mapp(my["couple"])?(my["couple"]["have_couple"]?my["couple"]["couple_name"]:"目前还没有"):"目前还没有";
         line = "\n┏━━━━━"+HIR"【个人档案】"NOR"━━━━┓ "+HIG"天赋"NOR"\n";
         line += sprintf("%-32s┃%s\n",
         "┃",
         CYN"       膂力：["NOR+my_str+CYN"]     悟性：["NOR+my_int+CYN"] "NOR
         );
         line += sprintf("%s%-32s┃%s\n",
         "┃ 头  衔 :     ",RANK_D->query_rank(ob),
         CYN"       根骨：["NOR+my_con+CYN"]     身法：["NOR+my_dex+CYN"]"NOR
         );
         line += sprintf("%s%-15s┃%s\n",
         "┃中文姓名:      ",ob->name(),       
         CYN"       福缘：["NOR+my_kar+CYN"]     容貌：["NOR+my_per+CYN"]"NOR
         );
         line += sprintf("%s%-15s%39s\n",
         "┃英文姓名:      ",ob->query("id"),"┗━━━━━━━━━━━━━━━━━━━━┓" );
         if( ob->query("title") )
         {
                 line += sprintf("%s%-57s",
                 "┃ 称  谓 :      ",ob->query("title") );
                 for (i=0,cc_len=check_cc(ob->query("title"));i<cc_len;i++)
         {
                        line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","┃\n");
         }
         if( ob->query("nickname") )
         {
                 line += sprintf("%s%-57s",
                 "┃你的别称:      ",ob->query("nickname")
                 );
                 for (i=0,cc_len=check_cc(ob->query("nickname"));i<cc_len;i++) {
                         line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","┃\n");
        }
         line += sprintf("%s%-16s%s%-28s┃\n",
         "┃ 年  龄 :      ",chinese_number(ob->query("age"))+"岁","你的生辰是 ：",
         CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60) )
         );
         line += sprintf("%s%-16s%12s%-28s┃\n",
         "┃ 性  别 :      ", ob->query("gender"),
         "游戏时间:    ",FINGER_D->age_string( (int)ob->query("mud_age")),);
                 line += sprintf("%s"HIW"%-16s"NOR"%s"WHT"%-29s"NOR"┃\n",
                 "┃战斗攻击力:    ",
                   attack_points/5+1+" (+"+ob->query_temp("apply/damage")+")",
                 "江湖威望:   ",display_attr(my["weiwang"], ob->query("weiwang"))
                 );
         line += sprintf("%s"HIW"%-16s"NOR"%s"WHT"%-29s"NOR"┃\n",
                 "┃战斗防御力:    ",
                 (dodge_points + (weapon? parry_points: (parry_points/10)))/5+1+" (+"+ob->query_temp("apply/armor")+")",
                 "魅力值:     ",display_attr(my["meili"], ob->query("meili"))
                 );
         line += sprintf("%s%-32s%s%-23s┃\n",
                 "┃你一共杀生:    ",HIR+(my["MKS"] + my["PKS"])+NOR+" 次",
                 "你的师傅是:       ",master
                 );
         line += sprintf("%s%-32s%s%-23s┃\n",
		"┃你一共杀了:    ",HIC+my["PKS"]+NOR+" 个玩家",
                 "你的"+(ob->query("gender")=="男性"?"老婆":"老公")+"是:       ",couple  
         );
         line += sprintf("%s%-32s%s"HIR"%-23s"NOR"┃\n",
                 "┃你一共死亡:    ",HIB+ob->query("kill/killer_die")+NOR + " 次",
                 "最后一次死于:     ",killer
                 );                      
         line += sprintf("%s%-32s%s%-47s┃\n",
		"┃综合评价：     ",HIC+ob->query("score")+NOR, "食物:  ",
         tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL)
         );
         line += sprintf("%s%-30s%s%-29s┃\n",
         "┃你现在的神:    ",RED+ob->query("shen")+NOR        ,"饮水： ",
         tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN)
         );
         line += sprintf("%s"HIY"%-15s"NOR"%s%-20s┃\n",
         "┃ 潜  能 ：     ",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         " <精>   ",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"] , GRN),
         );
         line += sprintf("%s"HIM"%-15d"NOR"%s%-28s┃\n",
         "┃实战经验：     ",ob->query("combat_exp")," <气>   ",
         tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR)
         );
         line +="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
         write(line);
         return 1;
}
string display_attr(int gift, int value)
{
         if( value > gift ) return sprintf( HIY "%3d" NOR, value );
         else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
         else return sprintf("%3d", value);
 }
string tribar_graph(int val, int eff, int max, string color)
{
         return color + bar_string[0..(val*17/max)*2-1]
                 + ((eff > val) ? blank_string[(val*17/max)*2..(eff*17/max)*2-1] : "")
                 + ((max > eff) ? none_string[(eff*17/max)*2..34] : "")
                 +NOR;
}
int check_cc(string str)
{
         int i, nn_len;
         for (nn_len=0,i=0;i<strlen(str);i++) {
                 if (str[i]==27)
                 {
                         for (;str[i]!=109;i++)
                         {
                                 nn_len++;
                         }
                         nn_len++;
                 }
         }
         return nn_len;
}



