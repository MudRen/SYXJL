// xinshi.c
// by hate.
#include <ansi.h>
inherit NPC;

mapping *names=({
           
      (["name":                "��ľ����",
       "where" :              "�䵱��",]),  
      (["name":                "��Զ��",
       "where" :              "�䵱��",]),  
      (["name":                "������",
       "where" :              "�䵱��",]),  
      (["name":                "����Ϫ",
       "where" :              "�䵱��",]), 
      (["name":                "����ͤ",
       "where" :              "�䵱��",]), 
      (["name":                "�������",
       "where" :              "�䵱��",]), 
      (["name":                "�տն�",
       "where" :              "ؤ��",]),
      (["name":                "������",
       "where" :              "�����ھ�",]),
      (["name":                "��Ұ��",
       "where" :              "����",]),
      (["name":                "������",
       "where" :              "������",]),
      (["name":                "����ϼ",
       "where" :              "������",]),
      (["name":                "������",
       "where" :              "������",]),
      (["name":                "������",
       "where" :              "������",]),
      (["name":                "����",
       "where" :              "�һ���",]),        
      (["name":                "��ƽ֮",
       "where" :              "���ݳ�",]),  
      (["name":                "�����",
       "where" :              "ؤ��",]),        
      (["name":                "�Թ���",
       "where" :              "ؤ��",]), 
      (["name":                "��ҩ��",
       "where" :              "���ݳ�",]),        
      (["name":                "̷�Ѽ�",
       "where" :              "���ݳ�",]),        
      (["name":                "����",
       "where" :              "���ݳ�",]),        
      (["name":                "Ǯ�ۿ�",
       "where" :              "���ݳ�",]),        
      (["name":                "���",
       "where" :              "���ݳ�",]),        
      (["name":                "����",
       "where" :              "������",]),        
      (["name":                "ŷ����",
       "where" :              "����ɽ��",]),        
      (["name":                "���ͷ",
       "where" :              "����ɽ��",]),        
      (["name":                "����",
       "where" :              "����ɽ��",]),        
      (["name":                "���",
       "where" :              "��Ĺ��",]),        
      (["name":                "С��Ů",
       "where" :              "��Ĺ��",]),        
      (["name":                "�ֳ�Ӣ",
       "where" :              "��Ĺ��",]),        
      (["name":                "����",
       "where" :              "���ݳ�",]),        
      (["name":                "½��Ӣ",
       "where" :              "���ݳ�",]),        
      (["name":                "��ȫ",
       "where" :              "ؤ��",]),        
      (["name":                "��Ӣ",
       "where" :              "�һ���",]),
      (["name":                "��Ĭ��",
       "where" :              "�һ���",]),     
      (["name":                "½�˷�",
       "where" :              "���ݳ�",]),        
      (["name":                "ŷ����",
       "where" :              "���ݳ�",]),        
      (["name":                "�����",
       "where" :              "�һ���",]),
      (["name":                "÷����",
       "where" :              "�һ���",]),     
      (["name":                "��ҩʦ",
       "where" :              "�һ���",]),     
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "������",
       "where" :              "������",]),
       (["name":                "�۽�����",
       "where" :              "������",]),
       (["name":                "��ɫ����",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "���Ѵ�ʦ",
       "where" :              "������",]),
       (["name":                "�����ʦ",
       "where" :              "������",]),
       (["name":                "�μ�",
       "where" :              "������",]),
       (["name":                "�μ�",
       "where" :              "������",]),
       (["name":                "�ξ�",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
      (["name":                "ʷ��ɽ",
       "where" :              "�����ؽ�",]),
      (["name":                "�ɻ���",
       "where" :              "������",]), 
      (["name":                "������",
       "where" :              "����",]),
      (["name":                "�ܵ�",
       "where" :              "����",]),
      (["name":                "˵����",
       "where" :              "����",]),
      (["name":                "����",
       "where" :              "����",]),
      (["name":                "��Ȼ",
       "where" :              "����",]),
     (["name":                "��ң",
       "where" :              "����",]),
     (["name":                "�巨����",
       "where" :              "������",]),
     (["name":                "���ޱ���",
       "where" :              "������",]),
       });   

string ask_job();

void create()
{
        set_name("�ϰ�", ({ "boss" }));
        set("title", HIC"��վ�ϰ�"NOR);
        set("gender", "����");
        set("age", 43);
        set("str", 27);
        set("dex", 26);
        set("long", "����һ�����˴��š�\n");
        set("combat_exp", 400000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("whip", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 20);

        set("max_qi", 900);
        set("neili", 900); 
        set("max_neili", 900);
        set("jiali", 20);
       set("inquiry", 
                ([
                        "����" : (: ask_job :),
                        "job" : (: ask_job :),
                ]));


       setup();
       carry_object("/d/city/obj/cloth")->wear();
}

string ask_job()
{
        object me;
        object ob;
       mapping target;
        ob=this_player();
        me=this_object();
       if (ob->query_temp("hate_songxin"))
                return ("�㲻���Ѿ��������ŵ������𣿻�����ȥ����\n");
        if (ob->query("combat_exp")>=100000)
                     return ("�ҿ�����书�����൱�Ĺ����ˣ��Ͳ���������������ˣ�ȥ�ɵ���ʲô�ɡ�\n");
       if (ob->query("combat_exp")<10000)
                     return ("��Ĺ��򻹲����������ſ��Ǻ�Σ�յ��£��ҿɲ��ҽ�����������\n");
 
       target = names[random(sizeof(names))];
       ob->delete_temp("songxin_ok");
       ob->delete_temp("hate_songxin_late");

       ob->set_temp("hate_songxin",1);
       ob->start_busy(5 + random(2));
       ob->set_temp("songxin_target_name", target["name"]);
       ob->set_temp("songxin_where", target["where"]);
switch(random(3)) {
        case 0:
        message_vision("$N���İ�$n����һ�ԣ�����˵�����������ܺ������͵���"+ob->query_temp("songxin_where")+"��"
"�ġ�"+ob->query_temp("songxin_target_name")+"�����ϡ�\n",me,ob);
       message_vision("$N����$nһ���ܺ���\n",me,ob);
        ob=new("/u/hate/songxin/hate_letter");
        ob->start_busy(4 + random(4));
        break;
        case 1:
        message_vision("$N���˵�ͷ��˵���������������з��ţ���ȥ�����͵���"+ob->query_temp("songxin_where")+"��"
"�ġ�"+ob->query_temp("songxin_target_name")+"�����ϡ�\n",me,ob);
        message_vision("$N����$nһ���š�\n",me,ob);
        ob=new("/u/hate/songxin/hate_letter");
        ob->start_busy(4 + random(4));
        break;
        case 2:
        message_vision("$N΢΢һЦ���ӻ����ͳ�һ���ţ�˵������Ͻ������͵���"+ob->query_temp("songxin_where")+"��"
"�ġ�"+ob->query_temp("songxin_target_name")+"�����ϡ�\n",me,ob);
       message_vision("$N����$nһ���š�\n",me,ob);
        ob=new("/u/hate/songxin/hate_letter"); 
        ob->start_busy(4 + random(4));        break;
        }
        ob->move(this_player());
      return "�ٶ�Ҫ�죡��Ҫ����������Ӵ����";
}
