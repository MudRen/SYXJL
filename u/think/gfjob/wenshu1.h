#include <ansi.h>

void init()
{
        call_out("dest", 1800);
        add_action("do_guankan", ({"guankan","kan"}));
        add_action("do_wancheng", ({"wancheng","wancheng"}));
}

int do_guankan(string arg)
{
        int now_time, time;
        object me;

        me = this_player();
        now_time = me->query_condition("guanfu_task"); 
        time = me->query_temp("guanfu_time");

        if(!arg) return 0;
         if( arg=="wen shu" || arg=="wen" || arg=="shu" ) {
                write(HIW"����һ������֪������׽�ý����������飬������������\n
�Ļ���һ���˵�ͷ��������һ��С�֣�����д�ţ�\n\n
����������"+me->query_temp("guanfu_target")+"��������׽�á���\n\n
�ݷɸ봫�飬�ķ�Ŀǰ��û�ڡ�"+me->query_temp("ch_weizhi")+"��������\n\n"NOR);

                if(now_time > time*3/4) write(HIR"�������г����ʱ��ȥѰ��Ŀ�ꡣ\n"NOR);
                if(now_time > time/2 && now_time <= time*3/4) write(HIR"�Ѿ���ȥһС��ʱ���ˡ�\n"NOR);
                if(now_time > time/4 && now_time <= time/2) write(HIR"�㻹��һ���ʱ��ȥ׷��Ŀ�ꡣ\n"NOR);
                if(now_time > time/8 && now_time <= time/4) write("���ʱ���Ѿ������ˡ�\n"NOR);
                if(now_time > 0 && now_time <= time/8) write(HIR"�ٸ������Ѿ������µ�Ŀ���ˣ���Ҫץ��ʱ���ˡ���\n"NOR);
                return 1;
        }
}

int do_wancheng(string arg)
{
// object ob;
        object me, target;
        int exp,pot,gfjob_times,now_time,shen;

        if(!arg) return notify_fail("��Ҫ��ʲô��\n");
        me = this_player();
         shen = (int)me->query("shen");
        target = present(arg, environment(me));
        now_time = me->query_condition("guanfu_task");

        if(!target) return notify_fail("�Ҳ������������\n");
        if(target->query("id") != "corpse") return notify_fail("�㲢û���������\n");
        if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("�Ǹ�������Ŀ�꣡\n");
        if(target->query("victim_user")) return notify_fail("�ٺ٣������ף���\n");
        if(target->query("kill_by") != me) return notify_fail("������һ����Ŀ���Ѿ�����ɱ�ˡ�\n");
        if(target->query_temp("mark/dune1")) return notify_fail("���Ѿ���һ���Ѿ�����ɱ����ʬ���ˡ�\n");

        me->add("gf_job",1);
        gfjob_times=(int)me->query("gf_job");
        if (gfjob_times < 1) gfjob_times = 1;
    message_vision(HIW"$N��Цһ�����ӻ����ͳ����鿴�˿���΢���ھ�����������з����ȥ��"
"\n�������黯��ƬƬѩƬ��������$n���ϡ�\n"NOR, me, target);
    write(HIR"�ܺã���ɹ������������Ŀǰ���Ѿ�Ϊ�ٸ�����"+gfjob_times+"�ι��ס�\n"NOR);
        target->set("long", target->query("long")+"������������ֽƬ��\n");
        target->set_temp("mark/dune1",1);
//      if(me->query("potential") > me->query("max_pot")) 
//      me->set("potential", me->query("max_pot"));
        me->delete_temp("guanfu_time");
        me->clear_condition("guanfu_task");
        me->delete_temp("guanfu_target");
        me->delete_temp("ch_weizhi");
        me->delete_temp("path_rooms");
        me->delete_temp("gstart_rooms");
        me->delete_temp("mark/gkill3");

        if ((int)me->query("combat_exp")<2000000){
         exp=((30+random(10))*10); 
         pot=exp/4; 
         me->set("shen",shen);
         me->add("potential",pot);
         me->add("combat_exp",exp);
         me->add("meili",1);
         destruct(this_object());
         return 1;
        }
        if ((int)me->query("combat_exp")>2000000 && 
        me->query("combat_exp")<3000000){
         exp=((50+random(10))*10); 
         pot=exp/4; 
         me->set("shen",shen);
         me->add("potential",pot);
         me->add("combat_exp",exp);
         me->add("meili",1);
                destruct(this_object());
                return 1;
        }
        if ((int)me->query("combat_exp")>3000000 && 
         me->query("combat_exp")<4000000){
         exp=((80+random(10))*10); 
         pot=exp/4; 
         me->set("shen",shen);
         me->add("meili",1);
         me->add("potential",pot);
         me->add("combat_exp",exp);
         destruct(this_object());
         return 1;
        }
        if ((int)me->query("combat_exp")>4000000 && 
         me->query("combat_exp")<5000000){
         exp=((120+random(10))*10); 
         pot=exp/4; 
         me->set("shen",shen);
         me->add("meili",1);
         me->add("potential",pot);
         me->add("combat_exp",exp);
         destruct(this_object());
         return 1;
        }
         exp=((150+random(10))*10); 
         pot=exp/4; 
         me->add("meili",1);
         me->set("shen",shen);
        me->add("potential",pot);
        me->add("combat_exp",exp);
        destruct(this_object());
        return 1;
}
void dest()
{
       object me;
       me = this_player();
       write(HIY"�����Ѿ��������ģ�������ˣ������Ѿ�ûʲ�����ˣ���ֻ�����ֶ�����\n"NOR, me);  
       destruct(this_object());
}


