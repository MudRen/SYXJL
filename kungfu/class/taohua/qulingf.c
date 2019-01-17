#include <ansi.h>
#include "/quest/quest.h"
inherit NPC;

void create()
{
        set_name("�����", ({ "quling feng", "feng", "quling" }) );

        set("nickname",  RED "�����" NOR);
        set("gender", "����");
        set("age", 40);
        set("long",
            "���ǻ�ҩʦ���ĵ��ӣ����һ����Ĵ����\n"
            "���¡�÷������½���е�����磬���\n"
            "��ҩʦ�谮��������ã�����Ҳ��ߣ�\n"
            "�����黭�������ܡ�����������ʮ���꣬\n"
            "��ò������������� �е���ġ�\n" 
        );
        set("attitude", "peaceful");

        set("str", 20);
        set("con", 20);
        set("int", 20);
        set("dex", 20);
        set("per", 28);

        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("max_qi", 2000);
        set("max_jing", 1000);

        set("combat_exp", 500000);
        set("score", 20000);
        


        set_skill("force", 110);
        set_skill("bibo-shengong", 110);
        set_skill("dodge", 110);
        set_skill("anying-fuxiang", 110);
        set_skill("strike", 100);
        set_skill("luoying-zhang",110);
        set_skill("parry", 110);
        set_skill("sword", 100);
        set_skill("luoying-shenjian", 100);
        set_skill("literate", 50);
        set_skill("qimen-wuxing", 100);

        map_skill("force", "bibo-shengong");
        map_skill("dodge", "anying-fuxiang");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");
        
        prepare_skill("strike", "luoying-zhang");

        create_family("�һ���", 2, "�����");
        

        setup();
        carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();
}




