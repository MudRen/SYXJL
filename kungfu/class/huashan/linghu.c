// linghu.c �����
//#include "/quest/quest.h"
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "ling huchong", "ling", "huchong" }));
        set("nickname", "��ʦ��");
        set("long", 
"�����Ľ��ݣ�����Ũü���ۣ������Ѱ�������\n"
"ͬ���������ϴ��ǻ�ɽ������һ���еĶ�����֡�\n"
"Ŀǰ����������Ⱥ���ڣ�������ִ���ճ����\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("per",28);
        set("con", 30);
        set("dex", 30);
        
        set("qi", 2800);
        set("max_qi", 2800);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 60);

        set("combat_exp", 800000);
        set("score", 100000);

        set_skill("blade", 200);
        set_skill("cuff", 200);
        set_skill("strike",200);
        set_skill("force", 170);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("dugu-jiujian",300);
        set_skill("zixia-shengong", 170);
        set_skill("poyu-quan", 200);
        set_skill("fanliangyi-dao", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("huashan-jianfa", 200);
        set_skill("huashan-shenfa",200);
        set_skill("literate", 80);

        map_skill("force", "zixia-shengong");
        map_skill("cuff", "poyu-quan");
        map_skill("blade", "fanliangyi-dao");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "dugu-jiujian");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��", 14, "����");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.poqi" :),
                (: exert_function, "recover" :),
        }) );

        set("inquiry", ([
                "������" : "�����Ѿ��ܾ�û�м��������˼��ˡ���������\n",
                "��ӯӯ" : "������������Ϣ��˵�գ���������鼤��,�����۾����ģ�\n",
        ]));
        setup();

        carry_object("/d/heimuya/npc/obj/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
//        carry_object("/d/heimuya/npc/obj/card2")->wear()
}
/*

void init()
{
        object ob;
        ob = this_player();     
         ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("���ղ��ܼ���ӯӯ��!" + RANK_D->query_respect(ob)
          +"�������������Ϣ?\n");
}

int accept_object(object who, object ob)
{
        object obn;

        if( !who || environment(who) != environment() )
                return 0;
        if( !objectp(ob) )
                return 0;
        if( !present(ob, who) )
                return notify_fail("��û�����������\n");

        if( (string)ob->query("name") != "��")
                return notify_fail("����岻��Ҫ���������\n");
    say( "�����˫��������ӯӯ���ţ���������, ���׻�����������ȥ����ӯӯ,�������Ҿ�ȥ����!" );
        obn = new("/d/heimuya/npc/obj/card2");
        obn->set_amount(1);
        obn->move(who);
        destruct(ob);
    set_temp("card2",0);
    return 1;
}
*/

void init()
{

        object ob;
        ::init();
        ob = this_player();
            if((int)ob->query("shen")<=-1000&&ob->query("family/master_id")=="ling huchong")
        {
                  command("chat "+ob->query("name")+"!����ɱ��Խ����������Ϊ���������������ʦ����\n");
                  command("expell "+ ob->query("id"));
                    this_player()->set("title","��ɽ��" + RED + "��ͽ" NOR);   
        }
{
          add_action("do_kill", "kill");
          add_action("do_kill", "hit");
          add_action("do_kill", "fight");
}
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

        if ((int)ob->query_int() < 25) {
                command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�һ�ɽ���书��");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");

        return;
}
void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

          if (arg == "ling huchong" || arg == "ling")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

