inherit F_CLEAN_UP;
#include <ansi.h>
int sao(object me);

int main(object me)
{
//        int score;
	string short; 
	mapping quest;   
	short = environment(me)->query("short");
	if(!(quest=me->query("mpquest")) 
	  || quest["quest_type"] != "ɨ"
	  || quest["quest"] != short )
		return notify_fail("ʲô��\n");                           
	if(me->query("qi")<80) return notify_fail("�������״����̫�ʺ�ɨ�ء�\n");
	if(me->is_busy()) return notify_fail("����æ���أ�\n");
	message_vision("$N�ӽ���������һ�����㣬��ʼ��ɨ���\n",me);             
	me->add("qi",-50);      
	me->start_busy(15);
	call_out("sao",20,me);
	return 1;
}                 

int sao(object me)
{
	int score;
	mapping quest;

	quest = me->query("mpquest");

	message_vision("$N������һ������ֱ������������ɨ����ˣ�\n",me);
	me->delete("mpquest");
	me->set_temp("mpquest_finish",1);
	if((int)time() > (int)me->query("task_time"))
		return notify_fail("��û�а�ʱ������񣬲����н����ˡ�\n");
        else
        {
        	tell_object(me,HIW "��ϲ�㣡���������һ������,��ȥ�����ɣ�\n"NOR);
                score=quest["score"]+random(quest["score"]);
		tell_object(me,"���"+me->query("family/family_name")+"���ҳ϶������"+chinese_number(score)+"�㡣\n");
		if(!me->query("score"))
			me->set("score",0);
		me->add("score",score);
		return 1;
	}
	return 1;
}
