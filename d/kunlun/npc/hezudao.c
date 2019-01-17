// hezudao.c (kunlun)

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "he zudao", "he" }));
        set("title", "�����ɿ�ɽ��ʦ");
        set("nickname", HIB"������ʥ"NOR);
        set("long",
                "�����������ɿ�ɽ��ʦ���ų��ٽ��������ġ�������ʥ����\n"
                "������Ŀ���ݹ����⣬ԼĪ��ʮ��������͡�\n");
        set("gender", "����");
        set("unique", 1);
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 27);
        set("int", 40);
        set("con", 40);
        set("dex", 28);

        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("eff_jingli", 2000);
        set("jingli", 2000);
        set("combat_exp", 2000000);
        set("score", 400000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                 (: perform_action, "sword.yixing" :)
        }));

        set_skill("art", 200);
        set_skill("literate", 180);
        set_skill("force", 300);
        set_skill("xuantian-wuji", 300);
        set_skill("dodge", 250);
        set_skill("kunlun-shenfa", 250);
        set_skill("strike", 280);
        set_skill("kunlun-zhang", 280);
        set_skill("parry", 280);
        set_skill("sword", 320);
        set_skill("liangyi-jian", 320);
        set_skill("throwing", 230);
        set_skill("art", 200);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shenfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
        prepare_skill("strike", "kunlun-zhang");

        create_family("������", 1, "��ɽ��ʦ");
//      set("class", "taoist");
        setup();
       carry_object("/d/kunlun/obj/jwqin.c")->wield();
        carry_object("/d/kunlun/obj/w-cloth.c")->wear();
}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="he zudao")
       {
         command("chat "+ob->query("name")+"! ��ɱ��Խ��������Ϊ�����������������㣬�ӽ��Ժ������Ϊ֪�ɡ�����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);        }
}               

void attempt_apprentice(object ob)
{
                mapping skill;
                string *skl;
                int i;



                if(ob->query("kar") < 20){
                command("shake");
                return;
                }

                if(ob->query_int() < 32 ) {
                command("say ����������Ҫ���Լ��ߵ��˲ſ������������У��������书�������ۡ�");
                command("say "+RANK_D->query_respect(ob)+"�����Ȼ�ȥ�������ɡ�");
                return;
        }
                if ((int)ob->query_skill("xuantian-wuji", 1) < 85) {

                command("say �����黭��ΪС������Ҳ�������������С�");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����������޼����϶��µ㹦��");
                return;
        }

                if ((int)ob->query("max_neili", 1) < 500) {
                command("say ����������һ�Ķ����������߻���ħ��");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���Ⱥú�����������");
                return;
        }

                skill = ob->query_skills();
                skl = keys(skill);
                i = sizeof(skl);
                while (i--) {
                if (skill[skl[i]] < 80){
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ���" + 
                        CHINESE_D->chinese(skl[i]) + 
                        "�϶���Щ����");
                return;
                }
        }
                
                command("recruit "+ob->query("id"));
                ob->set("title","��������ʥ�մ�����");
                ob->set("class","sworder");        
                if(!ob->query("appren_hezudao"))
                {
                        ob->set("appren_hezudao", 1);
                        command("say ������Ҳ���������ˣ��Ҿͽ���һЩ�ٽ����֪ʶ�ɡ�");                
                        ob->set_skill("art", ob->query_skill("literate"));
                        ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
                }
}

