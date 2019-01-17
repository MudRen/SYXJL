
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "dao fengleng","dao", "fengleng" }));
        set("nickname", HIW "����Ц" NOR);
	set("long", 
		"������ɱ��¥��¥�������Ǹ�ɱ����ɲ�����\n"
		"����ֵ׳�꣬����ݳ�����Ĭ���ԡ�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);
	set("combat_exp", 7000000);
	set("score", 300000);

	set_skill("force", 300);
        set_skill("wuji-shengong", 300);
	set_skill("dodge", 300);
	set_skill("bugui-bufa", 300);
	set_skill("strike", 300);
	set_skill("fanyun-zhang", 300);
	set_skill("parry",300);
        set_skill("unarmed",300);
	set_skill("blade", 300);
        set_skill("qishen-dao", 300);
	set_skill("literate", 300);
 
        map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("strike", "fanyun-zhang");
        map_skill("parry", "qishen-dao");
        map_skill("blade", "qishen-dao");

	create_family("ɱ��¥", 1, "¥��");
	set("book_count", 1);

          set("chat_chance_combat", 75);
           set("chat_msg_combat", ({
                  (: perform_action, "blade.shaqi" :),
		(: perform_action, "strike.yunkai" :),     
		(: exert_function, "recover" :),
	}) );
            set("no_get",1);
	setup();
	carry_object("/d/shashou/obj/wuqing")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("combat_exp") < 100000) {
		command("say ɱ���������Դ������ӵ��£����Խ�������һ��Ҫ�ḻ��");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "shashou")
		ob->set("class", "shashou");

}

