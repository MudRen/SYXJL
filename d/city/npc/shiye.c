// shiye.c 知府师爷

inherit NPC;

string ask_me();

void create()
{
        set_name("谭友纪", ({ "tan youji", "tan" }));
        set("title", "知府师爷");
        set("gender", "男性");
        set("age", 57);

        set("combat_exp", 30000);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage",  20);
        set("shen_type", 0);

        set("inquiry", ([
                "叫化鸡" : (: ask_me :)
        ]) );

        setup();
this_object()->carry_object("/clone/misc/cloth")->wear();
}
        
string ask_me()
{
        if ((int)this_player()->query_temp("marks/鸡"))
        {
                say("好小子，你怎么知道我喜欢吃叫化鸡？\n");
                command("lick");
                say("既然你我成了食友，我就告诉你吧。付耳过来！\n");
                command("whisper " + this_player()->query("id") + " 你去北京找全聚德的老板，只要告诉他是我叫你去的，他就会...");
                this_player()->delete_temp("marks/鸡");
                this_player()->set_temp("marks/鸡2", 1);
                return "今天嗯....啊....那个天气很好....\n";
        }
        else if((int)this_player()->query_temp("marks/鸡2"))
                return "我是个浙江人，也没有你那么罗嗦！\n";
        else
                return "泥缩丝米偶钉布懂\n";
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
  
   say("谭友纪脸色一沉，喝道：大堂之上，竟敢喧哗！\n");
   tell_object(ob,"两边衙役冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n");
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
             tell_object(me,"你自己和自己离婚啊？\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"你提的人目前不在这世界吧？\n");
            return 1;
         }


      say(me->query("name")+"想要和"+ob->query("name")+"离婚.\n");

      if( !(me->query("marry") == arg) )
        {
          say("谭友纪疑惑的看了看"+me->query("name")+
                "说：有没搞错啊？\n");
          return 1;
        }

      if(!me->query("marry"))
        {
         say("谭友纪惊讶道："+me->query("name")+
             "你没有伴侣，如何离婚?\n");
         return 1;
        }

      if(!present(arg,environment()))
        {
         say("谭友纪摇摇头说:"+ob->query("name")+"现在不在这里。\n");
         return 1;
        }
      if( ob->query("want_lihun")==me->query("id") )
        {
         say("谭友纪叹息道：你们好自为之。\n");

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
         tell_object(me,"你的婚姻关系被解除了\n");
         tell_object(ob,"你的婚姻关系被解除了\n");
        }
      else
        {
         say("谭友纪道："+me->query("name")+",你的想法我知道了"+
             ",不过还要问问"+ob->query("name")+"的意思。\n");
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
             tell_object(me,"你自己和自己结婚啊？\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"你提的人目前不在这世界吧？\n");
            return 1;
         }


      say(me->query("name")+"想要和"+ob->query("name")+"结婚.\n");
      
      if(me->query("age") <16)
        {
         say("谭友纪摇摇头，显然你没达到结婚年龄。\n");
         return 1;
        }

      if(me->query("marry")== arg )
        {
          say("谭友纪疑惑的看了看"+me->query("name")+
                "说：有没搞错啊？\n");
          return 1;
        }

      if(me->query("marry")) 
        {
         say("谭友纪大怒，一拍桌子喝道："+me->query("name")+
             "你已有伴侣，竟敢重婚！\n");
         say("两边衙役冲上前来，不由分说，一阵大板打得"+
               me->query("name")+"皮开肉绽,昏了过去。\n");
         me->unconcious();
         return 1;
        }
      
      if(!present(arg,environment()))
        {
         say("谭友纪摇摇头说:"+ob->query("name")+"现在不在这里。\n");
         return 1;
        }
      if( ob->query("want_marry")==me->query("id") )
        {
         say("谭友纪微笑道：祝你们俩白头谐老，永无二心。\n");   
         ob->set("marry",me->query("id"));
         me->set("marry",arg);
         card= clone_object("d/city/obj/marry_card");
         card->set("name","你和"+arg+"的结婚证");
         card->move(me);
         card= clone_object("d/city/obj/marry_card");
         card->set("name","你和"+me->query("id")+"的结婚证");
         card->move(ob);
         say("谭友纪递给"+ob->query("name")+"和"+me->query("name")
                  +"一人一张结婚证书.\n");
         return 1 ;
         
        } 
      else
        {
         if( me->query("gender") == ob->query("gender") )
          {
           say ("同性恋啊！, 谭友纪被"+me->query("name")+
                  "气得口吐白沫昏了过去.\n");
           return 1;
          }
         say("谭友纪微笑道："+me->query("name")+",你的心意我知道了"+
             ",不过还要问问"+ob->query("name")+"的意思。\n");
         me->set("want_marry",arg);
         return 1;
        }

return 1;
}


