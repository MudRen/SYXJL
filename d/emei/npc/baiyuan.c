inherit NPC;



int ask_bangzhu();



void create()

{

        set_name("��Գ", ({

                "baiyuan",

                "yuan",

          }));

        set("long",

                "����һͷ��Գ��\n"

        );

        set("gender", "����");

        set("attitude", "friendly");

        set("age", 24);

        set("shen_type", 1);

        set("str", 21);

        set("int", 25);

        set("con", 20);

        set("dex", 25);

        set("max_qi", 500);

        set("max_jing", 200);

        set("neili", 400);

        set("max_neili", 400);

        set("jiali", 40);

        set("combat_exp", 10000);

        set("score", 100);

        set_skill("force", 60);

        set_skill("linji-zhuang", 60);

        set_skill("dodge", 70);

        set_skill("zhutian", 70);

        set_skill("tiangang-zhi", 70);

        set_skill("finger", 70);

        set_skill("parry", 60);

        set_skill("mahayana", 70);

        set_skill("literate", 60);

        map_skill("force", "linji-zhuang");

        map_skill("dodge", "zhutian");

        map_skill("finger", "tiangang-zhi");

        map_skill("parry", "tiangang-zhi");

        prepare_skill("finger", "tiangang-zhi");

        set("chat_chance",5);

        set("chat_msg", ({

             "��Գ�����ε��۹⿴���㡣\n",

             "��Գ����ץ��������\n",

             "��Գ��������·����ڴ�����İ�����\n",

                        }) );

        set("inquiry",([

              "����" : ( : ask_bangzhu : ),

                ]));



        setup();

}

   

int ask_bangzhu()

{

 object me = this_player();

 me->set_temp("tui",1);

 say("��Գ��Ȼ����˵����������������ԡ�\n");

 say("��Գָ��һ���ʯͷ���\n");

 say("��Գ�������ƣ�tui�����ʯͷ��\n");

 return 1;

}