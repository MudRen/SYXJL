// look.c
// modify by Byt@J.H.Y.J 12/99
// 增加四季的场景变化及雨雪时的天气变化。
// Room 必须增加long_spring long_summer long_autumn long_winter
// 或者在需要产生四季变化的房间增加特殊属性，否则影响全部room

#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
#include <look_msg.h>
#define TIME_CHECK NATURE_D->outdoor_room_description()
#define SEASON_CHECK NATURE_D->outdoor_room_description()
#define RAIN_CHECK NATURE_D->outdoor_room_description()
string do_query(object obj);
string tough_level(int power, int hide_level);
string gettof(object obj);

string getdam(object obj);
void create() { seteuid(ROOT_UID); }

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string combat_level(int);

//void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i, j, k, l, night_check, char_p, obj_p,season_check,day_check;
	object *inv;
	mapping exits, *data;
	string str, *dirs;

	k = 0;
	data = allocate(3000);
	if( !env ) {
		write("你的四周灰蒙蒙地一片，什么也没有。\n");
		return 1;
	}
	if((strsrch(TIME_CHECK, "夜晚") != -1 || strsrch(TIME_CHECK, "深夜") != -1)
	&& env->query("outdoors") != 0
	&& (!me->query_temp("night/light") || !present(me, env))
	&& !wizardp(me) )
		night_check = 1;
	else night_check = 0;

	if(env->query("day_change"))	
	{
	if((strsrch(TIME_CHECK, "下午") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 6;			
	else if((strsrch(TIME_CHECK, "凌晨") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 2;		
	else if((strsrch(TIME_CHECK, "清晨") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 3;		
	else if((strsrch(TIME_CHECK, "上午") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 4;			
	else if((strsrch(TIME_CHECK, "正午") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 5;		
	else if((strsrch(TIME_CHECK, "深夜") != -1) && env->query("outdoors") == 0 || !present(me, env))
		day_check = 1;
	else if((strsrch(TIME_CHECK, "傍晚") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 7;			
	else if((strsrch(TIME_CHECK, "夜晚") != -1)
	 	&& env->query("outdoors") == 0 || !present(me, env))
		day_check = 8;			
	}
	if(env->query("season"))
	{
	if((strsrch(SEASON_CHECK, "初春的") != -1 || strsrch(TIME_CHECK, "早春二月的") != -1 || strsrch(TIME_CHECK, "阳春三月的") != -1)
	 || !present(me, env)
	&& !wizardp(me) )
		season_check = 1;
	else if((strsrch(SEASON_CHECK, "初夏的") != -1 || strsrch(TIME_CHECK, "盛夏的") != -1 || strsrch(TIME_CHECK, "仲夏的") != -1)
	 || !present(me, env)
	&& !wizardp(me) )
		season_check = 2;
	else if((strsrch(SEASON_CHECK, "初秋的") != -1 || strsrch(TIME_CHECK, "秋高气爽的") != -1 || strsrch(TIME_CHECK, "深秋的") != -1)
	 || !present(me, env)
	&& !wizardp(me) )
		season_check = 3;
	else if((strsrch(SEASON_CHECK, "初冬的") != -1 || strsrch(TIME_CHECK, "隆冬的") != -1 || strsrch(TIME_CHECK, "寒冬的") != -1)
	 || !present(me, env)
	&& !wizardp(me) )
		season_check = 4;
	}
	else season_check = 0;

	if( night_check ) {
		str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
			env->query("short"),
			wizardp(me)? file_name(env): "",
			"夜晚了，你虽然睁大了眼睛仔细观看，可还是看不清楚周围的事物。\n"+
                           "一切都被夜色所笼罩，连脚下的道路都模糊不清了... \n",
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
	}
	else {
	        switch( season_check ) {
	                case 1:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_spring"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 2:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_summer"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 3:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_autumn"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 4:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_winter"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 0:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
		}
	}
	        switch( day_check ) {
	                case 1:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day1"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 2:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day2"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 3:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day3"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 4:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day4"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 5:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day5"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 6:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day6"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}						
	                case 7:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day7"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}
	                case 8:
			{
				str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR +  " - %s\n    %s%s",
				env->query("short"),
				wizardp(me)? file_name(env): "",
				env->query("long_day8"),
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
				break;
			}				
		}	
	if((strsrch(RAIN_CHECK, "雨") != -1)
	&& env->query("outdoors") != 0 || !present(me, env)
	&& !wizardp(me) )
		str += "    刚下过雨，地上到处都是一洼一洼的积水。\n"; 
	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    这里没有任何明显的出路。\n";
			

                else if(night_check&&random(me->query_con()) < 35){
                        i = random(sizeof(dirs));
                        if( random(me->query_con()) < 10) i = 0;
                        else if( random(me->query_con()) < 20) i = 1;
                        if( i <= 0 )
                                str += "    这里看不见任何明显的出路。\n";
                        else if( i == 1 )
                                str += "    这里看得见的唯一出口是 " + BOLD + dirs[i-1] + NOR + "。\n";
                        else str += sprintf("    这里看得清的出口是 " + BOLD + "%s" + NOR + "。\n", implode(dirs[1..i], "、"));
                        }
			
		else if( sizeof(dirs)==1 )
			str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
		else
			str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
				implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	if( night_check ) {
		for (i = 0; i < sizeof(inv); i++) {
			if (inv[i]!=me && me->visible(inv[i]) && living(inv[i])) {
				char_p = 1;
				if (inv[i]->query_temp("night/light")) {
					str += "  " + inv[i]->short() + "正举着一个" + HIR + inv[i]->query_temp("night/light") + NOR + "东张西望。\n";
				}
			}
			else if (!living(inv[i]) || !inv[i]->is_character())
				obj_p = 1;
		}
		if (char_p)
			str += "  一些模糊的影子，显然看不清楚。\n";
		if (obj_p)
			str += "  一堆模糊的东西，显然看不清楚。\n";
	}
	else {
		for (i = 0; i < sizeof(inv); i++) {
			if (inv[i]!=me 
			&&  me->visible(inv[i])
			&&  !inv[i]->query("money_id")
			&&  !inv[i]->query_temp("check_only"))
			{
				data[k]=([]);
				for(j = i; j < sizeof(inv); j++ )
				{
					if ( inv[i]->query("name")==inv[j]->query("name")
					&&   inv[i]->query("id")==inv[j]->query("id")
					&&   !inv[j]->query_temp("check_only") )
					{
						data[k]["id"]=inv[i]->short();
						data[k]["unit"]=inv[i]->query("unit");
						data[k]["num"]= data[k]["num"] + 1;
						inv[j]->set_temp("check_only", 1);
					}
					else continue;
				}
				k++;
			}
			else continue;
		}

		for (i = 0; i < sizeof(inv); i++) {
			if ( !inv[i]->query_temp("check_only") && inv[i]!=me && me->visible(inv[i]) )
			str += sprintf("%s%s\n", "  ", inv[i]->short());
		}

		for (i = 0; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("check_only") )
				inv[i]->delete_temp("check_only");

		if (k > 0)
		{
			for (l = 0; l < k; l++)
				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
		}
	}

	write(str);
	return 1;
}

int look_item(object me, object obj)
{
        object hob;
        mixed *inv;
        mapping count;
        mapping equiped;
        mapping unit;
        string short_name;

        string str;
        string *dk;
        int i;

        count   = ([]);
        unit    = ([]);
        equiped = ([]);

        str = obj->long();
        while (mapp(obj->query_temp("daub")))
        {
                if (! obj->query_temp("daub/poison/remain"))
                        // no poison remain now
                        break;

                if (obj->query_temp("daub/poison/id") == me->query("id"))
                {
                        str += HIG "你发现这上面还有你炼制的" +
                               obj->query_temp("daub/poison/name") +
                               HIG "呢。\n" NOR;
                        break;
                }

                if (obj->query_temp("daub/who_id") == me->query("id"))
                {
                        str += HIG "这上面还有你亲手布下的" +
                               obj->query_temp("daub/poison/name") +
                               HIG "呢。\n" NOR;
                        break;
                }

                if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
                        // nothing was worked out
                        break;

                str += HIG "忽然间你发现上面似乎泛着一些奇异荧光，";
                if (me->query_skill("poison", 1) >= 120)
                {
                        str += "可能是" + obj->query_temp("daub/poison/name") +
                               "。\n" NOR;
                        break;
                }

                str += "。\n" NOR;
                break;
        }

        inv = all_inventory(obj);
        if (! sizeof(inv))
        {
                message("vision", str, me);
                return 1;
        }

        if (obj->is_corpse())
        {
                if (objectp(hob = obj->query_temp("handing")))
                {
                        str += "手中还死死握着一" + hob->query("unit") +
                              hob->name() + "，";
                        inv -= ({ hob });
                        if (! sizeof(inv))
                                str += "没有什么其他遗物了。\n";
                        else
                                str += "里面的遗物有：\n";
                } else
                        str += "里面的遗物有：\n";
        } else
                str += "里面有：\n";

        for (i = 0; i < sizeof(inv); i++)
        {
                short_name = inv[i]->short();
                if (undefinedp(count[short_name]))
                {
                        count += ([ short_name : 1 ]);
                        unit += ([ short_name : inv[i]->query("unit") ]);
                }
                else
                        count[short_name] += 1;

                if (inv[i]->query("equipped"))
                        equiped[short_name] = 1;
        }

        dk = keys(count);
        dk = sort_array(dk, 1);
        for (i = 0; i < sizeof(dk); i++)
        {
            if (equiped[dk[i]])
                str += HIC "  □" NOR;
            else
                str += "    ";

            if (count[dk[i]] > 1)
                str += chinese_number(count[dk[i]]) + unit[dk[i]];
            str += dk[i] + "\n";
        }

        message("vision", str, me);
        return 1;
}


int look_living(object me, object obj)
{
	string str, pro, skill_type;
	object weapon;
	mixed *inv;
	mapping my_fam, fam;
	int me_shen, obj_shen, per_temp, attack_points;

	me_shen = (int)me->query("shen");
	obj_shen = (int)obj->query("shen");

	if( me!=obj )
		message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

	str = obj->long();

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	per_temp= (obj->query_per()>=32)?20:(obj->query_per()-12);
	if ( per_temp < 0 ) per_temp=0;
	if ( (string)obj->query("race")=="人类" ) {
		if ( (string)obj->query("gender") == "女性")
			str += sprintf("%s长得%s。\n", pro,
				look_level_girl[per_temp]);
		else
			str += sprintf("%s长得%s。\n", pro,
				look_level_boy[per_temp]);
	}

	if( objectp(weapon = obj->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(obj, skill_type, SKILL_USAGE_ATTACK);
	str +=sprintf("%s的武艺看上去", pro);
        str +=gettof(obj);
        str +="，";
        str +=sprintf("出手似乎");
        str +=getdam(obj);

	if( (string)obj->query("race")=="人类"
	&&	intp(obj->query("age")) )
            str += sprintf("。\n%s看起来约%s多岁。\n"+"这时候%s%s\n", pro,chinese_number(obj->query("age") / 10 * 10),pro,bel_status_msg((int)obj->query("shen"), obj->query("gender")) );

	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = obj->query("family"))
	&&	mapp(my_fam = me->query("family"))
	&&	fam["family_name"] == my_fam["family_name"] ) {

		if( fam["generation"]==my_fam["generation"] ) {
			if( (string)obj->query("gender") == "男性" ||
				(string)obj->query("gender") == "无性")
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
			else
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "是你的师父。\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "是你的同门长辈。\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "是你的师伯。\n";
			else
				str += pro + "是你的师叔。\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "是你的同门晚辈。\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "是你的弟子。\n";
			else
				str += pro + "是你的师侄。\n";
		}
	}

	if( obj->query("id") == me->query("couple/couple_id"))
		str += pro + "是你的" + me->query("couple/couple_gender") + "。\n";

	if( obj->query("max_qi") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";
      	
      	if (obj->query_temp("daub/poison/remain") &&
            (me == obj || random((int)me->query_skill("poison", 1)) > 80))
        {
                str += pro + HIG "身上现在" + (me == obj ? "" : "似乎") +
                       "淬了" + (me == obj ? obj->query_temp("daub/poison/name") : "毒") +
                       NOR "。\n";
        }
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
                          str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "只见%s：\n%s\n",
				pro, implode(inv, "\n") );
		if ( !obj->query_temp("armor/cloth") && obj->query("race")=="人类" )
			str+=pro+"光着"+YEL+"身子"+NOR+"，什么也没穿！\n";
	}
	else
		str += sprintf( obj->is_corpse() ? "%s的遗体上什么也没有。\n" : ( obj->query("race")=="人类"
			?"%s光着"+YEL+"身子"+NOR+"，什么也没穿！\n":"它的身上没有任何东西。\n"),pro);
	message("vision", str, me);

// Modified by Hop
	if( obj!=me && living(obj)
	&& (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
	&& (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
	|| ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
	{
		write( obj->name() + "突然转过头来瞪你一眼。\n");
		if(obj->query("age") > 15 && me->query("age") > 15)
			COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;
	str = obj->short();

	if( obj->query("equipped") )
		str = HIC "  √" NOR + do_query(obj);

	else if( !flag )
		str = "    " + str;

	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));

		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("你要看什么？\n");
}


string do_query(object obj)
{
        string str,units;

        units =obj->query("unit");
        str = obj->short();
        if (obj->query("armor_type"))
        switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":
                        str = "身穿一"+ units + str;
                        break;
                case "boots":
                        str = "脚上穿着一" + units + str;
                        break;
                case "head":
                case "neck":
                case "wrists":
                case "finger":
                case "hands":
                        str ="戴着一"+ units + str;
                        break;
                case "waist":
                        str = "腰间绑得有一"+units+str;
                        break;
                default:
                        str = "装备着"+str; 
                        }
        else
        if( obj->wield() )
                if (obj->query("skill_type")=="throwing")
                str ="身上带着"+str;
                else
                str ="手持一" + units + str;
        return str;     
}


string gettof(object ob)
{
        object weapon;

        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points, hide_level);
        return tough_level(attack_points, 0);
}

string tough_level(int power, int hide_level)
{

        int lvl, rawlvl;
        if(power<0) power=0;
        rawlvl = (int) pow( (float) 1.0 * power, 0.2);
        lvl = to_int(rawlvl);
        
        if(hide_level)
            lvl = hide_level;
        if( lvl >= sizeof(tough_level_desc) )
            lvl = sizeof(tough_level_desc)-1;
        
        return tough_level_desc[lvl];
}

string getdam(object obj)
{
        int level;
        level = obj->query_temp("apply/damage");
        level += obj->query_str();
        level += obj->query("jiali");
        level += obj->query("neili")/60;
        level += obj->query("max_neili")/30;
        level = level / 100;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}

int help (object me)
{
	write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。

HELP
);
	return 1;
}

