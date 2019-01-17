///ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
                   +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
                   +"����ң�������ͷɢ����\n");
        set("title", "�϶���");
        set("gender", "����");
        set("age", 53);
        set("nickname", HIR "����" NOR);
        set("shen_type",-1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 900);
        set("max_jing", 900);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);

        set("combat_exp", 1500000);
        set("score", 200000);

        set_skill("force", 300);
        set_skill("training", 300);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hand",300);
        set_skill("finger",300);        
        set_skill("poison",300);        
        set_skill("staff", 300);
        set_skill("hamagong", 300);
        set_skill("chanchu-bufa", 300);
        set_skill("shedu-qiqiao",300);        
        set_skill("shexing-diaoshou", 300);
        set_skill("lingshe-zhangfa", 300);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("hand", "shexing-diaoshou");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("staff", "lingshe-zhangfa");
         map_skill("poison", "shedu-qiqiao");        

        create_family("����ɽ��",1, "��ɽ��ʦ");
        set("chat_chance",2);
        set("chat_msg",({
         "ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
         "ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
         "ŷ������������ն����������ģ�\n",
        }));
            set("no_get",1);
        setup();
         carry_object("/d/baituo/obj/shezhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",50);
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
         if((int)ob->query("shen")>=0&&ob->query("family/master_id")=="ouyang feng")
        {
                    command("chat "+ob->query("name")+"!���Ĵ�������������а�ɵ��ӣ����ҹ�����\n");
                  command("expell "+ ob->query("id"));
                    this_player()->set("title","����ɽ��" + RED + "��ͽ" NOR);   
        }

}     

void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("ŷ�����$NЦ������ľ���̫����,�һ��������㣡\n",ob);
        return ;
         }
   message_vision("ŷ��������$N��ͷ��΢΢���˵�ͷ��\n",ob);
   command("recruit " + ob->query("id"));
   return;
}
