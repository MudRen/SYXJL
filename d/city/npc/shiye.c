// shiye.c ֪��ʦү

inherit NPC;

string ask_me();

void create()
{
        set_name("̷�Ѽ�", ({ "tan youji", "tan" }));
        set("title", "֪��ʦү");
        set("gender", "����");
        set("age", 57);

        set("combat_exp", 30000);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage",  20);
        set("shen_type", 0);

        set("inquiry", ([
                "�л���" : (: ask_me :)
        ]) );

        setup();
this_object()->carry_object("/clone/misc/cloth")->wear();
}
        
string ask_me()
{
        if ((int)this_player()->query_temp("marks/��"))
        {
                say("��С�ӣ�����ô֪����ϲ���Խл�����\n");
                command("lick");
                say("��Ȼ���ҳ���ʳ�ѣ��Ҿ͸�����ɡ�����������\n");
                command("whisper " + this_player()->query("id") + " ��ȥ������ȫ�۵µ��ϰ壬ֻҪ���������ҽ���ȥ�ģ����ͻ�...");
                this_player()->delete_temp("marks/��");
                this_player()->set_temp("marks/��2", 1);
                return "������....��....�Ǹ������ܺ�....\n";
        }
        else if((int)this_player()->query_temp("marks/��2"))
                return "���Ǹ��㽭�ˣ�Ҳû������ô���£�\n";
        else
                return "����˿��ż������\n";
}

void init()
{
        ::init();
        add_action("do_chat", "chat");
        add_action("do_chat","chat*");
        add_action("do_jiehun","jiehun");
        add_action("do_jiehun","marry");
        add_action("do_lihun","lihun");
}


int do_chat()
{
  object ob;
   ob=this_player(1);
  
   say("̷�Ѽ���ɫһ�����ȵ�������֮�ϣ�����������\n");
   tell_object(ob,"�������۳���ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n");
   ob->unconcious();
   return 0;
}


int do_lihun(string arg)
{
object me;
object ob;
//object card;

object *inv;
int i;

me=this_player(1);

if(!arg)   {
             tell_object(me,"���Լ����Լ���鰡��\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"�������Ŀǰ����������ɣ�\n");
            return 1;
         }


      say(me->query("name")+"��Ҫ��"+ob->query("name")+"���.\n");

      if( !(me->query("marry") == arg) )
        {
          say("̷�Ѽ��ɻ�Ŀ��˿�"+me->query("name")+
                "˵����û�����\n");
          return 1;
        }

      if(!me->query("marry"))
        {
         say("̷�Ѽ;��ȵ���"+me->query("name")+
             "��û�а��£�������?\n");
         return 1;
        }

      if(!present(arg,environment()))
        {
         say("̷�Ѽ�ҡҡͷ˵:"+ob->query("name")+"���ڲ������\n");
         return 1;
        }
      if( ob->query("want_lihun")==me->query("id") )
        {
         say("̷�Ѽ�̾Ϣ�������Ǻ���Ϊ֮��\n");

         inv=all_inventory(me);
         for(i=0;i<sizeof(inv);i++)      
            {
             if(inv[i]->query("id")=="jiehunzheng") 
              {
                destruct(inv[i]);

              }
            }
         inv=all_inventory(ob);
         for(i=0;i<sizeof(inv);i++)
            {
             if(inv[i]->query("id")=="jiehunzheng")
              {
                destruct(inv[i]);

              }
            }

         me->delete("marry");
         me->delete("want_marry");
         me->delete("want_lihun");
         ob->delete("marry");
         ob->delete("want_marry");
         ob->delete("want_lihun");
         tell_object(me,"��Ļ�����ϵ�������\n");
         tell_object(ob,"��Ļ�����ϵ�������\n");
        }
      else
        {
         say("̷�Ѽ͵���"+me->query("name")+",����뷨��֪����"+
             ",������Ҫ����"+ob->query("name")+"����˼��\n");
         me->set("want_lihun",arg);
         return 1;
        }

return 1;
}

int do_jiehun(string arg)
{
object me;
object ob;
object card;

me=this_player(1);

if(!arg)   {
             tell_object(me,"���Լ����Լ���鰡��\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"�������Ŀǰ����������ɣ�\n");
            return 1;
         }


      say(me->query("name")+"��Ҫ��"+ob->query("name")+"���.\n");
      
      if(me->query("age") <16)
        {
         say("̷�Ѽ�ҡҡͷ����Ȼ��û�ﵽ������䡣\n");
         return 1;
        }

      if(me->query("marry")== arg )
        {
          say("̷�Ѽ��ɻ�Ŀ��˿�"+me->query("name")+
                "˵����û�����\n");
          return 1;
        }

      if(me->query("marry")) 
        {
         say("̷�Ѽʹ�ŭ��һ�����Ӻȵ���"+me->query("name")+
             "�����а��£������ػ飡\n");
         say("�������۳���ǰ�������ɷ�˵��һ������"+
               me->query("name")+"Ƥ������,���˹�ȥ��\n");
         me->unconcious();
         return 1;
        }
      
      if(!present(arg,environment()))
        {
         say("̷�Ѽ�ҡҡͷ˵:"+ob->query("name")+"���ڲ������\n");
         return 1;
        }
      if( ob->query("want_marry")==me->query("id") )
        {
         say("̷�Ѽ�΢Ц����ף��������ͷг�ϣ����޶��ġ�\n");   
         ob->set("marry",me->query("id"));
         me->set("marry",arg);
         card= clone_object("d/city/obj/marry_card");
         card->set("name","���"+arg+"�Ľ��֤");
         card->move(me);
         card= clone_object("d/city/obj/marry_card");
         card->set("name","���"+me->query("id")+"�Ľ��֤");
         card->move(ob);
         say("̷�Ѽ͵ݸ�"+ob->query("name")+"��"+me->query("name")
                  +"һ��һ�Ž��֤��.\n");
         return 1 ;
         
        } 
      else
        {
         if( me->query("gender") == ob->query("gender") )
          {
           say ("ͬ��������, ̷�Ѽͱ�"+me->query("name")+
                  "���ÿ��°�ĭ���˹�ȥ.\n");
           return 1;
          }
         say("̷�Ѽ�΢Ц����"+me->query("name")+",���������֪����"+
             ",������Ҫ����"+ob->query("name")+"����˼��\n");
         me->set("want_marry",arg);
         return 1;
        }

return 1;
}


