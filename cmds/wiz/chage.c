//change.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object ob,string arg)
{
	message("vision", BLINK HIY"¹�������������ָ��£�����help change��ѯ���������\n"NOR, users());
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: chage
 
֪ͨ���help change��ѯ���¸��¡�
 
HELP
	);
	return 1;
}
