#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"�ż�"NOR, ({ "letter","xin","secret letter" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ���ؿ��ʵݣ��ŷ�ĺ���ʵ����ڸ��ź���ӡ����\n");
                set("no_drop", 1);
                set("no_get", 1);
                set("no_give", 1);
                set("material", "paper");
         }
}
void init()
{        
        call_out("dest",random(100)+900);
        add_action("do_send", "songxin");
        add_action("do_send", "gei");
        add_action("do_drop", "diuxin"); 
        add_action("do_drop", "drop");        add_action("do_look", "kan");
        add_action("do_look", "chakan");
}
int do_look(string arg)
{
        object me;

        me = this_player();
        if(!arg) return 0;
        if( (arg=="letter"||arg=="xin")&&me->query_temp("hate_songxin")) {
                write(                      "\n����һ������վ�������ż�������д��"HIR"��"+me->query_temp("songxin_target_name")+"�� ������\n"NOR);                             write(HIW"��Ϊ��վ����"+me->query("hate_job")+"�ι�����\n"NOR);   
     write(HIY"���Ѿ�Ϊ��վ��������"+me->query("job_tp")+"�ι��������ͣ�\n"NOR);                                                           
        }else{
        if( (arg=="letter"||arg=="xin")&&!me->query_temp("hate_songxin")) 
 write("����һ���ؿ��ʵݣ��ŷ�ĺ���ʵ����ڸ��ź���ӡ����\n");
         }
                return 1;

}

int do_send(string arg)
{
        int exp,pot,sco;
//        object ob;
        object me,target;
        string t_name,t_id;
        me=this_player();
        if(!arg) return notify_fail("��Ҫ�͸�˭��\n");
        if(!objectp(target = present(arg, environment(me)))) return notify_fail("������㣬��Ҫ���ŵ��˲������\n");
        t_name = target->query("name");
        t_id = target->query("id");

        if(!target) return notify_fail("������㣬��Ҫ���ŵ��˲������\n");
        if(target->query("victim_user")) return notify_fail("�ٺ٣������ף���\n");
        if(me->query_temp("hate_songxin_late"))
                return notify_fail("�������Ѿ�ʧ���ˣ���������һ���ɡ�\n");
        if (!present("secret letter", this_player()) )
           return notify_fail("������û��Я���ż���\n"); 
 if (!me->query_temp("hate_songxin"))
            return notify_fail(t_name+"����������վ������,Ҫ���͵ģ����ǲ��Ǵӱ������������ģ�");
 if(me->query_temp("songxin_target_name") != t_name) 
            return notify_fail(t_name+"��������Ų��Ǹ��ҵģ����ǲ����ʹ��ˣ�");
message_vision("$N������$nһ���š�\n",me, target);
            message_vision(HIC "$N�ӹ��ſ��˿������˵�ͷ˵������λ"+RANK_D->query_respect(me)+"�������ˡ�\n"NOR, target, me);
            exp=10+random(50);
            pot=10+random(20);     
            sco=5+random(5);               me->add("potential",pot);
            me->add("combat_exp",exp);
            me->add("score",sco);
            me->add("hate_job",1);
            me->add("job_tp",1);
            if( me->query("job_tp") >= 100) 
               { 
               write(HIY"\n���㾤��ҵҵ��Ϊ��վ�����£���������վ�ϰ����ʶ\n"NOR);
               write(HIR"\n�㱻��վ�ϰ影���� 2000 �㾭��\n"NOR);
               write(HIR"\n�㱻��վ�ϰ影���� 1000 ��Ǳ��\n"NOR);
               write(HIR"\n�㱻��վ�ϰ影���� 500 ������\n"NOR);

            me->add("combat_exp",2000);
            me->add("potential",1000); 
            me->delete("job_tp");            me->add("score",500);
            me->start_busy(2 + random(4));
            destruct(this_object());
                 return 1; 
                 } 
           
            tell_object(me,HIW"�ã��������,�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       chinese_number(sco) + "������\n"
                       NOR);
            me->delete_temp("hate_songxin");
            me->delete_temp("songxin_target_name"); 
            me->delete_temp("songxin_where");    
            me->set_temp("songxin_ok",1);
            destruct(this_object());
            return 1;
}
int do_drop(string arg)
{
        object me,target;

        me = this_player();

        if( !arg ) return 0;

        if( arg=="letter") 
        {
                tell_object(me,"�㳢�����������վ���������\n");
{
message_vision(HIR"$N��������ļ�����ֻ��̾�˿�����������˭�����Ҳ����أ�\n"NOR, me, target);
message_vision(HIG"$N�����ǽ������еļ��������ˡ�\n"NOR,me, target);
            me->add("score",-(random(40)+5));
            me->add("hate_job",-1);
            me->delete_temp("hate_songxin");
            me->delete("job_tp");
            me->delete_temp("songxin_target_name"); 
            me->delete_temp("songxin_where");     
            me->set_temp("songxin_ok",1); 
            destruct(this_object());
}
            return 1;
    }
}
void dest()
{
       object me;
       me = this_player();
       write("���ź�Ȼ������·�ϲ����ˡ�\n", me);  
       destruct(this_object());
}
