#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ʹ��", ({ "shi zhe", "zhe",}));
        set("long", 
"����ͷ�����ź�ɫͷ�֣�����������
��ò�����ɽ������ֵ��̳����ĸ���
�������Ž�̳��������\n");
        set("title",HIW"������̻���"NOR);        
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 1000);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
set("combat_exp", 10000);

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
        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
                 "����ʹ�߸���˵������������ּӢ���������Ųߡ���\n",
                "����ʹ��˵����������ǧ�����أ�һͳ��������\n",
               "����ʹ�߸߽е����������ĳ���£�����Ӣ��������ʥ�̣��󱻲�������\n",
        }));
 }
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
         && !ob->query_temp("hmy_enter")
        && !present("heimu ling", ob) 
        && ( (fam = ob->query("family")) && fam["family_name"] != "�������" ) )
        {
                if( !ob->query_temp("warned") ) {
                        command("say ����˭��  ��ô����������������ˣ���");
                        command("say ����������뿪���´ο����������ģ�");
                        ob->set_temp("warned", 1);
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say �󵨿�ͽ�����Ҵ����������������Ұ������\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                }
        }       
 }
