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

		return notify_fail("你不能执行这个程序。\n");

	}

	else

		return notify_fail("指令格式：chgkf playid xx%\n");

	if (sscanf(arg, "%s %d%s",objname,percent,tmp)!=3 || percent==0 || tmp!="%") 

		return notify_fail("指令格式：chgkf playid xx%\n");

	obj = find_player(objname);

	if(!obj)

		return notify_fail("找不到指定的玩家。\n");

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

		sprintf("%s(%s)修改%s(%s)之功夫，修改后百份比为 %d％ on %s\n",

			me->name(1), geteuid(me), obj->name(1), geteuid(obj), percent,

			ctime(time()) ) );

	printf("你修改了%s(%s)的所有功夫(包括经验)，修改后百份比为 %d％\n",

		obj->name(1), geteuid(obj), percent );

	return 1;

}



int help(object me)

{

write(@HELP

指令格式 : chgkf player percent% ...... )

 

将玩家的武功资料(包括经验)改为目前的百份之 percent .

 

HELP

    );

    return 1;

}

