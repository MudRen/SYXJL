#include "/quest/quest.h"
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("�ڰ���", ({ "heibai zi","zi" }) );
        set("title", "�ͷ�ʹ");
        set("gender", "����" );
        set("age", 56);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
"ֻ������Ȼ���������۶��룬��ò��� ��\n");

        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("max_neili", 1000);  
        set("neili", 1000);             
        set("jiali", 70);

         set_skill("cuff", 100);
         set_skill("strike",100);
         set_skill("force", 100);
         set_skill("dodge", 100);
         set_skill("parry", 100);
         set_skill("sword", 100);
         set_skill("literate",100);
         set_skill("unarmed",100);
         set_skill("wushuang-jian",100);
         set_skill("fanyun-zhang",100);
        set_skill("bugui-bufa",100);
         set_skill("wuji-shengong",100);

         map_skill("force","wuji-shengong");
         map_skill("strike","fanyun-zhang");
         map_skill("sword","wushuang-jian");
         map_skill("dodge","bugui-bufa");
         create_family("ɱ��¥", 3, "����");
      
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        }
