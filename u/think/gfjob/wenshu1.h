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
                write(HIW"这是一张扬州知府悬赏捉拿江洋大盗的文书，上面栩栩如生\n
的画着一个人的头像，下面有一行小字，上面写着：\n\n
“江洋大盗「"+me->query_temp("guanfu_target")+"」，悬赏捉拿”。\n\n
据飞鸽传书，改犯目前出没于「"+me->query_temp("ch_weizhi")+"」附近。\n\n"NOR);

                if(now_time > time*3/4) write(HIR"你现在有充足的时间去寻找目标。\n"NOR);
                if(now_time > time/2 && now_time <= time*3/4) write(HIR"已经过去一小半时间了。\n"NOR);
                if(now_time > time/4 && now_time <= time/2) write(HIR"你还有一半的时间去追踪目标。\n"NOR);
                if(now_time > time/8 && now_time <= time/4) write("你的时间已经不多了。\n"NOR);
                if(now_time > 0 && now_time <= time/8) write(HIR"官府好象已经快有新的目标了，你要抓紧时间了。！\n"NOR);
                return 1;
        }
}

int do_wancheng(string arg)
{
// object ob;
        object me, target;
        int exp,pot,gfjob_times,now_time,shen;

        if(!arg) return notify_fail("你要干什么？\n");
        me = this_player();
         shen = (int)me->query("shen");
        target = present(arg, environment(me));
        now_time = me->query_condition("guanfu_task");

        if(!target) return notify_fail("找不到这个东西。\n");
        if(target->query("id") != "corpse") return notify_fail("你并没有完成任务。\n");
        if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("那个并不是目标！\n");
        if(target->query("victim_user")) return notify_fail("嘿嘿，想作弊？！\n");
        if(target->query("kill_by") != me) return notify_fail("你晚了一步，目标已经被人杀了。\n");
        if(target->query_temp("mark/dune1")) return notify_fail("那已经是一具已经被人杀过的尸体了。\n");

        me->add("gf_job",1);
        gfjob_times=(int)me->query("gf_job");
        if (gfjob_times < 1) gfjob_times = 1;
    message_vision(HIW"$N冷笑一声，从怀中掏出文书看了看，微运内劲将文书向空中飞射出去。"
"\n但见文书化做片片雪片，飞落在$n身上。\n"NOR, me, target);
    write(HIR"很好！你成功地完成了任务。目前你已经为官府做了"+gfjob_times+"次贡献。\n"NOR);
        target->set("long", target->query("long")+"上面飞落着许多纸片。\n");
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
       write(HIY"文书已经被你揉的模糊不清了，看来已经没什麽用了，你只好随手丢掉。\n"NOR, me);  
       destruct(this_object());
}


