// hetaichong.c (kunlun)

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();

void create()
{
        set_name("��̫��", ({ "he taichong", "he" }));
        set("title", "����������");
        set("nickname", HIW"��������"NOR);
        set("long",
                "���������������š����ｭ��������������̫�塣\n"
                "��Ȼ����Ѵ󣬵���Ȼ���ó�������ʱӢ��������\n");
        set("gender", "����");
        set("unique", 1);
        set("age", 40);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1300);
        set("max_neili", 1300);
        set("jiali", 50);
        set("combat_exp", 700000);
        set("score", 40000);

        set_skill("literate", 100);
        set_skill("force", 120);
        set_skill("xuantian-wuji", 140);
        set_skill("dodge", 120);
        set_skill("kunlun-shenfa", 120);
        set_skill("strike", 140);
        set_skill("kunlun-zhang", 140);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("liangyi-jian", 130);
        set_skill("throwing", 100);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shenfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        prepare_skill("strike", "kunlun-zhang");

        create_family("������", 4, "������");
        set("class", "taoist");

        set("inquiry",
                ([
                        "�ķ�" : (: ask_me :),
                        "��ϰ֮" : (: ask_ding :),
                ]));

        set("book_count", 1);
        set("ding_count", 5);

        setup();
        carry_object("/d/kunlun/obj/sword")->wield();
        carry_object("/d/kunlun/obj/cloth")->wear();
}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="he taichong")
       {
         command("chat "+ob->query("name")+"! ��ɱ��Խ��������Ϊ�����������������㣬�ӽ��Ժ������Ϊ֪�ɡ�����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);        }
}               


void attempt_apprentice(object ob)
{
         if((int)ob->query("shen")<0){
         command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+
                                "��Ʒ��ʵ�����˻��ɡ�");
         command("say "+RANK_D->query_respect(ob)+
                                "�����Ȼ�ȥ�������°ɡ�");
         return;
         }

          if(ob->query("appren_hezudao", 1) == 1) {
         command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
         return;
         }

         command("say �ðɣ��ұ������㣬ֻ����Ͷ��������֮����ð���ѧ�ա�");
         command("recruit " + ob->query("id")); 
       ob->set("title","���������½�ʿ");
       ob->set("class","sworder");       }


string ask_me()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "������")
                                         return RANK_D->query_respect(this_player()) +
                                         "�뱾��������������֪�˻��Ӻ�̸��";
                  if (query("book_count") < 1)
                                         return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
                  add("book_count", -1);
                  ob = new("/d/kunlun/obj/force-book.c");
                  ob->move(this_player());
                  return "�������б����ڹ��ķ��������й����������ģ����û�ȥ�ú����С�";
}

string ask_ding()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "������")
                                         return RANK_D->query_respect(this_player()) +
                                         "�뱾��������������֪�˻��Ӻ�̸��";
                  if (query("ding_count") < 1)
                                         return "ɥ�Ŷ��Ѹ�������ȥ׷ɱ��ϰ֮���ˣ���Ͳ���ȥ�ˡ�";
                  add("ding_count", -1);
                  ob = new("/d/kunlun/obj/sangmending.c");
                  ob->move(this_player());
                  return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬��öɥ�Ŷ������ȥ�ɡ�";
}

