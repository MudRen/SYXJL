// Date: CSY 98/08/14

inherit NPC;

string ask_for_huansu();
void create()
{
        set_name("����ɮ", ({
                "huansu seng",
                "huansu",
                "seng",
        }));
        set("long",
                "����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
                "�������������һϮ�ײ��ڱ����ģ��ƺ������գ�����������������׵��¡�\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 30);
        set("shen_type", 1);
        set("str", 23);
        set("int", 21);
        set("con", 18);
        set("dex", 22);
        set("max_qi", 350);
        set("max_jing", 200);
        set("neili", 350);
        set("max_neili", 350);
        set("jiali", 30);
        set("combat_exp", 5000);
        set("score", 100); 

        set("inquiry", ([
        "����" : (: ask_for_huansu :),
        ]) );

        set_skill("force", 30);
        set_skill("hunyuan-yiqi", 30);
        set_skill("dodge", 30);
        set_skill("shaolin-shenfa", 30);
        set_skill("claw", 35);
        set_skill("longzhua-gong", 35);
        set_skill("parry", 30);
        set_skill("buddhism", 30);
        set_skill("literate", 30);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "longzhua-gong");

        prepare_skill("claw", "longzhua-gong");

        create_family("������", 40, "����");

        setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
} 
void init()
{
        add_action("do_huansu", "huansu");
}

string ask_for_huansu()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "������")) 
        return ("�������û��ԨԴ��ƶɮ���Ҹ��㻹�ס�\n");
    if( (string)me->query("class")!="bonze" )
        return "�����ӷ𣡳����˲���ڿ����Ѿ����׼����ˡ�\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say �����ӷ����գ����գ�һ����������ٲ�����");
        command ("say ����"+RANK_D->query_respect(me)+"��˼�����Ѿ������������ۻ���(huansu)�����ܳͷ���"); 
        return "��Ȼ�����"+RANK_D->query_respect(me)+"��Ը���׵Ļ������밲���ڴ������ɡ�\n";
}

int do_huansu()
{ 
   if(this_player()->query_temp("pending/leave_bonze")) 
     return 0;
     message_vision("$N���������Ը�⡣\n\n", this_player());
     command("say �������������Ե�������ɽȥ�ɣ�\n");
     this_player()->set("combat_exp", this_player()->query("combat_exp")*90/100);
     this_player()->delete("class");
     this_player()->delete_skill("hunyuan-yiqi");
     this_player()->delete("family");
     this_player()->set("title", "��ͨ����");
     command("say �ӽ�����������������޹ϸ�");
     command("sigh");
     this_player()->delete_temp("pending/leave_bonze");
     command("say �����粨���ƶ����Σ�ʩ������Ϊ֮������\n");
     this_player()->save();
     return 1;
}

