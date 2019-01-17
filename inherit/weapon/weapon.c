
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif
#include <ansi.h>
// axe.c
varargs void init_axe(int damage, int flag)
{

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "axe");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "chop", "slice", "hack" }) );
	}
}


// blade.c
varargs void init_blade(int damage, int flag)
{

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
}

// falchion.c
varargs void init_falchion(int damage, int flag)
{

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "falchion");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "chop", "hack" }) );
	}
}

// club.c
varargs void init_club(int damage, int flag)
{

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "club");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// dagger.c

varargs void init_dagger(int damage, int flag)
{


	set("weapon_prop/damage", damage);
	set("flag", flag | EDGED | SECONDARY );
	set("skill_type", "dagger");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slice", "pierce", "thrust" }) );
	}
}

// fork.c

varargs void init_fork(int damage, int flag)
{


	set("weapon_prop/damage", damage);
	set("flag", (int)flag | POINTED);
	set("skill_type", "fork");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "thrust" }) );
	}
}

// hammer.c

varargs void init_hammer(int damage, int flag)
{


	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "hammer");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// staff.c

varargs void init_staff(int damage, int flag)
{


	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "staff");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// sword.c


varargs void init_sword(int damage, int flag)
{


	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

// whip.c

varargs void init_whip(int damage, int flag)
{


	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "whip");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
	}
}


int set_desc(int w_lv,string w_or,string w_name)
{
	object weapon,me;
	string w_liang, player_name, make_time, name;
	string result1,result2,result3,result4,result;
	int color;

	weapon = this_object();
	me = this_player();
	w_liang = weapon->query("unit");
	player_name=me->query("name");
	make_time=me->query("weapon/time");
	color = w_lv;
//	color = w_lv - color*10;
	switch(color){
		case 1:
		case 2:
			name = HIR + w_name + NOR;
			break;
		case 3:
		case 4:
			name = HIG + w_name + NOR;
			break;
		case 5:
			name = HIY + w_name + NOR;
			break;
		case 6:
			name = HIM + w_name + NOR;
			break;
		case 7:
			name = MAG + w_name + NOR;
			break;
		case 8:
			name = HIW + w_name + NOR;
			break;
		case 9:
			name = HIC + w_name + NOR;
			break;
		default:
			name = HIB + w_name + NOR;
			break;
	}

	switch(w_or) {
		case "ǧ����ľ":
	                result1="\t      ����һ"+w_liang+"��"+w_or+"������ɵ�"+ name + "��\n";
		        result2="����������͸�죬�ƺ�ʮ�ּ�Ӳ��";
			break;
		case "���׽�ĸ":
	                result1="\t      ����һ"+w_liang+"��"+w_or+"������ɵ�"+ name + "��\n";
			result2="�������ϳγεģ��ƺ�ʮ�ֳ��ء�";
			break;
		case "��˿����":
	                result1="\t      ����һ"+w_liang+"��"+w_or+"������ɵ�"+ name +"��\n";
			result2="��������Ө���̣�͸��˿˿�ĺ��⡣";
			break;
		default:
			break;
		}
	switch(w_lv) {
		case 1:
			result3="���ƺ�������û�п�����������ϰ��֮\n�˳��õ����������\n";
			break;
		case 2:
			result3="���ƺ����������ܴ����ǽ����˳���\n�Ļ�����С�\n";
			break;
		case 3:
			result3="������ɢ����һ˿���˲�������Ϣ��\n";
			break;
		case 4:
			result3="ɢ����һ˿���˲�������Ϣ�� ��Ȼ��ͨ\n�����Ѳ��ܺ�������ˡ�\n";
			break;
		case 5:
			result3="����ɢ����һ˿���ɵ�����������һ��\n����ɢ���˳�����\n";
			break;
		case 6:
			result3="һ�ɰ���ֱ��������ֱ���񾪹�����\n";
			break;
		case 7:
			result3="�����ƺ������������������������һ��\n���˵�������\n";
			break;
		case 8:
			result3="������������˿��˲����ľ���ս����Ը\n�ٿ��ڶ��ۡ�\n";
			break;
		case 9:
 	 	        result3="�����ƺ������˲��٣�һ���º͵�����֮\n��͸�˳�����\n";
			break;
		case 10:
			result3="һ���º͵�����֮�����Ƶ�ɢ���˳�����\n";
			break;
		default:
			result3="һ��ׯ�ϣ��ºͣ���Ȼ�������ַ�����Ϣ��\n�˲�����һ˿����֮�⣬ ���Ѿ����ӹ��棬��Ϊ�������Ϲ������ \n";
		}

	result4="������С׭����һ��С�֣�"+player_name+"����"+make_time+"\n";
	result=result1+result2+result3+result4;
	weapon->set("long", result);

}