// qiu.c

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
        object ob;

        if (me->query("marry"))
                return notify_fail("���Ѿ�����ˡ�\n");
        if (me->query_temp("marry"))
                return notify_fail("���Ѿ������ˡ�\n");
        if (me->query("gender") == "Ů��")
                return notify_fail("���ֻ�����з�����\n");
        if (me->query("class") == "bonze" || me->query("class") == "taoist")
                return notify_fail("���Ȼ�����˵�ɡ�\n");
        if (!arg || !(ob = present(arg, environment(me))) || me == ob)
                return notify_fail("��Ҫ��˭��飿\n");
        if (!userp(ob))
                return notify_fail("��ֻ���������顣\n");
        if (ob->query("gender") != "Ů��") {
                message_vision("$N��������ض���$n˵��С�๫���ǲ��Ǻܼ�į����\n", me, ob);
                return 1;
        }
        if (me->query("age") < 18) {
                message_vision("$N����$n��飬����$N��û�г��ꡣ\n", me, ob);
                return 1;
        }
        message_vision("$N��$n��顣\n", me, ob);
        tell_object(ob, YEL "�����Ը���"+me->name()+"��Ϊ�������� marry ָ�\n" NOR);
        me->set_temp("pending/marry", ob);
        return 1;
}
