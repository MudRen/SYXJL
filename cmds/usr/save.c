// save.c by rhxlwd 99.02
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
                  return notify_fail(HIR"�����̾��顿�㲻�Ǿ����������߽��룬���ܴ��档\n"NOR);
/*
        if ( ((int)time() - (int)me->query("save_time")) < 120 )
                 return notify_fail("����̶Է�����Ӳ�̽����к������һ����� save �ɡ�\n");
*/

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
                    write("�����´����߽���ʱ��������￪ʼ��\n");
	}

	if( (int)link_ob->save() && (int)me->save() ) {
            write(HIR"�����̾��顿 ��������ɹ���\n"NOR);
                me->set("save_time", time());
		return 1;
	} else {
                  write(HIR"�����̾��顿 ����ʧ�ܡ�\n"NOR);
		return 0;
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ��save

��������ܶ��Ľ����������
HELP
	);
	return 1;
}
