//miejue.c ���ʦ̫
//create bye cuer  
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void heal();
int ask_ling();
int ask_xiashan();

void init()
{
  object me = this_player();
  object ob = this_object();
  if( me->query("family/master_id") == ob->query("id") )
    if(me->query("score") < -100)
       {            
         command("shake");
         command("say ���������ʣ��㶼��ʦ�Ÿ���Щʲô���������������ʦ����\n");
         command("expell "+ me->query("id"));
       }
}

 
void create()
{
        set_name("���ʦ̫", ({
                "miejue shitai",
                "miejue",
                "shitai",
        }));
        set("long",
                "����һλ����ʦ̫��\n"
        );
        set("gender", "Ů��");
        set("nickname","�����ɵ���������");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 30);
        set("int", 27);
        set("con", 20);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 120);
        set("combat_exp", 1500000);
        set("score", 100);
        set_skill("force", 200);
        set_skill("linji-zhuang", 180);
        set_skill("dodge", 200);
        set_skill("zhutian", 200);
        set_skill("tiangang-zhi", 180);
        set_skill("finger", 180);
        set_skill("jinding-mianzhang",160);
        set_skill("strike",180);
        set_skill("fuliu-jian",200);
        set_skill("sword",180);
        set_skill("yanxing-dao",150);
        set_skill("blade",150);
        set_skill("throwing",100);
        set_skill("pili-dan",150);
        set_skill("parry", 200);
        set_skill("mahayana", 150);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "fuliu-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("sword", "fuliu-jian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("throwing", "pili-dan"); 
        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-mianzhang");

        set("chat_chance",100);
        set("chat_msg", ({
                 (: heal :)
                        }) );

        create_family("������", 3, "����");
        setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

        set("inquiry",([
                 "������" : (: ask_ling :),
                 "����" : "�Ҿ��Ƕ�ü�ɵ����������ʦ̫ѽ������ô���Ҷ�����ʶ��",
                 "����" : "���������µ�һ�ɣ����ɴ�ʼ�˹�Ů�������ϱ���",
                 "���ʦ̫" : "�Ҿ������ʦ̫����",
                 "������" : "������������ͽ����ֻ��ϧ�������Ǹ�ħͷ������",
                 "���޼�" : "�������������ҵĺ�ͽ����",
                 "����" : "ħ�̵ĳ�����",
                 "��ɽ" : ( : ask_xiashan : ),
//                 "���콣" : ( : ask_jian : ),
                 ]));
}

int ask_xiashan()
{
  object me = this_player();
  if( (string)me->query("family/family_name") != "������" )
     {
      command("say ʩ���뱾������ԨԴ���������");
      command("? "+(string)me->query("id"));
      return 1; 
     }
  if( !(me->query("xiashan")))
     {
      say("���ʦ̫��Щ��ŭ�ˡ�\n");
      command("say ���Ѿ�ͬ���������ɽ�ˡ��㻹���ʸ�ʲô��");
      return 1;
     }      
/*  else if( me->query("age") < 15)
     { 
      command("pat "+(string)me->query("id"));
      command("say �����������ն񰡣����ǵ�����ʹ����ȥ�ɡ�");
      return 1;
     }      
*/   
  else if(!(me->query_temp("xia1")))
     {
      command("say �ðɣ�����ͽ�һ���߿ߣ����ܷ񴳳�����");
      me->set_temp("xia1",1);
      return 1; 
     }
  else if(me->query_temp("xia1") == 1 && !(me->query_temp("xia2")))
     {
      say("���ʦ̫��Щ��ŭ�ˡ�\n");
      command("say �㻹û�д����߿ߣ������ʸ�ʲô��");
      return 1;
     }  
  else if( me->query_temp("xia2") == 1)
     {
      command("smile");
      command("say �����Ƕ����ɵĺ�ͽ���������������ɽ�ˡ�");
      me->delete_temp("xia1");
      me->delete_temp("xia2");
      me->delete("xiashan");
      return 1; 
     }   
  
  else 
      return 0;
}              


int ask_ling()
{
   object me = this_player();
   object ob = this_object();
   object obj;    
   mapping my_fam;
   if(!(my_fam = me->query("family")) || my_fam["family_name"] != "������")
        {
            command("say ʩ���뱾������ԨԴ��Ҫ����������ã�\n");
            return 1;
        }
/*
   if( ( my_fam["generation"] == 6 && me->query("score") < 200 )
       || ( my_fam["generation"] == 5 && me->query("score") < 500 ) )
        {
            command("shake");
            command("say ���ʦ�ŵĹ��׻��������ӽ�Ŭ���ɡ�");
            return 1;
        }     
*/
   if ( my_fam["master_id"] == ob->query("id") )
        {
            command("? "+me->query("id"));
            command("say �������ҵ�ͽ���ˣ���Ҫ�����");
            return 1;
        }
   obj=new(__DIR__"obj/emling");
   obj->move(me);
   command("say �ðɣ�ƾ������Ժ�ʦ���ǱȻ��ˡ�\n");
   return 1; 
}

void heal()
{
        object ob = this_object();
        if(random(10)==1)
         { 
          switch(random(3)){
             case 0 : say("���ʦ̫ҧ���гݵ�˵����һ��Ҫɱ����������ˣ���\n");break;
             case 1 : say("���ʦ̫˵������������СѾͷҲ̫��֪�ô��ˡ���\n");break;
             case 2 : command("sigh");break;         
              }
          }
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                if(random(5)==1)
                {say(GRN"���ʦ̫ŭ��˵��������ô��ӣ���Ȼ�Ҵ����ң���\n"NOR);
                 say(RED"�������ʦ̫Ҫʹ��ȫ���ˣ�\n"NOR);
                 ob->set("jiali",150);
                } 
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                  command("exert regenerate");
                 return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        if (obj->query("id") == "jieshao-xin2"
        && ob->query_temp("have_letter") )
        {
                ob->set_temp("apprentice_ok",1);
                command("say �ã�" + ob->query("name") + "����Ը�����Ϊʦ��");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
        }
        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");
	string name, new_name;
	name = ob->query("name");
	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if ( ob_fam["generation"] == 0 )
	{
		command("say �����ӷ�ƶ������������ҵĵ����ˡ�");
		command("recruit " + ob->query("id"));
		return;
	}
	
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say ��" + ob_fam["master_name"] + "���������ҵİɣ������� !");
			command("say ƶ���ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");                     
                        if(ob->query("class") == "bonze" )
			{new_name = "��" + name[2..3];
			ob->set("name", new_name);
	                command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɾ��ֱ����� !");
                        }
                        else 
                        command("say ��ϲ������Ϊ�������Ĵ����� !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û�н����ţ�����Խ����ʦ��");
			return;
		}
	}
	return;
}
