// give.c
// writed by shadow
#include <ansi.h>
inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target, item;
        object obj, who, *inv, obj2;
        int i, amount;

        if(!arg) return notify_fail("你要给谁什么东西？\n");

        if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
        else return notify_fail("你要给谁什么东西？\n");

        if(!objectp(who = present(target, environment(me))) || !living(who))
                return notify_fail("这里没有这个人。\n");

	if( me->is_busy() )
		return notify_fail("你正忙着呢，没功夫给人家东西。\n");

        if(sscanf(item, "%d %s", amount, item)==2)
        {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("你身上没有这样东西。\n");
                if( obj->query("no_drop") )
                        return notify_fail("这样东西不能随便给人。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开给人。\n");
                if( amount < 1 )
                        return notify_fail("东西的数量至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你没有那么多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_give(me, obj, who);
                else
                {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if (do_give(me, obj2, who))
                                return 1;
                        else
                        {
                                obj->set_amount((int)obj->query_amount() + amount);
                                return 0;
                        }
                }
        }

        if(arg=="all")
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        do_give(me, inv[i], who);
                }
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("你身上没有这样东西。\n");
        return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
        object *inv;

        if( obj->query("no_drop") )
                return notify_fail("这样东西不能随便给人。\n");

// check for dynamic_quests
	if(obj->query("dynamic_quest"))
	if(TASK_D->quest_reward(me,who,obj)) return 1;

        if( !interactive(who) && !who->accept_object(me, obj) )
                return notify_fail("你只能把东西送给其他玩家操纵的人物。\n");
        if( who->query("env/no_accept") )
                return notify_fail("人家不要你的东西。\n");
        if( !userp(who) && obj->value() )
        {
                message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
                destruct(obj);
                return 1;
        }
        else
        {
                // add by hello 1996.12.05
                // 检查玩家身上是不是已有太东西
                inv = all_inventory(who);
                if (inv && sizeof(inv)>49 && userp(who))
                {
                        write(who->name()+"身上都那么多东西了，你还想给他啊！\n");
                        return 1;
                }
                if( obj->move(who) )
                {
                        if ( ( wizardp(me) || wizhood(me) == "(immortal)" ) &&
                        !wizardp(who) && wizhood(who) != "(immortal)" )
                        {
                                log_file("static/wizgive", sprintf("%s%s give %s%s %d %s %s (%s)\n",
                                        me->query("name"),
                                        "(" + me->query("id") + ")" ,
                                        who->query("name"),
                                        "(" + who->query("id") + ")" ,
                                        !obj->query_amount()?1:(int)obj->query_amount(),
                                        obj->query("unit"),
                                        base_name(obj) + ".c",
                                        ctime(time())
                                        ) );
                        message("channel:sys", HIR +"【系统】："+ me->query("name") + "(" + me->query("id") + ")给了" + who->query("name") + "(" + who->query("id") + ")一"+obj->query("unit")+obj->short()+"。\n"NOR, users());
                        }
                        printf("你给%s一%s%s。\n", who->name(), obj->query("unit"), obj->name());
                        message("vision", sprintf("%s给你一%s%s。\n", me->name(),
                                obj->query("unit"), obj->name()), who );
                        message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
                                obj->query("unit"), obj->name()), environment(me), ({me, who}) );
                        me->save();
                        who->save();
                        return 1;
                }
                else return 0;
        }
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>

这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.

HELP
    );
    return 1;
}


