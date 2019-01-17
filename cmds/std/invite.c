// invite.c zyx



#include <ansi.h>



inherit F_CLEAN_UP;



int main(object me, string arg)

{



   if( !arg )

        {

        if(this_player()->query_temp("invited"))

        return notify_fail(CYN+this_player()->query_temp("invited_name")+"("+this_player()->query_temp("invited")+")邀请你去他家玩呢。\n"NOR);

        return notify_fail(HIR"现在没有人邀请你！\n"NOR);

        }



        if(file_size("/data/playerhome/h_"+me->query("id")+".o") == -1 && 

           file_size("/data/playerhome/h_"+me->query("couple/couple_id")+".o") == -1 )

        return notify_fail(HIR"现在还没有属于你的房屋!你邀请别人干什么？\n"NOR);



    if (!find_player(arg))

     return notify_fail(HIR"有这个人在线上嘛?\n"NOR);



   if(find_player(arg)==me)

    return notify_fail(HIB"没事闲的邀请自己玩？比我还幽默，你真行！\n"NOR);



        if(find_player(arg)->query_temp("invited")==this_player()->query("id"))

        {

    find_player(arg)->delete_temp("invited");

    find_player(arg)->delete_temp("invited_name");

    tell_object(find_player(arg),CYN+this_player()->query("name")+"说他现在没有空，叫你改天在到他(她)家里去。\n"NOR);

    write(HIR"已经帮你取消邀请了。\n"NOR);      

        return 1;

        }

    find_player(arg)->set_temp("invited",this_player()->query("id"));

    find_player(arg)->set_temp("invited_name",this_player()->query("name"));



    tell_object(find_player(arg),HIR+this_player()->query("name")+"("+this_player()->query("id")+")邀请你去他(她)的房间呢！\n"NOR);

    write(YEL"已经帮你邀请了！\n"NOR);

    return 1;



}

int help(object me)

{

  write(@HELP

指令格式 : invite(   ||<人物>)



 

该命令可以邀请别人到你家里作客。

不加任何信息，就看当前有谁邀请你。

要取消邀请一个人，请再次邀请他(她)。



 

HELP

    );

    return 1;

}

 



