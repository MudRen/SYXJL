// cat.c
// writed by shadow

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("����Ҫ��ʾ�Ǹ�����?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
	if( file_size(file)>16384 ) return notify_fail("��������ĳ��ȳ������ƣ��޷�ֱ����ʾ��\n");
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : cat <����>

��ָ�������(��)ֱ�Ӷ�ȡĳ����֮��ʽ��
HELP
    );
    return 1;
}
