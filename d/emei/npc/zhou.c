// zhou.c ������

#include <command.h>
#include <ansi.h>

int do_teach();
inherit NPC;
void create()
{
        set_name("������", ({ "zhou zhiruo","zhiruo","zhou"}));
        set("long",
                "���Ƕ����ɵĵ��Ĵ����ŵ��ӡ�\n"
                "һ�����������ס�����һ�������ѡ�\n"
                "�����������Ц�д���Щ�����Ρ�\n"
                "���ܼ�į��\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "���"    : "������ȣ����԰ɡ�",
                "����"    : "Ҫ�������ҵ�ʦ����ȥ��",
                "����"    : "���ġ�����Ҳ���ң�",
                "���޼�"  : "������Ķ����ļһ����Ҳ��Ҫ������",
                "����"    : "��Ҫ���������ӣ�",
                "ָ���书" : (: do_teach :),                
        ]));
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 70);
        set("combat_exp", 400000);
        set("score", 100);
        set("max_jingli", 1000);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        set_skill("throwing",100);
        set_skill("sword",100);
        set_skill("fuliu-jian",100);
        set_skill("pili-dan",100);
        map_skill("throwing","pili-dan");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "tiangang-zhi");
        prepare_skill("finger", "tiangang-zhi");
 
        create_family("������", 4, "���ŵ���");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
int do_teach()
{
        object ob;
        ob=this_player();
        if(ob->query("jiuyin") ==1)
        {
                say("������˵�������Ҳ����Ѿ�ָ��������𣿡�\n");
                return 1;
        }
        
        if(ob->query("gender")!="Ů��")
        {
                say("������˵��������ʲô������͵�������ݣ����������ޣ���\n");
                command("heng");
                return 1;
        }
        if((int)ob->query_skill("jiuyin-baiguzhao", 1) < 100)
        {
        say("������˵������ľ����׹�צ��������죬��ָ�㲻����ʲô��\n");
        return 1;
	}
	say("������˵������Ҳûʲô�ý���ģ��͸��㽲��һ�¾����׹�צ�ɡ�\n");
	say("�������������Ľ��⣬ѧ���ˡ�����һ�����͡�ʩ���󷨡���\n");
        this_player()->set("jiuyin",1);
        return 1;
}
