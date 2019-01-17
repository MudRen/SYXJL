// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, *ob;
	string callname;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	if( me->query_temp("baohuman")==obj->query("id"))
		return notify_fail(HIR "����ɱ��Ҫ�������ˣ�\n" NOR);

	if( !obj->query_temp("begging") )
	{
		if((int)obj->query("age") <= 15 && userp(obj))
			return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
	}

	if(!undefinedp(me->query("friends/"+obj->query("id"))))
	{
		write(HIG"��������ô��ô����Ҫɱ��ĺ���ҲҪ�Ȱ���(��)�Ӻ����г�ȥ��\n"NOR);
		return 1;
	}

	callname = RANK_D->query_rude(obj);

	message_vision("\n$N����$n�ȵ�����"
		+ callname + "�����ղ������������һ��\n\n", me, obj);

	me->kill_ob(obj);
	// Add by jungu
	if ( userp(obj))
	write_file("/log/static/ATTEMP_KILL",sprintf("%s   ��ͼɱ��   %s on %s\n",
	me->name(1),obj->name(1), ctime(time()) ));
	// Look for PKS
	if( !userp(obj) )
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name()
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}

	if ( (string)obj->query("family/family_name") != (string)me->query("family/family_name") ) {
		ob = all_inventory(environment(me));
		for(int i=0; i<sizeof(ob); i++) {
			if( !living(ob[i]) || ob[i]==me || ob[i]==obj || !ob[i]->query("family") ) continue;
			if( (string)ob[i]->query("family/family_name")==(string)obj->query("family/family_name") && !userp(ob[i]) ) {
				message_vision(ob[i]->name() + "ŭ��һ������" + me->name() + "����"
					 + RANK_D->query_rude(me) + "��������ͬ�ţ���\n", me);
				ob[i]->fight_ob(me);
				me->fight_ob(ob[i]);
			}
		}
	}

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>

���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: hit, fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
