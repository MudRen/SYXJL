#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("��ӯӯ", ({ "ren yingying","ren" }));
        set("long", "�����ü������������Ƕ��۾����ĵ�ֱ���Թ��˻��ǡ�\n");
       set("nickname", "�������");             
       set("title", "������̻����ɹ�");
        set("gender", "Ů��");
        set("age", 20);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 40000);
        set("shen_type", 1);
       create_family("�������",3,"����");
       set("chat_chance",1);
        set("chat_msg",({
         "��֪��������������,�Ƿ��ֺ���С������һ��......\n",
        "�����ܰ�������Ӹ�������̫лл����.............\n",
        "Ҳ��֪����˼�û�����������漱������.......\n",
           }) );
       set("inquiry",([
        "�����" : (: ask_me :),
           ]));
       set_temp("letter",1);
        
setup();
        carry_object("/d/city/npc/obj/necklace")->wear();
}
string ask_me()
{
 object me=this_player();
 object obn;

 message_vision("ȥ���ϻ�ɽһȥ����������,�����������Ұ�......\n"
         , me );
 if(query_temp("letter")==0)
 {  message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ��������ȥѰ����,\nҲ��֪����ô���ˡ�\n",me);
   return "";
 }
   message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"������������, ��Ҫ���ҵ������塻��\n�Ͱ��Ž��������������׵ġ�\n" , me);
   obn=new(__DIR__"obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("����ŷ��㽻������塣\n");
}

void init()
{
        object me, ob;

        me = this_object();

      if(present("xo", this_player())     )
        {
         command("say �ۣ���Ȼ��ˣ��Ȿ�ؼ�����ȥ���ɣ�����.....\n");
         ob = new(__DIR__"obj/du");
         ob->move(this_player());
         this_player()->set_temp("marks/Ц��������", 1);
         destruct(present("xo", this_player()));
         return;
        }

        return;
}
        
int accept_object(object me, object ob)
{
        object book;
        
        command("smile");
        command("say ��������һ����������лл" + RANK_D->query_respect(me) + " ��");

        if( ob->query("money_id") && ob->value() >= 30000 && me->query("class") != "bonze")
        {
                book=new(__DIR__"obj/sword_book");
                book->move(me);
                message_vision("ӯӯ��$Nһ�����ס�\n", me);

                command("say ��ûʲô�������,�Ȿ���׾��͸���ɡ�"); 
                return 1;
        }

        return 1;
}
