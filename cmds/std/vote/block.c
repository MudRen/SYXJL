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
                return notify_fail("��������͹ر��Լ�������Ƶ�����Ҫ����������Ц��\n");
        }

        if ( ( reason = (int)victim->query("vote/reason") ) > 0 
                && ( reason != V_CHBLK ) )
    {
                return notify_fail("�ȵ�ǰ��ͶƱ��ɺ��ٽ�����һ��������\n");
        }

        if ( channel == "chat" ) channel_name="����";
        if ( channel == "rumor" ) channel_name="ҥ��";
        if ( channel == "es" ) channel_name="��������";
        if ( channel == "shout" ) channel_name="����";  
        if ( channel == "ldj" ) channel_name="¹����";  

        if ( victim->query("chblk_channel/"+channel) ) 
                return notify_fail(victim->name()+"��"+channel_name+"Ƶ���Ѿ��ǹرյ��ˡ�\n");

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
        else return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");

        vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  
        vc = victim->add("vote/count", 1);

        df = vv-vc;
        if ( vv < 4 ) df = 4 - vc;

        if ( df>=1 ) {
                shout( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
                        +"��"+channel_name+"Ƶ��������"+chinese_number(df)+"Ʊ��\n" NOR);
                write( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
                        +"��"+channel_name+"Ƶ��������"+chinese_number(df)+"Ʊ��\n" NOR);
                victim->apply_condition("vote_clear", 10);
        }
        else {
                shout( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
                        +"��"+channel_name+"Ƶ����"+victim->name()+"��"+channel_name+"Ƶ�����ر��ˣ�\n" NOR);
                write( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
                        +"��"+channel_name+"Ƶ����"+victim->name()+"��"+channel_name+"Ƶ�����ر��ˣ�\n" NOR);
                victim->apply_condition("vote_clear", -10);
                victim->set("chblk_channel/"+channel, time());
        victim->save();
        } 
  
        return 1;
}


