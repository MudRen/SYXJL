#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_quit(object me);
void create() 
{
        seteuid(getuid());
        set("channel_id", "离线指令(quit)");
        set("id", "quit");
}

int main(object me, string arg)
{
        object link_ob;

        if( LOGIN_D->get_madlock()) 
                return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");

        if( (me->is_busy()) && (!me->query_temp("suicide_countdown")))
                return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");

        link_ob = me->query_temp("link_ob");

        // We might be called on a link_dead player, so check this.
        if( link_ob ) {

                // Are we possessing in others body ?
                if( link_ob->is_character() ) {
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }
                

                link_ob->set("last_on", time());
                if( !wizardp(me) ) {
                me->set("quit_time",time());            
                 }
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
        if( environment(me)->query("valid_startroom") )
                {
                        me->set("startroom", base_name(environment(me)));
                        write("当你下次连线进来时，会从这里开始。\n");
                }

                destruct(link_ob);
        }
        if( (environment(me)->query("no_fight") && environment(me)->query("no_sleep_room")) ||
        wizardp(me) )
                do_quit(me);
        else
        {
                write("档案保存中，请稍候... ...\n");
                call_out("do_quit",5,me);
        }

        return 1;
}

int do_quit(object me)
{
        int i;
        object *inv;
        if( !me ) return 1;
        if( !wizardp(me) ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload() )
                                DROP_CMD->do_drop(me, inv[i]);
        }

        write("欢迎下次再来！\n");
        message("system", me->name() + "离开游戏。\n", environment(me), me);

         i=me->query("combat_exp")-me->query_temp("temp_exp");
        if (i < 0 ) i=0;
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name() + "(" + me->query("id") + ")离开游戏了。\n\t本次连线经验增长"+i+
                        "。\n\t连线时间"+
                        CHINESE_D->chinese_period(FINGER_D->online_time(me))+
                        "。\n");
        if( userp(me) ) log_file("EXP_LOG",
                          sprintf("%s(%s)本次连线exp增长 %d 连线时间 %s   %s 记录.\n", me->name(1), geteuid(me),i,
                                    CHINESE_D->chinese_period(FINGER_D->online_time(me)),ctime(time())) );
        if( !wizardp(me) && userp(me) && i>=100000 ) log_file("static/check_exp",
                          sprintf("%s(%s)本次连线exp增长 %d 连线时间 %s   %s 记录.\n", me->name(1), geteuid(me),i,
                                    CHINESE_D->chinese_period(FINGER_D->online_time(me)),ctime(time())) );

        me->set("time_aged",me->query("time_aged")+time()-me->query_temp("temp_time")); 
        if(wizardp(me))
                CHANNEL_D->do_channel(this_object(),"wiz",me->name(1)+
                        "离开了"+MUD_NAME+"。\n");
        me->save();
        destruct(me);
        return 1;
}
       
int help(object me)
{
        write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}



