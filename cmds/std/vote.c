// vote command..
// Modified by Marz, 04/18/96

#include <net/dns.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name, channel;
	string file;
	object file_ob;

	if (((int)me->query("age")<16) && !wizardp(me)) {
 		return notify_fail("����δ�����ˣ���û������Ȩ����\n");
	}
    if ( !userp( me ) ) return 0;
	if ((int)me->query("vote/deprived")) {
 		return notify_fail("����������ͶƱȨ��������Ȩ����ʱ�������ˡ�\n");
	}

    if (!arg || sscanf(arg, "%s %s %s", act_name, victim_name, channel) != 3) {
		return notify_fail("��Ҫ��Ū����������㲻֪�����ͶƱ������help vote��\n");
    }
    
         if (channel == "rumor" || channel == "chat" || channel == "ldj" )  {
		victim = LOGIN_D->find_body(victim_name);
        if (!objectp(victim))  return notify_fail("���ϧ������˲������ϡ�\n");       
   		if ( wizardp(victim) ) return notify_fail("��������ӵ����Ȩ�����κ������ã����������Ű������·�����˵�ɡ�\n");
	}
 	else return notify_fail("������ֻ��ͶƱ�رջ��ĳ�˵�����Ƶ����\n");

/*	victim = LOGIN_D->find_body(victim_name);
	if (!victim) return notify_fail("��ҪͶ˭��Ʊ��\n");*/
		
    if( !stringp(file = (string)"/cmds/std/vote/"+act_name)
   		|| file_size(file + ".c") <= 0 )
   			return 	notify_fail("��ҪͶƱ��ʲô��\n");
   	me->set("voting",channel);
	
    if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);
	
    if ((int)file_ob->vote(me, victim) <= 0) {
		if ((int)me->query("vote/abuse")> 50) {
			write( HIG "����Ϊ����ͶƱ��ͶƱȨ�������ˣ�\n" NOR);
			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");
		}	
		return 0;
	}
	return 1;
}


int valid_voters(object me)
{
	object *list;
	int d = 0;
	int j;

    list = users();
    j = sizeof(list);
    while( j-- )
	{
		// Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;
		
		d++;
	}
	
	return d;
}


int help(object me)
{
write(@HELP
ָ���ʽ : vote <��/�ر�> <ĳ��> <ĳ������Ƶ��>

������������ͶƱ�����رջ��ĳ�˵�����Ƶ������һ��ʱ����һֱ����ͶƱ
��������Զ�ȡ������ǰ������������鰸��

block: �ر�ĳ�˽�̸Ƶ������ӵ�б��Ȩ�����һ���ϵļ򵥶���ͬ�⡣
unblock: ��ĳ�˽�̸Ƶ����������֮һƱ��ͬ�⡣

HELP
    );
    return 1;
}

/**
future motion (not implemented yet):
eject: ����ĳ�ˣ�����Ʊ���ϵļ򵥶���ͬ�⡣
robot: ����ĳ���ǻ����ˣ���������˸��飬����ϵͳ��ѵ�������ߡ�
jail: ��ĳ���ͽ�����������Ʊ���ϵļ򵥶���ͬ�⡣
**/
