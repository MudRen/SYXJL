// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
	if (me->is_fighting()) {
//added by ronger
		if (wizardp(me)) {
			me->remove_all_killer();
			message_vision("$N����ʦ��������ֹ���ⳡ�򶷡�\n", me); 
			me->set_temp("halted");

			return 1;

		}
//
		else
		me->remove_all_enemy();
		message_vision("$N�������һԾ������սȦ�����ˡ�\n", me); 
		me->set_temp("halted");

		return 1;

	}
	else if (!me->is_busy()) 
		return notify_fail("�����ڲ�æ��\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
		message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate") != 0){
		message_vision("$N��������̨�����е�����֮�������³�������վ��������\n", me);
		me->interrupt_me();
	}
	me->interrupt_me();

	return 1;
}
	
