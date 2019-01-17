// set.c

//    add color availability by ReyGod  in Dec. 1996

 

#define MAX_ENV_VARS	20



#include <ansi.h>



inherit F_CLEAN_UP;

 

int help();

 

int main(object me, string arg)

{

    int i;

	string term, *terms, *usr_only;

	mixed data;

	string data0;

	mapping env;

 

        usr_only = ({"wimpy", "no_tell", "brief", "no_accept", "no_teach", "combat"});
 

	if( me != this_player(1) ) return 0;

 

	env = me->query("env");

 

	if( !arg || arg=="" ) {

		write("��Ŀǰ�趨�Ļ��������У�\n");

		if( !mapp(env) || !sizeof(env) )

			write("\tû���趨�κλ���������\n");

		else {

			terms = keys(env);

			for(i=0; i<sizeof(terms); i++)

				printf("%-20s  %O\n", terms[i], env[terms[i]]);

		}

		return 1;

	}

 



       arg = replace_string(arg, "$BLK$", BLK);

	arg = replace_string(arg, "$RED$", RED);

	arg = replace_string(arg, "$GRN$", GRN);

	arg = replace_string(arg, "$YEL$", YEL);

	arg = replace_string(arg, "$BLU$", BLU);

	arg = replace_string(arg, "$MAG$", MAG);

	arg = replace_string(arg, "$CYN$", CYN);

	arg = replace_string(arg, "$WHT$", WHT);

	arg = replace_string(arg, "$HIR$", HIR);

	arg = replace_string(arg, "$HIG$", HIG);

	arg = replace_string(arg, "$HIY$", HIY);

	arg = replace_string(arg, "$HIB$", HIB);

	arg = replace_string(arg, "$HIM$", HIM);

	arg = replace_string(arg, "$HIC$", HIC);

	arg = replace_string(arg, "$HIW$", HIW);

	arg = replace_string(arg, "$NOR$", NOR);



	if( sscanf(arg, "%s %s", term, data)!=2 ) {

		term = arg;

		data = "YES";

	}

 	

	if( term && term!="" ) {

		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )

			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");

	   data0 = data;	/* save string* data */

	   sscanf(data, "%d", data);

	if( !wizardp(me) && (member_array(term, usr_only) == -1) )

		return notify_fail("��ֻ���趨�ض��Ļ�����������ϸ����뿴help settings��\n");

	   if(data == data0) 		/* if data is �ַ��� */

	         me->set("env/" + term, data + NOR);

	   else  me->set("env/" + term, data);		/* is ���� */

 	 

	  printf("�趨����������%s = %O%s\n", term, data,NOR);

	   return 1;

	}

	return help();

}

 

int help()

{

	write(@TEXT

ָ���ʽ��set <������> [<����ֵ>]

 

���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��

����ֵ�����ڶ�ֵΪ "YES"������ֵ��Ϊ�ַ������ɲ��� nick �仯��ɫ.

for example : set msg_min, msg_mout, msg_home , etc.

 

ȡ�������趨���� unset ָ�

 

�������Щ�������������趨����� help settings��

TEXT

	);

	return 1;

}

