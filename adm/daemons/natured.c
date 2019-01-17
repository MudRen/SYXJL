// natured.c
#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
// TIME_TICE1 also use in move.c look.c
nosave int current_day_phase, current_month;
mapping *day_phase;
nosave string ppl;
string *month_time = ({
	"�������ĵ������ˣ�",
	"��������ط���������ӣ�",
	"�����𽥱�ů�ˣ�",
	"�Ѿ��ǳ���ʱ���ˣ�",
	"֪�˵Ľ�������о�����ʢ�ĵ���Ϣ��",
	"������÷ǳ����ȣ�",
	"��Ȼ�������ˣ�����������Щ�ȣ�",
	"����ѽڿ쵽�ˣ�",
	"һ����紵���������˵��ϵ���Ҷ��",
	"��ȥ������",
	"����������",
	"�쵽����ˣ�",
});

string *month_desc = ({
	HIW"¡����"NOR,
	HIW"������"NOR,
	HIG"������"NOR,
	HIG"�紺���µ�"NOR,
	HIG"�������µ�"NOR,
	HIC"���ĵ�"NOR,
	HIC"ʢ�ĵ�"NOR,
	HIR"���ĵ�"NOR,
	HIY"�����"NOR,
	HIY"�����ˬ��"NOR,
	YEL"�����"NOR,
	WHT"������"NOR,
});
/*
string *weather_msg = ({
	"�������������",
	"���䵭�����Ʋ�ױ�������ʵ����",
	"�����������Ʈ��Ʈȥ",
	"�����Ʋ�ѻ������",
	"����������ܲ�",
});
*/
mapping *read_table(string file);
void init_day_phase();

void create()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
                       case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}
	switch(get_day)
	{
		case "һ��һ��":
		     day_phase = read_table("/adm/etc/nature/spring");
		     break;
//		case "��������":
//		case "��������":
//		case "����ʮ����":
//		case "���¾���":
//		case "ʮ���°���":
	}
//	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];           // hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];

	// MUD ����ʱ����ˣ�ʱ�����ƫ������ǵ�������ÿСʱִ��һ��
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.
	remove_call_out("update_day_phase");	

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
//        call_out("test_robot", 5+random(20));
	call_out("update_day_phase", day_phase[current_day_phase]["length"]);

}

string room_event_fun()
{
    return day_phase[current_day_phase]["event_fun"];
}
int get_mon()
{
	int get_month;
	mixed *local;
	local = localtime(TIME_TICK);
	get_month = local[4];
	return get_month;
}
int get_day()
{
	int get_day;
	mixed *local;
	local = localtime(TIME_TICK);
	get_day = local[4];
	return get_day;
}

void test_robot()
{
	object *obs = users(), ob, robot;
 	int i = sizeof(obs), j = 10;

	if (i < 1) return;
	while (j--) {
		ob = obs[random(i)];
		if (wiz_level(ob)) continue;
		if (!living(ob)) continue;
		if (!interactive(ob)) continue;
        if (query_idle(ob) > 30) continue;
		if (!environment(ob)) continue;
		if (ob->query("id") == ppl) continue;
		break;
	}
	if (j < 0) return;
	ppl = ob->query("id");
        robot = new("/clone/npc/antirobot"+(random(2)+2));
	CHANNEL_D->do_channel( robot, "rumor", ob->short(1)+"���ڽ��ܻ����˳�顣");
	robot->test_robot(ob);
}


void event_midnight()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[1]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
           case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}
	switch(get_day)
	{
		case "һ��һ��":
		     day_phase = read_table("/adm/etc/nature/spring");
		     break;
//		case "��������":
//		case "��������":
//		case "����ʮ����":
//		case "���¾���":
//		case "ʮ���°���":
	}
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
	object *ob;
	int i, con, con1, con2, con3;
	string get_month,ill,msg;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		case "��":
		case "��":
		case "��":
		     ill = "ill_kesou";
		     msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
		     break;
		case "��":
		case "��":
		case "��":
		     ill = "ill_zhongshu";
		     msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
		     break;
		case "��":
		case "ʮ":
		case "ʮһ":
		     ill = "ill_shanghan";
		     msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
		     break;
		case "ʮ��":
		case "һ":
		case "��":
		     ill = "ill_dongshang";
		     msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
		     break;
	}
	if(random(2))
	{
		ill = "ill_fashao";msg = HIG+"��ż�з纮����������������\n"+NOR;
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("qi");
		con2 = ob[i]->query("max_qi");
		(int)con = con1/con2*50;//�γɵ�һ�������ж�����
		con3 = ob[i]->query("neili");
		con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;//�γɵڶ��������ж�����
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10);
			tell_object(ob[i], msg);
		}
	}
}
string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "��\n";
}
/*
string outdoor_room_outcolor()
{
	return day_phase[current_day_phase]["outcolor"];
}
*/
string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}
int auto_shutdown(int flag)
{
    reclaim_objects();
    if (172800-uptime()<=0 || flag){
        message("vision", RED "Ҫ�����ˣ����ģ����ĵ����Ѿ��Զ��洢�ˣ�\n" NOR, users());
        users()->disable_player("����������......");
             call_out("backup",1);
    }
}
int backup()
{

    reset_eval_cost();
  foreach (object userob in children(USER_OB) ){
       if (!userob || !environment(userob)) continue;
           userob->save();
           userob->des();
    }
shutdown(0);
return 1;

}

mapping *query_day_phase() { return day_phase; }
