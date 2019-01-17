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
	  || quest["quest_type"] != "扫"
	  || quest["quest"] != short )
		return notify_fail("什么？\n");                           
	if(me->query("qi")<80) return notify_fail("你的身体状况不太适合扫地。\n");
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");
	message_vision("$N从角落里找了一把笤帚，开始打扫这里。\n",me);             
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

	message_vision("$N深吸了一口气，直起身来，终于扫完地了！\n",me);
	me->delete("mpquest");
	me->set_temp("mpquest_finish",1);
	if((int)time() > (int)me->query("task_time"))
		return notify_fail("你没有按时完成任务，不会有奖励了。\n");
        else
        {
        	tell_object(me,HIW "恭喜你！你又完成了一项任务,回去复命吧！\n"NOR);
                score=quest["score"]+random(quest["score"]);
		tell_object(me,"你对"+me->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");
		if(!me->query("score"))
			me->set("score",0);
		me->add("score",score);
		return 1;
	}
	return 1;
}
