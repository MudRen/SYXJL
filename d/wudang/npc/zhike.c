// zhike.c ֪��
// creat by sec

#include <ansi.h>

inherit NPC;

string do_shoumen();
string do_guard();
string do_cancl();
void do_kill(string);
void get_exp(object);
void get_money(object);
void clear_cancl(object) ;
void do_mm();
int do_stop(object);
int count=0;
object ob;

void create()
{
        set_name("֪�͵���", ({ "zhike daozhang", "zhike" }));
        set("long", 
              "�����䵱ɽ��֪�͵�����\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 400);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 50000);
        set("shen", 5000);

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("literate", 40);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("taiji-shengong", 30);
        set_skill("taiji-jian", 40);
        set_skill("taoism", 20);
        set_skill("tiyunzong", 40);

        map_skill("parry", "taiji-jian");
        map_skill("force", "taiji-shengong");
        map_skill("sword", "taiji-jian");
        map_skill("dodge", "tiyunzong");

        create_family("�䵱��", 4, "����");

         set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
               (: perform_action, "sword.lian" :),
               (: perform_action, "sword.sui" :),
         }) );

        set("inquiry", ([
                "����" : (: do_shoumen :),
                "����" : (: do_guard :),
                "����" : (: do_cancl :),
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
   object ob;
   ::init();
   if (interactive(ob = this_player()) && !is_fighting()) {
      remove_call_out("greeting");
      call_out("greeting", 1, ob);
   }
// add_action("do_stop","go");
   add_action("do_stop","du");
   add_action("do_stop","dazuo");
   add_action("do_stop","study");
   add_action("do_stop","tuna");
   add_action("do_stop","lian");
   add_action("do_stop","practice");
   add_action("do_stop","exercise");
   add_action("do_stop","meditate");
   add_action("do_kill","kill");
   add_action("do_kill","hit");
   add_action("do_kill","touxi");
   add_action("do_stop","quit");
}

void do_kill(string arg)
{
        object ob=this_player();
        object me=this_object();

        if (!arg||arg=="ren"||arg=="mengmian"||arg=="mengmian ren")
                return;

        message_vision(YEL"֪�͵�����$N˵���������ڴ�ɱ�����ף��䵱�ݲ�������Ұ����\n"NOR, ob);
       me->kill_ob(ob);
       ob->fight_ob(me);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query("shen")<-1000) {
                        say ("֪�͵���˵������λ" + RANK_D->query_respect(ob) +"������ذɡ�\n");
              return;
         }
        switch( random(2) ) {
              case 0:
                 say( "֪�͵�������˵������ӭ��λ" + RANK_D->query_respect(ob)
                               + "�����䵱ʥ�ء�\n");
                 break;
              case 1:
                        command("bow" + ob->query("id"));
                 break;
        }
}

string do_shoumen()
{
        ob=this_player(); 
   
        if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�˵��\n";

        if ( environment(this_object())->query("short")!="�䵱ɽ��" )
                return "���ﲻ���䵱ɽ�ţ�����ô���ţ�";
        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

        if ( ob->query("in_shoumen") || ob->query("work_shoumen"))
                return "���㲻�Ǽ������������� ����㲻��ɣ��ͷ����ɡ���\n";

        if (count>=4) {
                message_vision(YEL"$N��ԸΪ֪�͵������䵱ɽ�š�\n"NOR,ob);
                return "���������ŵ��˼������ˣ���Ȼ������ɡ���\n";
                }
               if ( (int)ob->query_condition("shoumen" ) > 0 )
                return "��ղ������ţ����ǵ�һ�������ɣ�\n";
        ++count;
        ob->start_busy(4);

        ob->set("in_shoumen",1);
        call_out("get_exp", 200, ob);

        ob->set("oldtitle",ob->query("title"));
        ob->set("title",HIW"ɽ������"NOR);
//  ob->apply_condition("shoumen", 10);
        message_vision(YEL"$N��ԸΪ֪�͵������䵱ɽ�š�\n"NOR,ob);
        return "���������ںú����Űɣ��ɱ���а�����ײ���䵱ʥ�ء���\n";
}

string do_guard()
{
        ob=this_player();
/*
        if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�˵��\n";
*/
        if ( environment(this_object())->query("short")!="�䵱ɽ��" )
                return "���ﲻ���䵱ɽ�ţ�����ô���ţ�";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

        if ( ob->query("in_shoumen") || ob->query("work_shoumen"))
                return "���㲻�Ǽ������������� ����㲻��ɣ��ͷ����ɡ���\n";

        if (count>=4){
                message_vision(YEL"$N��Ϊ֪�͵������䵱ɽ�š�\n"NOR,ob);
                return "���������ŵ��˼������ˣ���Ȼ������ɡ���\n";
                }

        ++count;
       ob->start_busy(4);

        ob->set("work_shoumen",1);

        call_out("get_money", 200, ob);

        ob->set("oldtitle",ob->query("title"));
        ob->set("title",HIW"ɽ������"NOR);
// ob->apply_condition("shoumen", 10);
        message_vision(YEL"$N��Ϊ֪�͵������䵱ɽ�š�\n"NOR,ob);
        return "���������ںú����Űɣ��ɱ���а��֮ͽײ�����䵱ʥ�ء���\n";
}

int do_stop(object ob)
{
        ob=this_player();
  
        if ( ob->query("in_shoumen") || ob->query("work_shoumen")) {
                tell_object(ob,"�㻹�ǰ��ĵ����Ű�!\n");
                return 1;
                }

        return 0;
}

string do_cancl()
{
        ob=this_player();
/*
        if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�˵��\n";
*/
        if (!ob->query("in_shoumen") && !ob->query("work_shoumen"))
                return "���㻹û���ţ���Ҫ�����ˣ���";

        ob->delete("in_shoumen");
        ob->delete("work_shoumen");

       --count;

        if (count<=0) count=0;

        ob->set("title",ob->query("oldtitle"));
        ob->delete("oldtitle");
        message_vision(YEL"$NͻȻ��������ɽ���ˡ�\n",ob);
        return "�����¶����ڼ�֣��㲻Ը��ɽ�ž��߰ɡ���\n";
}

void get_exp(object ob)
{
        int pot;
        --count;
        if (count<=0) count=0;

        pot = 10+random(ob->query_str())/2;

        if (!(ob->query_temp("in_cancl")) && ob->query("in_shoumen") && present("zhike daozhang", environment(ob)) && living(present("zhike daozhang", environment(ob)))) {
                if (ob->query("do_shoumen")<11) {
                        ob->set("combat_exp",ob->query("combat_exp")+random(10)+1);
                        ob->set("do_shoumen",ob->query("do_shoumen")+1);
                }else {
                        ob->set("combat_exp",ob->query("combat_exp")+30+random(10));
                        if(((int)ob->query("learned_points") + 120) > (int)ob->query("potential")
                            && ((int)ob->query("potential") - (int)ob->query("learned_points")) < (120-pot)){
                                ob->add("potential",pot);
                                }
                        else ob->set("potential",ob->query("learned_points")+120);
                        }

                ob->delete("in_shoumen");   
                ob->set("title",ob->query("oldtitle"));
                ob->delete("oldtitle");

                 if (random(100)>80) {
                        remove_call_out("do_mm");
                        call_out("do_mm",15);
                        }

                ob->set_temp("in_cancl",1);
                call_out("clear_cancl",199,ob);
                message_vision(NOR"֪�͵�����$N˵����������ʱ�䵽�ˣ��������ˡ���\n"NOR,ob);
                return;
                }
        return;
}

void get_money(object ob)
{
        object mo;
        int amount;
        --count;
        if (count<=0) count=0;

 if (!(ob->query_temp("in_cancl")) && ob->query("work_shoumen") && present("zhike daozhang", environment(ob)) && living(present("zhike daozhang", environment(ob)))) {
                ob->delete("work_shoumen");   
                ob->set("title",ob->query("oldtitle"));
                ob->delete("oldtitle");
                mo=new("/clone/money/silver");
                amount=random(50)+1;
                mo->set_amount(amount);
                mo->move(ob);
                if (random(100)>80) {
                        remove_call_out("do_mm");
                        call_out("do_mm",15);
                        }

                ob->set_temp("in_cancl",1);
                call_out("clear_cancl",199,ob);

                message_vision(sprintf("֪�͵����ó�%s��"HIW"����"NOR"��$N��\n",chinese_number(amount)),ob);
                message_vision(NOR"֪�͵�����$N˵����������ʱ�䵽�ˣ��������ˡ���\n"NOR,ob);
                return;
                }
        return;
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0){
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}

void do_mm()
{
        object mm;
        say(HIR"ͻȻ��һ�������˴�ɽ�³���������\n"NOR);
        mm=new("/d/wudang/npc/mengmian_ren.c");
        mm->move("/d/wudang/shanmen");
        return;
}

void clear_cancl(object ob)
{
  ob->delete_temp("in_cancl");
}

