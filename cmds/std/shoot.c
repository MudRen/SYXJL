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
                return notify_fail("你正忙着呢!\n");
        if(!have_bow)
                return notify_fail("你必须有一张弓,才可以射箭!\n");
        if(!have_arrow)
                return notify_fail("你的箭已经用完了!\n");
        if(!arg)
                return notify_fail("命令格式:shoot <方向> <人名>\n");
        if(sscanf(arg,"%s %s",dir,id)!=2)
                return notify_fail("命令格式:shoot <方向> <人名>\n");

        direction=here->query("exits");
        dire=keys(direction);
        for(i=0;i<sizeof(dire);i++)
        {
        if(dire[i]==dir)
                have_dir=1;
        }

        if(!have_dir)
                return notify_fail("没有这个方向!\n");
        
        neighbour=ROOM_D->get_neighbour(here,dir);

        if(!who=present(id,neighbour))
                return notify_fail("没有这个人!\n");
        if(!who->is_character())
                return notify_fail("这不是个人!\n");
        if(environment(who)!=neighbour)
                return notify_fail("此人不在那里!\n");
        if(environment(me)==environment(who))
                return notify_fail("太近了,根本没有办法射到此人.\n");

        if(environment(who)->query("no_fight")==1)
                return notify_fail("你没有办法射到那里的人,那里的人是受保护的.\n");
        if(environment(me)->query("no_fight")==1)
                return notify_fail("这里不许战斗!\n");
        if(who-> query_temp("netdead") )
                return notify_fail("此人正在断线中!\n");
        if(who->in_input() )
                return notify_fail("此人正在"+HIC " 输入文字中" NOR+"\n");
        if(who->in_edit() ) 
                return notify_fail("此人正在"+HIY "编辑档案中" NOR+"\n");
        if( interactive(who)
        && query_idle(who) > 120 ) 
       return notify_fail("此人正在"+HIM "发呆中" NOR+"\n");
        if(arrow->query("prick")) 
                return notify_fail(HIY "这枝箭使用过于频繁不能再用了！\n" NOR);

        arrow_out=ARROW_D->shoot_at_vision(me,who,arrow,dir,bow);
        if(arrow->query_amount()==arrow_out)
        tell_object(me,"你的"+arrow->query("name")+"用完了!\n");

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
指令格式 : shoot <方向> <对象> 
此指令可以使您在拥有弓箭的时候能够远距离攻击对方.您必须和敌人不在同
一个空间,而且对方不会自动的跑过来与您战斗,也许就是明枪易躲暗箭难防吧.
正是由于此,所以此命令的限制比较大,初步决定,
当:     自己或者敌人之中一人所在空间禁止战斗时;
        敌人发呆时;
        敌人编辑档案时;
        敌人输入文字时;
        敌人断线时;
不允许使用弓箭攻击对方.
这些还是临时的决定,如果玩家有什么建议可以与巫师联系.    
HELP
    );
    return 1;
}
