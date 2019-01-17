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

        if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

        if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
        else return notify_fail("��Ҫ��˭ʲô������\n");

        if(!objectp(who = present(target, environment(me))) || !living(who))
                return notify_fail("����û������ˡ�\n");

	if( me->is_busy() )
		return notify_fail("����æ���أ�û������˼Ҷ�����\n");

        if(sscanf(item, "%d %s", amount, item)==2)
        {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
                if( obj->query("no_drop") )
                        return notify_fail("�����������������ˡ�\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
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
                return notify_fail("������û������������\n");
        return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
        object *inv;

        if( obj->query("no_drop") )
                return notify_fail("�����������������ˡ�\n");

// check for dynamic_quests
	if(obj->query("dynamic_quest"))
	if(TASK_D->quest_reward(me,who,obj)) return 1;

        if( !interactive(who) && !who->accept_object(me, obj) )
                return notify_fail("��ֻ�ܰѶ����͸�������Ҳ��ݵ����\n");
        if( who->query("env/no_accept") )
                return notify_fail("�˼Ҳ�Ҫ��Ķ�����\n");
        if( !userp(who) && obj->value() )
        {
                message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
                destruct(obj);
                return 1;
        }
        else
        {
                // add by hello 1996.12.05
                // �����������ǲ�������̫����
                inv = all_inventory(who);
                if (inv && sizeof(inv)>49 && userp(who))
                {
                        write(who->name()+"���϶���ô�ණ���ˣ��㻹���������\n");
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
                        message("channel:sys", HIR +"��ϵͳ����"+ me->query("name") + "(" + me->query("id") + ")����" + who->query("name") + "(" + who->query("id") + ")һ"+obj->query("unit")+obj->short()+"��\n"NOR, users());
                        }
                        printf("���%sһ%s%s��\n", who->name(), obj->query("unit"), obj->name());
                        message("vision", sprintf("%s����һ%s%s��\n", me->name(),
                                obj->query("unit"), obj->name()), who );
                        message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
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
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>

���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.

HELP
    );
    return 1;
}


