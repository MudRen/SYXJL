//shitai.c ....angle

inherit NPC;

#include <ansi.h>



void create()

{       set_name("����ʦ̫", ({ "wenrou shitai", "shitai" })); 

        set("title", HIW"����������"NOR);        

        set("gender", "Ů��");

        set("age", 32);

        set("str", 20);

        set("dex", 20); 

        set("per", 30);   

set("long", "�����Զ������������ʦ̫����˵��������ŵ�ԭ�������Ϊ���ľ������ݣ��������Թź��ջ�ˮ,

ȷʵ˵�ò���\n");

        set("combat_exp", 12000);

        set("shen_type", 1);

        set("attitude", "friendly"); 

       

        set_skill("unarmed", 45);

        set_skill("dodge", 45);

        set_skill("parry", 45);

        set_skill("force", 45);



        set_temp("apply/attack", 25);

        set_temp("apply/defense", 25);

        set_temp("apply/armor", 25);

        set_temp("apply/damage", 15);

        setup();

        carry_object("/clone/misc/cloth")->wear();  

} 

void init()

{

        object ob;

         ::init();

 if (interactive(ob = this_player()) && !is_fighting() ) {

                remove_call_out("greeting");

                call_out("greeting", 1, ob);

        }

}



void greeting(object me)

{

       command("look " + me->query("id"));

        if(present("shi kuai", this_player()) ) 

       {command("say ��λʩ���������ˣ�������ϵ�ʯͷ�������ɣ�"); }        if(!present("shi kuai", this_player()) ) {

       command("say ��λʩ�����ٱ��֣���֪�кι�ɣ����������������֡���δ�޽���ϣ�����ʩ����������"); }       }





