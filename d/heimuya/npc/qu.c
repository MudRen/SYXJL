#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("����", ({ "qu yang", "qu",}));
        set("long", 
"�������������ʮ����֮һ���书��ɲ⡣
����������������֮�������տ��ԳƵ����ǵ�����һ��.\n
");
        set("title",HIM"������̳���"NOR);         
       set("gender", "����");
        set("age", 60);
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


       
        set_skill("tmzhang",100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("�������",3,"����");

        set("inquiry", ([
                "Ц��������" : (: ask_me :),
        ]));
set("book_count", 1);
        setup();
 carry_object(__DIR__"obj/bi")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        

}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "Ц������������֪���ˣ�������һ���ˡ�";
        add("book_count", -1);
        ob = new(__DIR__"obj/xo");
        ob->move(this_player());
        return "���������ͣ��������ˣ��ⱾЦ�����������͸���ɣ�
       ֻ�����Ǹ�������֪���ˡ�";
}