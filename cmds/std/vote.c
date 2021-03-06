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
 		return notify_fail("你是未成年人，还没有政治权利。\n");
	}
    if ( !userp( me ) ) return 0;
	if ((int)me->query("vote/deprived")) {
 		return notify_fail("由于你滥用投票权，你政治权利暂时被剥夺了。\n");
	}

    if (!arg || sscanf(arg, "%s %s %s", act_name, victim_name, channel) != 3) {
		return notify_fail("休要玩弄民主，如果你不知道如何投票，可以help vote。\n");
    }
    
         if (channel == "rumor" || channel == "chat" || channel == "ldj" )  {
		victim = LOGIN_D->find_body(victim_name);
        if (!objectp(victim))  return notify_fail("真可惜，这个人不在线上。\n");       
   		if ( wizardp(victim) ) return notify_fail("唉，神仙拥有特权，你奈何他不得，还是先试着把他打下凡间再说吧。\n");
	}
 	else return notify_fail("你现在只能投票关闭或打开某人的聊天频道。\n");

/*	victim = LOGIN_D->find_body(victim_name);
	if (!victim) return notify_fail("你要投谁的票？\n");*/
		
    if( !stringp(file = (string)"/cmds/std/vote/"+act_name)
   		|| file_size(file + ".c") <= 0 )
   			return 	notify_fail("你要投票干什么？\n");
   	me->set("voting",channel);
	
    if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);
	
    if ((int)file_ob->vote(me, victim) <= 0) {
		if ((int)me->query("vote/abuse")> 50) {
			write( HIG "你因为胡乱投票，投票权被剥夺了！\n" NOR);
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
指令格式 : vote <打开/关闭> <某人> <某个聊天频道>

此命令提议大家投票决定关闭或打开某人的聊天频道。若一段时间内一直无人投票
该提议会自动取消。当前可以提出如下议案：

block: 关闭某人交谈频道，需拥有表决权的玩家一半上的简单多数同意。
unblock: 打开某人交谈频道，需三分之一票数同意。

HELP
    );
    return 1;
}

/**
future motion (not implemented yet):
eject: 驱逐某人，需三票以上的简单多数同意。
robot: 怀疑某人是机器人，如果有五人附议，则由系统审训被怀疑者。
jail: 将某人送进监狱，需三票以上的简单多数同意。
**/
