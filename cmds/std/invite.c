// invite.c zyx



#include <ansi.h>



inherit F_CLEAN_UP;



int main(object me, string arg)

{



   if( !arg )

        {

        if(this_player()->query_temp("invited"))

        return notify_fail(CYN+this_player()->query_temp("invited_name")+"("+this_player()->query_temp("invited")+")������ȥ�������ء�\n"NOR);

        return notify_fail(HIR"����û���������㣡\n"NOR);

        }



        if(file_size("/data/playerhome/h_"+me->query("id")+".o") == -1 && 

           file_size("/data/playerhome/h_"+me->query("couple/couple_id")+".o") == -1 )

        return notify_fail(HIR"���ڻ�û��������ķ���!��������˸�ʲô��\n"NOR);



    if (!find_player(arg))

     return notify_fail(HIR"���������������?\n"NOR);



   if(find_player(arg)==me)

    return notify_fail(HIB"û���е������Լ��棿���һ���Ĭ�������У�\n"NOR);



        if(find_player(arg)->query_temp("invited")==this_player()->query("id"))

        {

    find_player(arg)->delete_temp("invited");

    find_player(arg)->delete_temp("invited_name");

    tell_object(find_player(arg),CYN+this_player()->query("name")+"˵������û�пգ���������ڵ���(��)����ȥ��\n"NOR);

    write(HIR"�Ѿ�����ȡ�������ˡ�\n"NOR);      

        return 1;

        }

    find_player(arg)->set_temp("invited",this_player()->query("id"));

    find_player(arg)->set_temp("invited_name",this_player()->query("name"));



    tell_object(find_player(arg),HIR+this_player()->query("name")+"("+this_player()->query("id")+")������ȥ��(��)�ķ����أ�\n"NOR);

    write(YEL"�Ѿ����������ˣ�\n"NOR);

    return 1;



}

int help(object me)

{

  write(@HELP

ָ���ʽ : invite(   ||<����>)



 

���������������˵���������͡�

�����κ���Ϣ���Ϳ���ǰ��˭�����㡣

Ҫȡ������һ���ˣ����ٴ�������(��)��



 

HELP

    );

    return 1;

}

 



