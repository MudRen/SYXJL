// sleep.c
// littlefish
// last updated 3/16/96

void wakeup(object,object);
void del_sleeped(object);

int main(object me, string arg)
{
        int rnd;
	mapping fam;
	object where = environment(me);
	

        seteuid(getuid());

	if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("���ﲻ������˯�ĵط���\n");
   
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в���˯����\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("��С���������$N���: �����ﵱ��������! �ȵ�һ¥��Ǯ������˯!\n",me);
		return 1;
	}
 
//	if (me->query_temp("sleeped"))
//		return notify_fail("�������������˯��һ��, ��˯�������к�����! \n");

	if (where->query("sleep_room"))
	{
		write("��������һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
            rnd = random((60 - me->query_con()) / 3);
	}
	else { 
		write("�������½���һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N�����½�������һ�ɣ���һ�����������������������\n",me);
            rnd = 10 + random((100 - me->query_con()) / 3);
	}

	where->set("no_fight", 1);
	where->add_temp("sleeping_person", 1);

	me->set("no_get", 1);	
	me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");

	me->disable_player("<˯����>");

        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
	return 1;
	
}

void wakeup(object me,object where)
{
	me->set("qi",    me->query("eff_qi"));
	me->set("jing",  me->query("eff_jing"));
//          me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
          me->add("jingli", me->query("max_jingli")/2 - me->query("jingli")/2 );
	me->enable_player();
  
    call_out("del_sleeped", 0, me);

	message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
	me->set_temp("block_msg/all", 0);
	write("��һ��������ֻ���������档�ûһ���ˡ�\n");

	if (!where->query("sleep_room") && !where->query("hotel"))
		where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	me->delete("no_get");	
	me->delete("no_get_from");	
 
}

void del_sleeped(object me)
{
	if (objectp(me) &&  me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
