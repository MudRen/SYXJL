#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ͤ", ({ "yang lianting", "yang",}));
        set("long", 
"�������ο��࣬�������룬��ò��Ϊ�۽�
���䣬�������鸡�����������ڹ���\n");
        set("title",HIW"��������ܹ�"NOR);        
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 22);
        set("con", 21);
        set("dex", 19);
        
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 80000);
        set("shen", -1000);


       
        set_skill("tmzhang",50);
        set_skill("pmshenfa",50);
         set_skill("tmdafa",50);

        map_skill("unarmed", "tmzhang");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("�������",3,"����");
        setup();
}
