#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void consider();

void create()
{
        set_name("������", ({ "ren woxing", "ren",}));
        set("long", 
"����˫Ŀ������˸��ͷ����ü�������֮ɫ��һ��ɨ������ŭ������
Ŀ��������¶���װ԰Ե����ƣ����Ǹ�ƽ�����\n");
        set("title",HIB"����������ν���"NOR);         
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 1600);
        set("max_jing", 300);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 120);
        set("combat_exp", 2000000);
        set("shen", -200000);


          set_skill("sword", 300);
            set_skill("tmdafa",240);
          set_skill("parry", 300);
        set_skill("literate",200);
          set_skill("dodge", 300);
          set_skill("unarmed", 300);
          set_skill("whip", 250);
          set_skill("force", 300);
         set_skill("tmzhang", 300);
        set_skill("staff", 160);
         set_skill("tmjian", 290);
         set_skill("tmdao", 300);
        set_skill("rybian",200);
         set_skill("pmshenfa", 300);
        set_skill("wuchang-zhang",100);
         set_skill("xixing-dafa", 290);
          set_skill("strike",300);
         set_skill("blade", 300);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "xixing-dafa");
        map_skill("whip", "rybian");
       create_family("�������",1,"����");
 set("inquiry", ([
                "���Ǵ�": (: ask_me :),
                "��ӯӯ" : "���ѵ�֪����������\n",
                "������" : "�Ҿ������𽭺���������̽�������Ͱ���Ϊʦ�ɡ�\n",
                "�������" : "�ǵģ������������̰ɣ���������书��û���ܵС�\n",
                ]));
        set("book_count", 1);

            set("no_get",1);
        setup();
}
void attempt_apprentice(object ob)
{
         if (ob->query_int() < 30) {
              command("say " + RANK_D->query_respect(ob) +
                        "�߿��߿����Ҳ����ɵ��˵����");
                return;
        }
         if (ob->query_dex() < 25) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
        if ((int)ob->query("shen") > -10000) {
                command("say " + RANK_D->query_respect(ob) +
                        "�㻹�����ĺ��������һ��������㡣");
                return;
        }
        command("say ������ ���Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","��������ν����״�����");
}


int accept_fight(object me)
{
        command("say ������䣿�㹻�ʸ���");
        command("say ��Ȼ��λ" + RANK_D->query_respect(me) + "Ҫ����Ļ�����Ī����ɱ���ˣ�"); 
        command("say �������Ĵ�.......");
        command("chat ��������ɳ������κε�ͷ�ѳ���...������һ�����������ˣ�");

        kill_ob(me);
        return 1;        
}

string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����Ǵ��ܼ������Ҵ���";
        add("book_count", -1);
        ob = new(__DIR__"obj/xxdafa");
        ob->move(this_player());
        return HIY"����ȥ�ɣ���������ħ����������¡�"NOR;
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if( ( (int)ob->query("shen") >= 0 || (int)ob->query("score") < 0 ) && ob->query("family/master_id")=="ren woxing" )
        {
                      command("chat "+ob->query("name")+"!��ľ�²�Ҫ����û�õĶ�����\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","�������" + RED + "��ͽ" NOR);   
        }

}

