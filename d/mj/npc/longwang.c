// longwang.c ��ɼ����
#include <ansi.h>
inherit NPC;

object ob = this_object();
void create()
{
        set_name("���˿",({"dai qisi","dai","longwang"}));
        set("title","���̻��̷���");
        set("long", 
                "���������̵��Ĵ󻤽̷����Ĵ��㡣\n"
                "��һ������ɫ��ȹ���ɶ����ˣ���˿�����������������Ȼ�˵����꣬��Ȼ��ζ�̴档\n");
        set("age", 43);
        set("nickname",MAG"��ɼ����"NOR);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 32);
        set("con", 20);
        set("dex", 30);
        set("per", 24);
        
        set("max_qi",2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 60);
        set("combat_exp", 1300000);
    

        set_skill("sword",160);
        set_skill("dodge",180);
        set_skill("unarmed",160); 
        set_skill("literate",160);
        set_skill("force",160);
        set_skill("shenghuo-shengong",160);
        set_skill("qingyunwu", 160);
        set_skill("liehuo-jian",160);
        set_skill("blade",160);
        set_skill("shenghuo-quan",160);  

        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        map_skill("unarmed","shenghuo-quan");

        create_family("����",34,"����");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        
}

