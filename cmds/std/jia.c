// jia.c

int main(object me, string arg)
{
        object ob;

        if (me->query("marry"))
                return notify_fail("你已经结婚了。\n");
        if (me->query_temp("marry"))
                return notify_fail("你已经订婚了。\n");
       if (me->query("gender")=="男性")
                return notify_fail("只有女人才能答应别人的求婚！\n");
        if (!arg || !(ob = present(arg, environment(me))) || me == ob || !ob->is_character())
                return notify_fail("你要嫁给谁？\n");
        if (ob->query_temp("pending/marry") != me) {
                message_vision("$N想嫁给$n，不过$n并没有向$N求婚。\n", me, ob);
                return 1;
        }
        if (me->query("age") < 18) {
                message_vision("$N想嫁给$n，不过$N还小，再等几年吧。\n", me, ob);
                return 1;
        }
        message_vision("$N羞答答地答应嫁给$n。\n", me, ob);
        ob->delete_temp("pending/marry");
        me->set_temp("marry", ob);
        ob->set_temp("marry", me);
        return 1;
}
