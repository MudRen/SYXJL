// suicide.c

#include <ansi.h>

int main(object me, string arg)
{
        if( me->is_busy() )
                return notify_fail("你上一个动作还没完成。\n");

        if( !arg || arg != "-f") {
                write("请用 suicide -f 确定自杀。\n");
                return 1;
        }

        if (!me->query_temp("link_ob"))
                return notify_fail("你不是正常连线进入的，不能自杀。\n");

        write(
                "江湖虽然险恶，生活毕竟美好，请不要轻言自杀。\n"
                "选择自杀意味着这个人物的资料就永远删除了，请务必考虑清楚，\n"
                "确定的话请输入您的密码：");
        input_to("check_password", 1, me, 1);
        return 1;
}
void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass;

        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("密码错误！\n");
                return;
        }

        if (forever) {
                tell_object( me,
                        HIR "\n你决定要自杀了，真的永别了。\n\n" NOR);
                        message("channel:sys", HIR +"【自杀精灵】"HIW+ me->short(1)+HIR"决定要自杀了。\n"NOR, users());                        
//        CHANNEL_D->do_channel(this_object(),"rumor",me->short(1) + HIM"决定要自杀了。"NOR);
                me->set_temp("suicide_countdown", 15);
                me->start_busy( (: call_other, this_object(), "slow_suicide" :),
                        (: call_other, this_object(), "halt_suicide" :) );
        }
}

int slow_suicide(object me)
{
        object link_ob;
        int stage;

        stage = me->query_temp("suicide_countdown");
        me->add_temp("suicide_countdown", -1);
        if( stage > 1 ) {
                if( stage%5 == 0 )
                        tell_object(me, HIR "你还有" + chinese_number(stage+stage) + "秒的生存时间。\n" NOR);
                return 1;
        }

        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        log_file("static/SUICIDE",
                sprintf("%s suicide on %s\n", geteuid(me), ctime(time())) );

        seteuid(getuid());
        if (me->query("combat_exp") < 20000) {
                rm( link_ob->query_save_file() + SAVE_EXTENSION );
                rm( me->query_save_file() + SAVE_EXTENSION );
        } else {
                link_ob->save();
        if (!environment(me)->query("no_save") && !me->is_ghost())
                        me->set("startroom", base_name(environment(me)));
                me->save();
                rename( link_ob->query_save_file() + SAVE_EXTENSION, link_ob->query_save_file() + ".ooo" );
                rename( me->query_save_file() + SAVE_EXTENSION, me->query_save_file() + ".ooo" );
        }
        write("好吧，永别了:)。\n");
        tell_room(environment(me), me->name() +
                "自杀了，以后你再也看不到这个人了。\n", ({me}));
      CHANNEL_D->do_channel(this_object(),"rumor",me->short(1) + "自杀逃离这个江湖了。");
    destruct(link_ob);
        destruct(me);
        return 0;
}

int halt_suicide(object me)
{
        tell_object(me, "你放弃了自杀的念头。\n");
        CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + HIM"决定继续勇敢地活下去。"NOR);
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀.
自杀分两种:
 
suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份.
 
请慎重选择 :)
HELP
);
        return 1;
}


