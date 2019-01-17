inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)

{

	int line;
	string party_name;

	mapping family;



	line = 1;

	family = me->query("family");



	while( party_name = read_file("/log/founded_party", line, 1) )

	{

	  if( party_name == arg + "\n" )

	    return notify_fail("�Բ����������Ѿ������ˣ��㲻�������齨��\n");

	  line = line + 1;

	}

	 if((int)me->query("combat_exp")<100000)

        {

          message_vision("��Ľ��������������������齨���ɣ�\n",me);

	return 1;

         }



//      if( stringp(me->query("banghui_leader")) )

//        return notify_fail("�Բ������Ѿ�������"+me->query("banghui_leader")+"�İ�ᡣ\n");



        if( !arg ) return notify_fail("��Ҫ�齨ʲô��᣿\n");



        tell_object(me,"������齨" + arg + "��\n");



        me->set("banghui", arg);

        me->set("banghui_leader", me->query("id"));

	if( me->query("family/family_name"))

	  me->set("title", HIG"��" + arg + "��"NOR + sprintf("%s��%s������", family["family_name"],

			chinese_number(family["generation"])));

	else

	  me->set("title", "��" + arg + "��" + "��ͨ����");



        log_file("founded_party", arg + "\n");



	return 1;

}
