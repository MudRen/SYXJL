// jiading.c �Ҷ�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
        set_name("�Ҷ�", ({ "jia ding", "ding" }));
        set("title", "������������");
        set("long", "���Ǵ�������������ļҶ���\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 10000);
        set("score", 2000);
        set("env/wimpy", 5);

        set_skill("force", 25);
        set_skill("dodge", 25);
        set_skill("parry", 25);
        set_skill("sword", 25);
        set_skill("cuff", 25);
        set_skill("kurong-changong", 25);
        set_skill("duanjia-jian", 25);
        set_skill("tiannan-bufa", 25);
        set_skill("jinyu-quan", 25);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("sword", "duanjia-jian");
        map_skill("cuff", "jinyu-quan");
        map_skill("parry", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver",2 );
}
