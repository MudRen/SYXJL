#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�Ϲ���", ({ "shang guanyun", "shang",}));
        set("nickname", "����");        
        set("long", 
"ֻ�������ֳ��ţ�˫Ŀ������ã��������ơ�\n");
        set("title",GRN"���������������"NOR);        
        set("gender", "����");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 1000000);
        set("score", 50);


        set_skill("unarmed", 160);
        set_skill("force",160);
        set_skill("literate", 160);
        set_skill("blade", 160);
        set_skill("dodge", 160);
        set_skill("strike", 160);
        set_skill("tmzhang",160);
        set_skill("sword", 160);
        set_skill("tmjian",160);
        set_skill("tmdao",160);        
         set_skill("pmshenfa",160);
         set_skill("tmdafa",160);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("�������", 3, "����");
            set("no_get",1);
        setup();
 carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}

void attempt_apprentice(object ob)
{
                command("say �Ϸ��������ͽ�ܣ�"+RANK_D->query_respect(ob)+
                                  "���ǻ�ȥ�ɡ�");
 }

