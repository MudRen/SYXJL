// chgkf.c

// writed by shadow



inherit F_CLEAN_UP;



int main(object me, string arg)

{

	string objname,status;

	object obj;

	mapping skills;

	int percent,i;

	string *skname,tmp;



	if( arg ) {

        status=(string)SECURITY_D->get_status(me);

        if ( status!= "(admin)" )

		return notify_fail("�㲻��ִ���������\n");

	}

	else

		return notify_fail("ָ���ʽ��chgkf playid xx%\n");

	if (sscanf(arg, "%s %d%s",objname,percent,tmp)!=3 || percent==0 || tmp!="%") 

		return notify_fail("ָ���ʽ��chgkf playid xx%\n");

	obj = find_player(objname);

	if(!obj)

		return notify_fail("�Ҳ���ָ������ҡ�\n");

	skills = me->query_skills();

	if( mapp(skills) ) {

		skname = keys(skills);

		for (i=0; i<sizeof(skname); i++)

		{

			skills[skname[i]] *= percent;

			skills[skname[i]] /= 100;

		}

	}

	obj->set("combat_exp",obj->query("combat_exp")*percent/100);

	if( obj != me ) log_file("static/CALL_PLAYER",

		sprintf("%s(%s)�޸�%s(%s)֮�����޸ĺ�ٷݱ�Ϊ %d�� on %s\n",

			me->name(1), geteuid(me), obj->name(1), geteuid(obj), percent,

			ctime(time()) ) );

	printf("���޸���%s(%s)�����й���(��������)���޸ĺ�ٷݱ�Ϊ %d��\n",

		obj->name(1), geteuid(obj), percent );

	return 1;

}



int help(object me)

{

write(@HELP

ָ���ʽ : chgkf player percent% ...... )

 

����ҵ��书����(��������)��ΪĿǰ�İٷ�֮ percent .

 

HELP

    );

    return 1;

}

