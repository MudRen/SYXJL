// hp cmds (Mon  09-04-95)

#include <ansi.h>

inherit F_CLEAN_UP;

string *force_status_msg = ({
    	HIR"����"NOR,
    	RED"ƫ��"NOR,
    	HIW"��������"NOR, 
        HIC"ƫ��"NOR,
    	MAG"����"NOR, 
    	MAG"����"NOR    	
    });
string status_color(int current, int max);
int potential_lv(int exp);

int main(object me, string arg)
{
        object ob,weapon;
        mapping my;
        string line,skill_type,force_status;
	int i;
        seteuid(getuid(me));

        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
                if( !ob->is_character() || ob->is_corpse())
                        return notify_fail("��" + ob->query("name") + "��״̬ҲҪ�鿴����������Ĭ��\n");
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();

    if ( objectp(weapon = ob->query_temp("weapon")) )
    	skill_type = weapon->query("skill_type");
    else
    	skill_type = "unarmed";

    if ( my["yin"] || my["yang"] )
    {
        i = my["yin"] * 5 / ( my["yin"] + my["yang"] );    
        force_status = force_status_msg[i];
    }
    else 
        force_status = "δ֪";
        write(HIW" ��"HIG+ob->name()+HIW"����״̬�б�\n");
        
        printf( HIC"��"NOR"������������������������������������������������������������������"HIC"��\n\n"NOR);
        printf(CYN" �� ���� ���� "NOR"%s%4d / %4d %s(%3d%%)" NOR CYN"    �� ���� ����%s%4d / %4d (+%d)\n" NOR,
                status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),   my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["jingli"], my["max_jingli"]),   my["jingli"], my["max_jingli"],
                my["jiajing"] );
        printf(CYN" �� ��Ϣ ���� "NOR"%s%4d / %4d %s(%3d%%)" NOR CYN"    �� ���� ����%s%4d / %4d (+%d)\n" NOR,
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
                status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
                my["jiali"] );
        printf(WHT" �� ʳ�� ����"NOR" %s%4d / %4d      " NOR WHT"     �� Ǳ�� ����%s%4d / %4d\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIG,
        (int)ob->query("potential") - (int)ob->query("learned_points"), potential_lv(my["combat_exp"]) );
        printf(WHT" �� ��ˮ ����"NOR" %s%4d / %4d      " NOR WHT"     �� ���� ����  %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM,
        my["combat_exp"] );
        write(sprintf(HIR" �� ��־ ����"NOR" %s%4d / %4d" NOR,
                HIG,my["douzhi"], my["eff_douzhi"]));        
   line = sprintf(HIR"           �� ���� ����"HIG" %s\n"NOR,force_status ); 
   write(line);       
printf( HIC"\n��"NOR"��������������������������������������������������"HIG"SYXJL"NOR"����������"HIC"��\n\n"NOR);
        return 1;
}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��

see also : score
HELP
    );
    return 1;
}
