// jia.c

int main(object me, string arg)
{
        object ob;

        if (me->query("marry"))
                return notify_fail("���Ѿ�����ˡ�\n");
        if (me->query_temp("marry"))
                return notify_fail("���Ѿ������ˡ�\n");
       if (me->query("gender")=="����")
                return notify_fail("ֻ��Ů�˲��ܴ�Ӧ���˵���飡\n");
        if (!arg || !(ob = present(arg, environment(me))) || me == ob || !ob->is_character())
                return notify_fail("��Ҫ�޸�˭��\n");
        if (ob->query_temp("pending/marry") != me) {
                message_vision("$N��޸�$n������$n��û����$N��顣\n", me, ob);
                return 1;
        }
        if (me->query("age") < 18) {
                message_vision("$N��޸�$n������$N��С���ٵȼ���ɡ�\n", me, ob);
                return 1;
        }
        message_vision("$N�ߴ��ش�Ӧ�޸�$n��\n", me, ob);
        ob->delete_temp("pending/marry");
        me->set_temp("marry", ob);
        ob->set_temp("marry", me);
        return 1;
}
