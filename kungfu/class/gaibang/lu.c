// sample master.c code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
       string ask_me();

void consider();

void create()
{
        set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
        set("title","ؤ��Ŵ�����");
        set("nickname", GRN "�ư���ͷ" NOR);
        set("gender", "����");
        set("age", 45);
        set("long",
                "³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
                "��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 120); // �����ڹ�
        set_skill("huntian-qigong", 120); // ��������
        set_skill("strike", 125); // �����Ʒ�
        set_skill("xianglong-zhang", 120); // ����ʮ����
        set_skill("dodge", 120); // ��������
        set_skill("xiaoyaoyou", 120); // ��ң��
        set_skill("parry", 120); // �����м�
        set_skill("staff", 115); // ��������
	set_skill("blade", 120);
	set_skill("liuhe-dao", 110);
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-dao");

        prepare_skill("strike", "xianglong-zhang");
        set("inquiry",
                ([
                        "�����ؼ�" : (: ask_me :),
                ]));
        set("book_count", 2);

        create_family("ؤ��", 18, "�Ŵ�����");
        setup();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="ؤ��")
        {
		command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");
                return;
        }
        if (ob->query("dai")<8)
        {
               	command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");
                return;
        }
        if ((int)ob->query("score")<800){
           command("sigh");
           command("say С�ֵ���ذ�!���ǲ�����һ���Ա��ﲻ��֮�˵�.");
           return;}
        if (ob->query("dai")== 8 )
        {
        if ( (int)ob->query("int") >= 25 ) {
                command("say ����ؤ�������һ���Ը���Ϊ����" +
                RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
                return;
        }
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
                command("recruit " + ob->query("id"));
                this_player()->set("title","ؤ��˴�����");
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α�������С�л��أ�");
        return;
}
string ask_me()
{
        mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "ؤ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
  if (this_player()->query("combat_exp")<5000)
             return RANK_D->query_respect(this_player()) +
            "����է���������ܸ�������ؼ���";
         if (this_player()->query("score")< 100)
             return "������է��������ô���ʲô.";
        if (query("book_count") < 1)
                return "�������ˣ������ġ������ؼ����ڴ˴���";
        add("book_count", -1);
        ob = new("/d/gaibang/obj/staff_book");
        ob->move(this_player());
        return "�ðɣ������ġ������ؼ����͸����û�ȥ�ú����С�";
}
 
