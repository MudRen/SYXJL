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

	    return notify_fail("对不起，这个帮会已经存在了，你不能重新组建。\n");

	  line = line + 1;

	}

	 if((int)me->query("combat_exp")<100000)

        {

          message_vision("你的江湖阅历不够，还不能组建帮派！\n",me);

	return 1;

         }



//      if( stringp(me->query("banghui_leader")) )

//        return notify_fail("对不起，你已经加入了"+me->query("banghui_leader")+"的帮会。\n");



        if( !arg ) return notify_fail("你要组建什么帮会？\n");



        tell_object(me,"你决定组建" + arg + "。\n");



        me->set("banghui", arg);

        me->set("banghui_leader", me->query("id"));

	if( me->query("family/family_name"))

	  me->set("title", HIG"【" + arg + "】"NOR + sprintf("%s第%s代弟子", family["family_name"],

			chinese_number(family["generation"])));

	else

	  me->set("title", "【" + arg + "】" + "普通百姓");



        log_file("founded_party", arg + "\n");



	return 1;

}
