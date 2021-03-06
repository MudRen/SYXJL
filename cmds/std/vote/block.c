// vote block
#include <vote.h> 
#include <ansi.h>

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
        int reason; // vote for what?
        int vv; // valid voter numbers
        int vc;         // vote count;
        int df;
        string *juror, my_id, channel, channel_name;

        if ( channel = (string)me->query("voting") ) me->delete("voting");
        else channel = "chat";
        if ( me == victim )
    {
                if (random(2)) me->add("vote/abuse", 10);
                return notify_fail("不想聊天就关闭自己的聊天频道嘛，不要拿民主开玩笑。\n");
        }

        if ( ( reason = (int)victim->query("vote/reason") ) > 0 
                && ( reason != V_CHBLK ) )
    {
                return notify_fail("等当前的投票完成后，再进行另一项表决。。\n");
        }

        if ( channel == "chat" ) channel_name="闲聊";
        if ( channel == "rumor" ) channel_name="谣言";
        if ( channel == "es" ) channel_name="网际闲聊";
        if ( channel == "shout" ) channel_name="门派";  
        if ( channel == "ldj" ) channel_name="鹿鼎记";  

        if ( victim->query("chblk_channel/"+channel) ) 
                return notify_fail(victim->name()+"的"+channel_name+"频道已经是关闭的了。\n");

        if ( reason <= 0 ) {
                victim->set( "vote/reason", (int)V_CHBLK ); 
        }
  
        my_id = me->query("id");

// dont allow me to vote twice for the same issue
        juror = victim->query("vote/juror");
  
        if( !pointerp(juror) ) {
                victim->set("vote/juror", ({ my_id }) );
        } 
        else if( member_array(my_id, juror) == -1 ) {
                victim->set("vote/juror", juror+({ my_id }) );
        } 
        else return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");

        vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  
        vc = victim->add("vote/count", 1);

        df = vv-vc;
        if ( vv < 4 ) df = 4 - vc;

        if ( df>=1 ) {
                shout( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
                        +"的"+channel_name+"频道，还差"+chinese_number(df)+"票。\n" NOR);
                write( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
                        +"的"+channel_name+"频道，还差"+chinese_number(df)+"票。\n" NOR);
                victim->apply_condition("vote_clear", 10);
        }
        else {
                shout( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
                        +"的"+channel_name+"频道。"+victim->name()+"的"+channel_name+"频道被关闭了！\n" NOR);
                write( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
                        +"的"+channel_name+"频道。"+victim->name()+"的"+channel_name+"频道被关闭了！\n" NOR);
                victim->apply_condition("vote_clear", -10);
                victim->set("chblk_channel/"+channel, time());
        victim->save();
        } 
  
        return 1;
}


