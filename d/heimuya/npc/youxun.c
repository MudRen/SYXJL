#include "/quest/quest.h"
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��Ѷ", ({ "you xun", "xun",}));
        set("nickname", "��������");        
        set("long", 
"����ͷ����ͺ��һ�����룬�ʷ����֣�������
�⣬����ʮ�ֺͰ����ס�\n");
        set("title",GRN"�����������������"NOR);        
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);


       
        set_skill("tmzhang",80);
        set_skill("tmdao",80);        
        set_skill("pmshenfa",80);
         set_skill("tmdafa",80);

        map_skill("unarmed", "tmzhang");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("�������",3,"����");
        setup();
 carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}
