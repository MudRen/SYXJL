#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
        set_name("����ʦ̫", ({
                "wenxu shitai",
                "wenxu",
                "shitai",
        }));
        set("long",
                "����һλ�����ʦ̫��\n"
        );
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("class", "bonze");
        set("inquiry",([
                "���"  : (: ask_for_join :),
                "����"  : (: ask_for_join :),
        ]));
        set("age", 28);
        set("shen_type", 1);
        set("str", 17);
        set("int", 20);
        set("con", 50);
        set("dex", 21);
        set("max_qi", 1000);

        set("max_jing", 500);

        set("neili", 1000);

        set("max_neili", 1000);

        set("jiali", 40);

        set("combat_exp", 60000);

        set("score", 100);

        set_skill("force", 60);

        set_skill("linji-zhuang", 60);

        set_skill("dodge", 70);

        set_skill("zhutian", 70);

        set_skill("jinding-mianzhang", 70);
        set_skill("strike", 70);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("fuliu-jian", 60);
       	set_skill("mahayana", 70);
        set_skill("literate", 60);
        map_skill("sword", "fuliu-jian");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("parry", "jinding-mianzhang");
        prepare_skill("sword", "fuliu-jian");
        create_family("������", 5, "����");
        setup();
          carry_object(__DIR__"obj/cloth")->wear();
          carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
        object me;
        me = this_player();
        if( me->query("family/master_id")=="wenxu shitai")
           if(me->query("shen")<=-100)
             {            
               command("shake");
               command("chat "+me->query("name")+"!����ɱ��Խ����������Ϊ���������������ʦ����\n");
               command("expell "+ me->query("id"));
               this_player()->set("title","������" + RED + "��ͽ" NOR);   
             }

        add_action("do_kneel", "kneel");
}
string ask_for_join()
{
        object me;
        me = this_player();
        if( (string)me->query("class")=="bonze" )
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶ�Ὺ�����Ц��\n";

        if(!undefinedp(me->query("marry/lover")))
                return "�����ӷ�ʩ����Եδ�ˣ����ǰ��˰ɡ�\n";
 
        if( (string)me->query("gender") != "Ů��" )
                return "�����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ���������ܽ䡣\n";
        me->set_temp("pending/join_bonze", 1);
        return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}
int do_kneel()
{
        object me = this_player();
        string *prename =
         ({ "԰", "��", "��", "��" });
        string name, new_name;
        if( !me->query_temp("pending/join_bonze") )
                return 0;
        message_vision(
                "$N˫�ֺ�ʮ�����������ع���������\n\n"
                "$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
                me, this_object() );
        name = me->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say �ӽ��Ժ���ķ�������" + new_name + "��");
        command("smile");
        me->delete_temp("pending/join_bonze");
        me->set("name", new_name);
        me->set("class", "bonze");
        me->set("K_record", me->query("PKS") + me->query("MKS"));
        me->set("shen_record", me->query("shen"));
        me->set("shen", 0);
        return 1;
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
        {
                command ("say �����ӷ�ʩ��ѽ��ƶ��ɲ��ҿ������Ц����");
                return;
        }
        if( ob->query("shen") < 0)
           {
            command("say �����ӷ𣡱��ɲ���Ϊ������֮ͽ��");  
            command("sigh");
            command("say �Ժ�������°ɣ��������ӷ�");                     
            return;
           }  
        if( (string)ob->query("class")!="bonze" )
        {  
                command("say �����ӷ�ƶ��������������׼ҵ��ӡ��ˡ�");
                command("say �Ժ�����ҵĻ�����˵һ���ɡ������ӷ�");              
        }
        command("say �����ӷ����գ����գ�");
        ob->set("xiashan",1);
        command("recruit " + ob->query("id"));
}
