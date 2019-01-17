// xiaoyaozi.c ��ң��
// shilling 97.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��ң��", ({ "xiaoyao zi", "xiaoyao","zi" }));
       set("title", "��ң�ɿ�ɽ��ʦ");
       set("long", 
               "��������ң�ɿ�ɽ��ʦ��������Ϊ��ң������һ���ڽ�����\n"
               "�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
               "����ȴ�ǡ���������������Ѯ��������⣬��ü�԰ס�\n");
       set("gender", "����");
       set("age", 75);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 40);
       
       set("max_qi", 5500);
       set("max_jing", 3000);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jingli", 2000);
       set("max_jingli", 2000);
       set("jiali", 100);
       set("combat_exp", 10000000);
       set("score", 200000);

       set_skill("force", 200);
         set_skill("sword", 200);
         set_skill("strike", 200);
       set_skill("beiming-shengong", 200);
       set_skill("dodge", 200);
       set_skill("lingboweibu", 200);
       set_skill("unarmed", 200);
       set_skill("liuyang-zhang", 180);
       set_skill("parry", 200);
       set_skill("blade", 200);
       set_skill("ruyi-dao", 180);
       set_skill("zhemei-shou", 200);
         set_skill("chixin-qingchang-jian", 200);
     set_skill("hand", 200);
       set_skill("literate", 120);

       map_skill("force", "beiming-shengong");
       map_skill("dodge", "lingboweibu");
       map_skill("unarmed", "zhemei-shou");
         map_skill("sword", "chixin-qingchang-jian");
     map_skill("strike", "liuyang-zhang");
       map_skill("parry", "ruyi-dao");
       map_skill("blade", "ruyi-dao");

//     prepare_skill("hand","zhemei-shou");
//     prepare_skill("strike","liuyang-zhang");

       create_family("��ң��", 1, "��ɽ��ʦ");
       set("class", "taoist");

       setup();
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query_skill("beiming-shengong", 1) < 80) {
               command("say ����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���"); 
               command("say " + RANK_D->query_respect(ob) + 
                       "�ı�ڤ���Ƿ�Ӧ��������߰���");
               return;
       }

       if (ob->query_int() < 35) {
               command("say ����ң���书�����ӡ���ң�����֡�");
               command("say ����ν����ң������ֻ�ܿ����Լ�ȥ����");
               command("say ����" + RANK_D->query_respect(ob) + "�������ƺ����д���߰���");
               return;
       }
       command("smile");
       command("say �벻���������Ͼ�Ȼ�����˿��Լ̳��ҵ���ң�ķ���");
       command("recruit " + ob->query("id"));
       ob->set("title","��ң�ɻ���ʹ��");
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score") < 0 &&ob->query("family/master_id")=="xiaoyao zi")
        {
                      command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","��ң��" + RED + "��ͽ" NOR);   
        }
{
          add_action("do_kill", "kill");
          add_action("do_kill", "hit");
          add_action("do_kill", "fight");
}
}
void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

          if (arg == "xiaoyao zi" || arg == "zi")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}


