// guojing.c ����
// Write by yanzi@J.H.Y.J

#include <ansi.h>
int potential_lv(int exp);
inherit NPC;
string ask_job();
int job_over(string arg);
void create()
{
        set_name("����", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY"����"NOR);
        set("gender", "����");
        set("age", 25);
        set("long", 
                "�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
                "�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ����\n"
                "��ͨ���˵�ͽ�ܣ���������书��\n"
                "������һ����ɫ���ۣ���̬���࣬�غ����Ŀ��͸��һ������\n"
                "���˲��ɵò���һ������֮�顣\n");
        set("attitude", "peaceful");
        
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);
        set("per", 22);

        set("chat_chance", 1);
        set("chat_msg", ({
                "����̾�˿����������ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....\n",
                "����˵���������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
                (: random_move :),
        }));

        set("inquiry", ([
                "����" : (: ask_job :),
                "job"  : (: ask_job :),
                "����" : "�ض����ҵİ��ޣ�������������\n",
                "ؤ��" : "����������������\n",
                "��ʦ" : "�����ɹ���Χ��������������������ͽ����\n",
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 1800000);
        set("score", 200000);
         
        set_skill("force", 250);                // �����ڹ�
        set_skill("huntian-qigong", 230);       // ��������
        set_skill("unarmed", 220);              // ����ȭ��
        set_skill("xianglong-zhang", 200);      // ����ʮ����
        set_skill("dodge", 200);                // ��������
        set_skill("xiaoyaoyou", 180);            // ��ң��
        set_skill("parry", 220);                // �����м�
        
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
        
        setup();
        
   this_player()->carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        add_action("job_over","task");
}


string ask_job()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ���"+sizeof(ene)+"λ�����д輸�£���\n";
                if(sizeof(ene)==1) return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ�"+ene[0]->name()+"�д輸�£���\n";
        }

          if (me->query_temp("job_failed"))
                   {
                      command("kick "+me->query("id"));
                      me->delete_temp("job_failed");
                  me->delete_temp("mark/job_shadi");
                  me->delete_temp("carry_location");
                  me->delete_temp("where");
                      me->apply_condition("jobshadi_failed",10);
                      return "�����ʱ�������ɡ�\n";
                   }


          if (me->query_condition("jobshadi_failed")>0)
                   return "��"+RANK_D->query_respect(me)+"���ú��سǣ��Ҳ����ĸ���������\n";

        if(me->query_temp("mark/job_shadi")>0 ) return "��"+RANK_D->query_respect(me)+"���������������𣡡�\n";

/*        if((int)me->query("shen") < 0) return "��"+RANK_D->query_respect(me)+"�������������ǲ���ӭ����\n";
*/     
        if ((int)me->query("combat_exp")<100000) return "��"+RANK_D->query_respect(me)+"���޸���֮�������Ǳ��������Ϊ�ã���\n";
        if (me->query("shen")>0)
        {
        switch( random(2) ) {
                case 0:
                        me->set_temp("mark/job_shadi",1);
                        me->set_temp("carry_location","northgate1");            
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�������Ű����ξ��سǰɡ�";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",2);
                        me->set_temp("carry_location","northgate1");            
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�������Ű����ξ��سǰɡ�";

                       break;
                }       
        }
        else
        {
        switch( random(2) ) {
                case 0:
                        me->set_temp("mark/job_shadi",3);
                        me->set_temp("carry_location","southgate1");
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ��ȸ���Ű����ξ��سǰɡ�";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",4);
                        me->set_temp("carry_location","southgate1");
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�׻����Ű����ξ��سǰɡ�";

                       break;
                }
        }
}


int job_over(string arg)
{
        int job_pot,job_exp,bonus;
        object me = this_player();

        if(!arg) return 1;

        if(arg!="over") return 1;
        if(me->query_temp("help_killed")>0)
        {
                message_vision(CYN "$N������$n�ļ��˵������"+RANK_D->query_respect(me)+"��Ϊ��ɱ�У���������\n" NOR, this_object(), me);
                job_exp=((int)me->query_temp("killed_mgb"))*30;
                  job_pot=job_exp+400+random(200);
                  job_exp=job_exp+800+random(200);
                me->add("combat_exp", job_exp);
                bonus = (int)me->query("potential");
                bonus = bonus - (int)me->query("learned_points");
        	bonus = bonus + job_pot;
                if ( bonus > potential_lv((int)me->query("combat_exp")) )
                bonus = potential_lv((int)me->query("combat_exp"));
                bonus += (int)me->query("learned_points");
                me->set("potential", bonus );                
                me->delete_temp("killed_mgb"); 
                   me->apply_condition("jobshadi_failed",0);
                me->delete_temp("where");
                me->delete_temp("help_killed");//��lks��exp ��bug (��ͣtask over)      
                return 1;
        }
                
        if(me->query_temp("mark/job_shadi")==0)
        {
                message_vision(CYN"$N����$nһ��:��û����ʲô��ɲ���ɡ���\n",this_object(),me);
                return 1;
        }
        
        if(me->query_temp("job_over")==0)
        {
                message_vision(CYN"$N����$nһ��:������û��ɡ���\n"NOR,this_object(),me);
                return 1;
        }
       if(me->query_temp("killed_mgb")<1)
       {
                  message_vision(CYN"$N����$nһ��:��һ�����˶�ûɱ�����㻹�����ͣ�����\n"NOR,this_object(),me);
         me->delete_temp("job_over");
         me->delete_temp("mark/job_shadi");
                me->delete_temp("where");
                  return 1;
          }

        message_vision(CYN "$N��$n˵������"+RANK_D->query_respect(me)+"�����ˣ�ȥ��Ϣһ�°ɣ���\n" NOR, this_object(), me);
        me->delete_temp("job_over");
        me->delete_temp("mark/job_shadi");
        job_exp=((int)me->query_temp("killed_mgb"))*30;
          job_pot=job_exp+800+random(200);
          job_exp=job_exp+2000+random(400);
          bonus = (int)me->query("potential");
          bonus = bonus - (int)me->query("learned_points");
        	bonus = bonus + job_pot;
          if ( bonus > potential_lv((int)me->query("combat_exp")) )
          bonus = potential_lv((int)me->query("combat_exp"));
          bonus += (int)me->query("learned_points");
          me->set("potential", bonus );                          
        me->add("combat_exp", job_exp);
        me->delete_temp("killed_mgb");        
                me->delete_temp("where");
        return 1;

}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}



