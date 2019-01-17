#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
    set("attitude", "peaceful");
        
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
    set("inquiry", ([
        "����"     : "���ֱ����Ů���Ĺ����� \n",
        "�����澭" : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
    ]));

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 100);
        
    set("combat_exp", 1500000);
    set("score", 0);
         
    set_skill("force", 300);             // �����ڹ�
    set_skill("bibo-shengong", 300);     // �̲���

//    set_skill("claw", 220);              // ����צ��

    set_skill("finger", 180);            // ����ָ��
      set_skill("tanzhi-shentong", 260);   // ��ָ��ͨ
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("luoying-zhang", 260);     // ��Ӣ����
    set_skill("hand", 230);              // �����ַ�
    set_skill("cuixin-zhang", 260);      // ������
    set_skill("xuanfeng-tui", 260);      // ����ɨҶ��
    set_skill("lanhua-shou", 230);       // ������Ѩ��
    set_skill("dodge", 250);             // ��������
  set_skill("anying-fuxiang", 250);    // ��Ӱ����
    set_skill("parry", 280);             // �����м�
    set_skill("strike", 260);            // �����Ʒ�
    set_skill("sword", 250);             // ��������
    set_skill("luoying-shenjian", 250);  // ��Ӣ��
    set_skill("qimen-wuxing",250);       // ��������
    set_skill("literate",150);           // ����ʶ��
        
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("strike", "cuixin-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "luoying-shenjian");
    map_skill("sword"  , "luoying-shenjian");
        
    create_family("�һ���", 1, "����");
    setup();
        
    this_player()->carry_object(__DIR__"obj/yuxiao")->wield();
    this_player()->carry_object(__DIR__"obj/bupao")->wear();
    this_player()->carry_object(__DIR__"obj/jiuyin2");
    
}

void init()
{
       object ob;

       ::init();

       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        ob = this_player();
        if((int)ob->query("score") < 0 &&ob->query("family/master_id")=="huang yaoshi")
        {
                    command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","�һ���" + RED + "��ͽ" NOR);   
        }

       }
}


void attempt_apprentice(object ob)
{
        string name,new_name; 
        if (ob->query_int() < 30) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�");
                return;
    }
    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
}
    if ((int)ob->query("score") < 500 ) {
        command("say ��Ա��ŵĹ��׻�����,����Ŭ��ѽ!");
                return;
 
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say ���һ��������������������������ֳ�������򽻵�������ذɣ�");
                return;
        }
    command("say �ܺã��ܺá�");
    name = ob->query("name");
    new_name = name[0..3] + "��";
    ob->set("name", new_name);
    command("say �ӽ��Ժ������ֽ���" + new_name + "!");    
    command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        if (mapp(ob->query("family"))) {
                myfam = (mapping)ob->query("family");
                if ( myfam["family_name"] == "�һ���") return 1;
        }
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("��ҩʦ���˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0; 
        ob->add_temp("tmark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        
        if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
                if (!(int)who->query_temp("tmark/��")) who->set_temp("tmark/��", 0);
                message_vision("��ҩʦ���˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�澭�ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
                who->add_temp("tmark/��", 240);
                return 1;
        }
        return 0;
}





void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "huang yaoshi" || arg == "huang")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}

