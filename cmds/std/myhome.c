inherit F_CLEAN_UP;
int main(object me, string arg)
{
        me=this_player();
        if (me->query("id")=="winnie")
        me->move("/u/brave/workroom");
}
