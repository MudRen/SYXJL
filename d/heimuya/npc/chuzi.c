inherit NPC;

string ask_me();

void create()
{
        set_name("��ʦ", ({ "chu zi", "chu" }));
        set("title", "�������");
        set("long", 
                "������̵�һ�����ӣ�Ц���еؿ����㣬�����ܺ��Ƶ����ӡ�\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 200);
        set("max_jing", 50);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 500);
        set("shen",0);
        set("score", 0);

        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("cuff", 10);
        set_skill("parry", 10);

        create_family("�������", 3, "����");
        set("inquiry", ([
                "����" : (: ask_me :),
        ]));

        setup();
        
}

string ask_me()
{
       object me=this_player();
       
       me->set("food", (int)me->max_food_capacity());
       me->set("water", (int)me->max_water_capacity());
  
        return "�����ԣ���ҭס�ˡ�";
}
