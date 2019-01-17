//zhucong.c csy by 98-12-14

#include <ansi.h>
inherit NPC;
void greeting(object ob);
void create()

{
        set_name("���", ({ "zhu cong","zhu"}));         
        set("nickname", YEL"��������"NOR);
        set("title","��������");
        set("long", "���ǽ��������е�����������һ���������ר���򱧲�ƽ��\n");
        set("gender", "����");
        set("attitude", "friendly");
        set("unique", 1);
        set_temp("no_return", 1);
        set("age", 28);
        set("per",20);
        set("shen", 50000);
        set("str", 30);
        set("int", 26);
        set("con", 25);
        set("dex", 23);
        set("max_qi", 2000);
        set("qi", 2000);
        set("max_jing", 1500);
        set("jing", 1500);
        set("neili", 2500);
        set("max_neili", 2500);
        set("eff_jingli", 2000);
        set("jiali", 100);
        set("combat_exp",800000);
        set_skill("cuff", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("stealing", 200);
        set_skill("poyu-quan", 130);
        set_skill("kunlun-shenfa", 200);
        set_skill("taiji-shengong", 150);
        set_skill("parry", 150);
        map_skill("force","taiji-shengong");
        map_skill("dodge","kunlun-shenfa");
        map_skill("cuff","poyu-quan");
        map_skill("parry","poyu-quan");
        prepare_skill("cuff","poyu-quan"); 
        set("chat_chance", 20);
        set("chat_msg", ({                                                                                                                      
           (: random_move :),           
        }));

        setup();
 
        carry_object("/clone/misc/cloth")->wear();

}

void init(object obj1)
{
        object ob;        
        ::init();
        
                ob=this_player();
                //if ((ob->query("can_ride")||interactive(ob)) && !ob->is_fighting() && living(ob)&& !wizardp(ob)) 
                if ((ob->query("can_ride")||interactive(ob)) && !ob->is_fighting() && living(ob)) 
                {
                        greeting(ob);
          }
//      add_action("do_hit", "hit");
        remove_call_out("do_back");
        call_out("do_back", 120, ob);
}

int steal_object(object ob)
{
        if(ob->query("unique"))
        return 1;
        return 0;
}

void greeting(object ob)
{
        object *inv,*ob1,ob2;        
        int j;
        inv = deep_inventory(ob);

        if( !sizeof(inv) )
        return ;

        if(wizardp(ob))
        return ;        

        if(!living(this_object()))
        return ;        

        ob1 = filter_array(inv,(:steal_object:));
        if( !sizeof(ob1) )
          return;  
                this_object()->set("chat_chance", -1);
                                write("��һ��С�ģ����ײ��һ������������\n");
                        ob->start_busy(2);
                if(ob->query("can_ride"))
                        if(ob->query_temp("rider"))
                        {
                        ob->query_temp("rider")->start_busy(2);
                        
                        tell_object(ob->query_temp("rider"),"��һ��С�ģ��������ײ��һ������������\n��");

                        }
  

                j=random(sizeof(ob1));
        ob2=ob1[j];      
        remove_call_out("steal_ok");
        call_out("steal_ok",0 , ob, ob2);
        return;
}

int steal_ok(object ob,object ob2)
{
        int steal_ok;
        if(environment(ob)!= environment(this_object()))
          return 1;
         if(random(100) > 60)
           steal_ok=1;
         if(steal_ok){                    
          ob2->move(this_object());
          
         if(ob->query("can_ride"))
                 {
                  message_vision(HIR"$N���������һ��$n��Ȼ��ת��ͷȥ��͵͵�Ķ���$nЦ��\n\n"NOR, this_object(),ob);
                 }else
                 {
                   message_vision(HIR"$N���������һ��$n��Ȼ��ת��ͷȥ��͵͵�Ķ���$nЦ��$n�����е㲻�Ծ���\n\n"NOR, this_object(),ob);
                 }
          remove_call_out("do_rumor");
          call_out("do_rumor",2,ob,ob2);
          remove_call_out("do_back");
          call_out("do_back",2);
          ob->start_busy(1);
          return 1;
          }     
         if(ob->query("can_ride"))
                 {
                 message_vision(HIY"$N��ɫ��Щ���ţ�����ʲôʲô�����¶�ˡ�\n"NOR,this_object());
     command("xixi");
                 }
                 else
                 {
                                         message_vision(HIY"$n������������$N������ֻ��$N��Щ���ţ�����$nҲû̫���⡣\n"NOR,this_object(),ob);
     command("say "+RANK_D->query_respect(ob)+"����...��������...�����δ���...���ѽ����...������");

                 }
                this_object()->set("chat_chance", 20);
     return 1;               
}

void do_rumor(object ob,object ob2)
{    
        command("rumor ���˿�����ϴ�"+ob->query("name")+"����͵����һ"+ ob2->query("unit")+ob2->query("name")+"��");
        remove_call_out("destrory");
        call_out("destrory", 150, ob2);
        if (random(10) > 6)
        command("chat* innocent "+ob->query("id"));
        else command("chat* slapsb");
}

int accept_fight(object me)
{
        command("say �������յ�΢���Ǹ���"+RANK_D->query_respect(me)+"��ǰ�ֳ�\n");
        return 0;
}

void do_back()
{
        message_vision("һ����$N��֪���ﵽ����ȥ�ˡ�\n", this_object());
                this_object()->set("chat_chance", 20);
        switch(random(20)){
        case 0: this_object()->move("/d/shaolin/matou2"); break;
        case 1: this_object()->move("/d/city/beidajie1"); break;
        case 2: this_object()->move("/d/city/xidajie1"); break;
        case 3: this_object()->move("/d/city/nanmen"); break;
        case 4: this_object()->move("/d/city/dangpu"); break;
        case 5: this_object()->move("/d/city/guangchang"); break;
        case 6: this_object()->move("/d/wudang/sanqingdian"); break;
       case 7: this_object()->move("/d/kunlun/qianting"); break;
        case 8: this_object()->move("/d/huashan/buwei1"); break;
        case 9: this_object()->move("/d/taishan/yitian"); break;
        case 10: this_object()->move("/d/baituo/damen"); break;
        case 11: this_object()->move("/d/city/kedian"); break;
        case 12: this_object()->move("/d/shashou/jiaochang"); break;
        case 13: this_object()->move("/d/mr/xiaoshe"); break;
        case 15: this_object()->move("/d/taishan/shijin"); break;
        case 16: this_object()->move("/d/taishan/fengchan"); break;
        case 17: this_object()->move("/d/city2/qianzhua"); break;
        case 18: this_object()->move("/d/xinfang/bieshuqu"); break;
        case 19: this_object()->move("/d/city2/tian_anm"); break;
        case 20: this_object()->move("/d/mj/shiwangdian"); break;
        }                  
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("max_neili",this_object()->query("max_neili"));
        this_object()->set("neili",this_object()->query("max_neili"));
        this_object()->set("max_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("jing"));
        this_object()->set("jingli",this_object()->query("eff_jingli"));
        this_object()->clear_condition();
        message_vision(HIY"$N���Ҵҵ����˹�����\n"NOR, this_object());       
        command("say �ٺ٣�������ջ񲻴��");
}

void destrory(object ob)
{
        destruct(ob);
        return ;
}

