/* channel block command..
 * author: ken@chinesemud.net
 * create time: 99-4-16
 */
 
#include <ansi.h>
#define valid_channels ({ "es", "rumor", "chat", "ldj", "shout","bidd","music" })

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;
	string who, channel;
	string *channels,*args;
	int i, flag;

	if( !arg ) {
		help(me);
		return 1;	
	}

        args = explode(arg," ");

	if( sizeof(args) < 1 ) {
		help(me);
		return 1;
	}
	if( sizeof(args) == 2 ) {
		who = args[0];
		channel = args[1];
		flag = 2;
	} else who = arg;
	
	ob = LOGIN_D->find_body(who);

	if (!ob) return notify_fail("这个人不在！\n");

	if( !flag ) {
		channels = ob->query("channels");
		printf("%s(%s)当前收听的频道有：\n",ob->query("name"),ob->query("id"));
		for( i=0;i<sizeof(channels);i++)
			printf("        %10s : %s\n",channels[i],
				(time() - ob->query("chblk_channel/" + channels[i]) <3600 ) ?
    HIR"关闭"NOR : BOLD"正常"NOR
				);
		printf("收听的频道共有 %d 个。\n", sizeof(channels) );
		return 1;
	}

	flag = 0;

//	if (wizardp(ob)) return notify_fail("你不能关闭巫师的频道。\n");
        

        for( i=0;i<sizeof(valid_channels);i++ ) {
		if( channel == valid_channels[i] ) {
			flag = 1;
			break;
		}
	}
	if( channel == "all" )
		flag = 1;
	
	if( !flag ) {
		write("当前没有 " + channel + "这个频道。\n");
		return 1;
	}
/*
	if( time() - (int)ob->query("chblk_channel/" + channel) < 3600 )
		return notify_fail( ob->query("name")+"的这个频道已经是关闭的。\n");
*/
	if( channel == "all" ) {
                        for( i=0;i<sizeof(valid_channels);i++ ) {
				ob->delete("chblk_channel/" + valid_channels[i], time() );
				printf("%s(%s)的 %s 频道已经被打开。\n",ob->query("name"),ob->query("id"),valid_channels[i]);
			}
	}
	else {
		ob->delete("chblk_channel/" + channel, time() );
		printf("%s(%s)的 %s 频道已经被打开。\n",ob->query("name"),ob->query("id"),channel);
	}
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : unchblk <某人> [<频道名>|all]

此命令将打开某人的频道。如果没有频道名就打开所有合法频道。
<某人>　也可以是频道名。
<频道名> 可以是rumor 或 chat 

HELP
    );
    return 1;

}

