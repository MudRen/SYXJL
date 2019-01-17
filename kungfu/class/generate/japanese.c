// japanese.c �ձ�����

inherit CHALLENGER;

void create()
{
        NPC_D->generate_jp_name(this_object());
	set("long", "�ձ����ӡ�\n");
	set("gender", "����");
	set("age", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

        // the follow 5 setting has no use
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 100);

	set("combat_exp", 3000000);
        set("scale", 135);

	set_skill("force", 1);
        set_skill("fushang-neigong", 1);
	set_skill("dodge", 1);
        set_skill("renshu", 1);
	set_skill("parry", 1);
        set_skill("dongyang-dao", 1);
        set_skill("blade", 1);

        map_skill("blade", "dongyang-dao");

        set("rank_info/rude", "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

	setup();

       carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/jpn-dao")->wield();
}

string challenge()
{
        set("opinion/msg", ({
                (random(2) ? "�������Զ����ɣ����˵����Ķ��󵶷�������졣"
                           : "�����ɣԶ�ڶ���֮�⣬�������ʿ�ó�ʹ��խ�г�����"),
                (random(2) ? "�ǰ�����������Ҳ�ǹ��صúܡ�"
                           : "û�����������������أ����������������������"),
                (random(2) ? "�ߣ���������������ţ�ʵΪϰ���ߴ�ɣ�"
                           : "���˿�ν��Ŀ��⣬��֪������һ˿Ҳ�����ã�"),
        }));

        command(random(2) ? "haha" : "heng");
        switch (random(3))
        {
        case 0:
                return "�ң������ʿ" + name() + "������������ԭ"
                        "������ս��˭�ҳ���ӭս��";

        case 1:
                return "�Ҿ��Ƕ����ɣ����" + name() + "��������"
                        "ԭ��û�������ҵĶ��֣�";

        default:
                return "��" + name() + "��������ʿ����������ս"
                        "�����ֵľ͸��ҹ�������";
        }
}

void unconcious()
{
        command("chat �˸�ѽ·��");
        die();
}

void competition_with(object ob)
{
        ::competition_with(ob);
        command("say �˸�ѽ·������ȥ�ɣ�\n");
        kill_ob(ob);
}
