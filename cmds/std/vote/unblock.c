// vote unblock
#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
        int reason; // vote for what?
        int vv; // valid voter numbers
        int vc;         // vote count;
        int df;
        string *juror, my_id;
        string my_name, v_name, channel, channel_name;

        channel = me->query("voting");

        if ( channel == "chat" ) channel_name="闲聊";
        if ( channel == "rumor" ) channel_name="谣言";
        if ( channel == "es" ) channel_name="网际闲聊";
        if ( channel == "shout" ) channel_name="门派";  
        if ( channel == "ldj" ) channel_name="鹿鼎记";  

        if ( ( reason = (int)victim->query( "vote/reason" ) ) > 0 
                && ( reason != V_UNCHBLK ) )
    {
                return notify_fail("等当前的投票完成后，再进行另一项表决。。\n");
        }

        if( !victim->query( "chblk_channel/" + channel ) )
                return notify_fail( victim->name() + "的" + channel_name + "频道已经是打开的了。\n" );
  

        if ( reason <= 0 )
    {
                victim->set("vote/reason", (int)V_UNCHBLK); 
        }
  
        my_id = me->query("id");

// dont allow me to vote twice for the same issue
        juror = victim->query("vote/juror");
  
        if( !pointerp(juror) ) victim->set("vote/juror", ({ my_id }) );
        else if( member_array(my_id, juror) == -1 ) 
                victim->set("vote/juror", juror+({ my_id }) );
        else return notify_fail("每人只能投一票！\n");
        

        vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;  
        vc = victim->add("vote/count", 1);

        df = vv - vc;
        if (vv < 4) df = 4 - vc;
  
        my_name = me->name();
        if (me == victim) v_name = "自己";
        else  v_name = victim->name();

        if (df>=1) {
                shout( HIG "【表决】"+my_name+"投票打开" +v_name +"的"+channel_name+"频道，还差"
                        +chinese_number(df)+"票。\n" NOR);
                write( HIG "【表决】"+my_name+"投票打开" +v_name +"的"+channel_name+"频道，还差"
                        +chinese_number(df)+"票。\n" NOR);
                victim->apply_condition("vote_clear", 10);
        } 
        else 
    {
                shout( HIG "【表决】"+my_name+"投票打开" +v_name+"的"+channel_name+"频道。"
                        +v_name+"的"+channel+"频道被打开了！\n" NOR);
                write( HIG "【表决】"+my_name+"投票打开" +v_name+"的"+channel_name+"频道。"
                        +v_name+"的"+channel+"频道被打开了！\n" NOR);
                victim->apply_condition("vote_clear", -10);
                if (victim->query("chblk_channel/"+channel)) victim->delete("chblk_channel/" + channel, time());
        } 
        return 1;
}


