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

        if ( channel == "chat" ) channel_name="����";
        if ( channel == "rumor" ) channel_name="ҥ��";
        if ( channel == "es" ) channel_name="��������";
        if ( channel == "shout" ) channel_name="����";  
        if ( channel == "ldj" ) channel_name="¹����";  

        if ( ( reason = (int)victim->query( "vote/reason" ) ) > 0 
                && ( reason != V_UNCHBLK ) )
    {
                return notify_fail("�ȵ�ǰ��ͶƱ��ɺ��ٽ�����һ��������\n");
        }

        if( !victim->query( "chblk_channel/" + channel ) )
                return notify_fail( victim->name() + "��" + channel_name + "Ƶ���Ѿ��Ǵ򿪵��ˡ�\n" );
  

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
        else return notify_fail("ÿ��ֻ��ͶһƱ��\n");
        

        vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;  
        vc = victim->add("vote/count", 1);

        df = vv - vc;
        if (vv < 4) df = 4 - vc;
  
        my_name = me->name();
        if (me == victim) v_name = "�Լ�";
        else  v_name = victim->name();

        if (df>=1) {
                shout( HIG "�������"+my_name+"ͶƱ��" +v_name +"��"+channel_name+"Ƶ��������"
                        +chinese_number(df)+"Ʊ��\n" NOR);
                write( HIG "�������"+my_name+"ͶƱ��" +v_name +"��"+channel_name+"Ƶ��������"
                        +chinese_number(df)+"Ʊ��\n" NOR);
                victim->apply_condition("vote_clear", 10);
        } 
        else 
    {
                shout( HIG "�������"+my_name+"ͶƱ��" +v_name+"��"+channel_name+"Ƶ����"
                        +v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
                write( HIG "�������"+my_name+"ͶƱ��" +v_name+"��"+channel_name+"Ƶ����"
                        +v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
                victim->apply_condition("vote_clear", -10);
                if (victim->query("chblk_channel/"+channel)) victim->delete("chblk_channel/" + channel, time());
        } 
        return 1;
}


