// nigu2.c

inherit NPC;

void create()
{
	set_name("���",({ "nigu" }) );
        set("gender", "Ů��" ); 
        set("class","bonze");
        set("age", 20);
        set("long", "���Ǹ��ѳ��ҵ���ã�����ȥ���ǻ��书�����ӡ�\n");
        set("str", 18);
        set("dex", 20);
        set("con", 20);
        set("int", 17);
	set("shen_type", 1);         
        set("max_qi",300);
        set("qi",300);     
        set("combat_exp", 2000);     
        set_skill("unarmed",30);
        set_skill("dodge",30);  
        set("attitude", "peaceful");
        create_family("������",7,"����");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

