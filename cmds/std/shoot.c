// shoot.c

#include <ansi.h>

inherit F_CLEAN_UP;
int shot_random(object me,object who);

void create() { seteuid(getuid()); }

int main(object me,string arg)
{
        object *all_inv,bow,arrow,arrow1,neighbour,here,who;
        int i,have_bow=0,have_arrow=0,have_dir=0,arrow_out;
        string dir,id,*dire;
        mapping direction;

        here=environment(me);
        all_inv=all_inventory(me);
        for(i=0;i<sizeof(all_inv);i++)
        {
        if(all_inv[i]->query("skill_type")=="bow" && all_inv[i]->query("equipped"))
                {
                bow=all_inv[i];
                have_bow=1;
                }
        if(!have_arrow && all_inv[i]->query("skill_type")=="arrow" && !all_inv[i]->query_temp("prick"))
                {
                arrow=all_inv[i];
                have_arrow=1;
                }
        }

        if(me->is_busy())
                return notify_fail("����æ����!\n");
        if(!have_bow)
                return notify_fail("�������һ�Ź�,�ſ������!\n");
        if(!have_arrow)
                return notify_fail("��ļ��Ѿ�������!\n");
        if(!arg)
                return notify_fail("�����ʽ:shoot <����> <����>\n");
        if(sscanf(arg,"%s %s",dir,id)!=2)
                return notify_fail("�����ʽ:shoot <����> <����>\n");

        direction=here->query("exits");
        dire=keys(direction);
        for(i=0;i<sizeof(dire);i++)
        {
        if(dire[i]==dir)
                have_dir=1;
        }

        if(!have_dir)
                return notify_fail("û���������!\n");
        
        neighbour=ROOM_D->get_neighbour(here,dir);

        if(!who=present(id,neighbour))
                return notify_fail("û�������!\n");
        if(!who->is_character())
                return notify_fail("�ⲻ�Ǹ���!\n");
        if(environment(who)!=neighbour)
                return notify_fail("���˲�������!\n");
        if(environment(me)==environment(who))
                return notify_fail("̫����,����û�а취�䵽����.\n");

        if(environment(who)->query("no_fight")==1)
                return notify_fail("��û�а취�䵽�������,����������ܱ�����.\n");
        if(environment(me)->query("no_fight")==1)
                return notify_fail("���ﲻ��ս��!\n");
        if(who-> query_temp("netdead") )
                return notify_fail("�������ڶ�����!\n");
        if(who->in_input() )
                return notify_fail("��������"+HIC " ����������" NOR+"\n");
        if(who->in_edit() ) 
                return notify_fail("��������"+HIY "�༭������" NOR+"\n");
        if( interactive(who)
        && query_idle(who) > 120 ) 
       return notify_fail("��������"+HIM "������" NOR+"\n");
        if(arrow->query("prick")) 
                return notify_fail(HIY "��֦��ʹ�ù���Ƶ�����������ˣ�\n" NOR);

        arrow_out=ARROW_D->shoot_at_vision(me,who,arrow,dir,bow);
        if(arrow->query_amount()==arrow_out)
        tell_object(me,"���"+arrow->query("name")+"������!\n");

        arrow->add_amount(-arrow_out);
        arrow1=new(base_name(arrow));
        arrow1->set_amount(arrow_out);
        me->start_busy(2);

        if(shot_random(me,who))
        {
        ARROW_D->shoot_vision(me,who,arrow1,dir,bow);
        arrow1->prick(who);
        if(me->query("jiali")!=0)
                {
                who->receive_damage("qi",me->query("jiali"));
                me->add("neili",-me->query("jiali"));
                }
        }
else    {
        ARROW_D->miss_shoot_vision(me,who,arrow1,dir,bow);
        ARROW_D->miss_shoot_vision(who,who,arrow1,dir,bow);
        destruct(arrow1);
        }
        return 1;

}

int shot_random(object me,object who)
{
        int my_arrow_level,enemy_listening_level,diff;
        my_arrow_level=me->query_skill("arrow");
        enemy_listening_level=who->query_skill("dodge")+who->query_skill("arrow");
        diff=(my_arrow_level-enemy_listening_level)/10;

        if(diff>=0)
                return random(diff+3);
                else    if(random(-diff)==1)
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : shoot <����> <����> 
��ָ�����ʹ����ӵ�й�����ʱ���ܹ�Զ���빥���Է�.������͵��˲���ͬ
һ���ռ�,���ҶԷ������Զ����ܹ�������ս��,Ҳ�������ǹ�׶㰵���ѷ���.
�������ڴ�,���Դ���������ƱȽϴ�,��������,
��:     �Լ����ߵ���֮��һ�����ڿռ��ֹս��ʱ;
        ���˷���ʱ;
        ���˱༭����ʱ;
        ������������ʱ;
        ���˶���ʱ;
������ʹ�ù��������Է�.
��Щ������ʱ�ľ���,��������ʲô�����������ʦ��ϵ.    
HELP
    );
    return 1;
}
