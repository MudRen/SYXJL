// baohu.c by ljty at May, 3 1998



#include <ansi.h>



inherit F_CLEAN_UP;





int main(object me, string arg)

{

    object ob;



    if (me->is_busy())

        return notify_fail("��������æ���ء�\n");



    if( !arg )

        return notify_fail("ָ���ʽ��baohu [none]|<����>|[cancel]\n");



    if( arg=="none" ) 

      {

        if(!me->query_temp("baohuman"))

          return notify_fail("�����ڲ�û�б���˭��\n");

        message_vision("$N���ڲ��뱣��$n��\n",me,me->query_temp("baohuman"));

        me->query_temp("baohuman")->set_temp("baohu",0);

        me->set_leader(0);

        return 1;

      }

    

    if( arg=="cancel" )

      {

        if(!me->query_temp("baohu"))

          return notify_fail("���ڲ�û���˱����㡣\n");

        me->query_temp("baohu")->set_temp("baohuman",0);

        me->query_temp("baohu")->set_leader(0);

        message_vision("$N���ڲ���Ҫ$n�����ˡ�\n",me,me->query_temp("baohu"));

         me->set_temp("baohu",0);

       me->set_temp("baohuman",0);
        return 1;

      }

    if( !objectp(ob = present(arg, environment(me)))

       ||        !ob->is_character() )

      return notify_fail("���뱣��˭��\n");



    ob = present(arg, environment(me));



    if(ob == me)

      return notify_fail("�Լ������Լ������Ǹ������⣮����\n");

    

    if(ob == me->query_temp("baohu"))

      return notify_fail("�����ڱ�����" + me->query_leader()->name() +"��\n");



    if(ob->query_temp("baohu"))

      return notify_fail("�Ѿ����˽��б����ˣ���Ͳ��÷����ˡ�\n");



    

    message_vision("$N������ʼ����$n�ˡ�\n", me, ob);

    me->set_leader(ob);

    me->set_temp("baohuman",ob->query("id"));
    ob->set_temp("baohu",me);

    return 1;

}



int help(object me)

{

        write(@HELP

ָ���ʽ��baohu <����>|[none]|[cancel]



���ָ��ʹ�㿪ʼ����һ���ˣ����������ɱ����

�㽫����ְ��нӹ�����������м����˶���ɱ

�����㽫����Ϊ����



HELP

    );

    return 1;

}

