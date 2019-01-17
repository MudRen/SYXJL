// dig.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object env, ob;
        int i;
        string oname,sum;
        mapping *item_list = ({
        ([
                "object" : "/u/byt/baowu/obj/bjitui",
                "name": "������",
        ]),
        ([
                "object" : "/u/byt/baowu/obj/bjiudai",
                "name": "ţƤ�ƴ�"
        ]),
        });

        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n");

        if( me->is_fighting() )
                return notify_fail("�㻹��ר����ս�ɣ�\n");

        env = environment(me);
        if (!env->query("outdoors"))
                return notify_fail("��������ѽ��\n");

        if (env->query("no_dig")) {
                if (stringp(env->query("no_dig")))
                        return notify_fail(env->query("no_dig"));
                return notify_fail("���ﲻ׼����ھ�\n");
        }
	oname=env->query_temp("baowu");
        message_vision("$N���ڵ��ϣ�˫�����١�\n", me);
//        me->receive_damage("jing", 5 + random(5));
	if(env->query_temp("baowu")!=0)
	{
                for (i = 0; i < sizeof(item_list); i++) {
                		sum= item_list[i]["name"];
                		if(sum==env->query_temp("baowu"))
                		{
                                	ob = new(item_list[i]["object"]);
                                	message_vision("\n$N�ڵ���һ" + ob->query("unit") + ob->query("name") + "��\n", me);
                                	env->delete_temp("baowu");
                                	ob->move(me);
					return 1;
                                }
                        }
	}
        if (env->query("dig_out"))
                if (env->add("dig_out", 1) > 100)
                        env->delete("dig_out");
        message_vision("$N����һ��ʲôҲû���ҵ���\n", me);
        return 1;
}
        
int help(object me)
{
        write(@HELP
ָ���ʽ : dig
 
���ָ����������ڻ����ھ���棬���ܻ��ڵ�һЩ��Ʒ.
 
HELP
    );
    return 1;
}

