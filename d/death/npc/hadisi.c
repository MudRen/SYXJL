#include <ansi.h>

inherit NPC;
int work_me();
void create()
{
       set_name("阎罗王", ({"yan wang"}));
       set("long", "身穿大红蟒袍，头戴黑绸软巾．
面如锅底，须若钢针，这就是阎罗王．\n");
       set("title", "冥王");
       set("gender", "男性");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_qi", 1100);
       set("max_jing", 1100);
       set("neili", 1150);
       set("max_neili", 1000);
       set("max_jingli", 1500);
       set("jingli", 1500);
       set("combat_exp", 1000000);

       set_skill("unarmed", 150);
   set_skill("whip", 100);
   set_skill("sword", 150);
       set_skill("dodge", 120);
       set_skill("parry", 150);
        set_skill("force", 150);

   set("nk_gain", 500);

   set_temp("apply/armor", 50);
   set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );

set("inquiry", ([
     "十八层地狱" : (: work_me :),

"name": "哼！连老夫都不认得，想来是活的太久了！\n",
"here": "这便是阎罗地府，到阳间一谈，嘿嘿，没人不怕！\n",
"阳间": "还阳容易，要不想有损失就难了！\n",
]) );

setup();

        carry_object("/clone/misc/cloth.c")->wear();
}

int accept_fight(object me)
{
        command("say " + "哈哈！阎王不叫，自己上门！\n");
        return 1;
}

int work_me()
{
   object who;
   who=this_player();

   if( (int)who->query("combat_exp") < 300000 ) {
     message_vision("$N对$n一拱手，道：经验不够，强求亦是枉然。\n", this_object(),who);
     return 1;
   }
   if( who->query("HellZhenPass") ) {

message_vision("$N对$n一拱手，道：即是武功高强，我等佩服便是，这。。。便是免了吧！\n",this_object(),who);
   return 1;
   }
   if( this_object()->query_temp("SomeonePassing") ) {
     message_vision("$N对$n一拱手，道：真时机缘不巧，改日再来吧。\n",this_object(),who);
     return 1;
   }


message_vision("$N对$n阴阴地笑了几声，说：天堂有路你不走，地狱无门你闯进来。\n",this_object(),who);
   this_object()->set_temp("SomeonePassing");
   command("chat "+who->query("name")+"要闯俺幽冥地府十八层地狱，哼！等着收尸吧！\n");

   message_vision("$N双手拍了一下，$n脚下突然陷了下去。。。\n", this_object(),who);
   who->delete("env/brief_message");
   who->move("/d/death/emptyroom");

   command("grin");
   this_object()->move("/obj/void");
   
   call_out("message",3,who);
   call_out("round_1",4, who);
   return 1;
}
int check_status(object who)
{
   if( (int)who->query("qi") < 50 
   ||   (int)who->query("eff_qi") < 50 ) {
                remove_call_out("round_2");
                remove_call_out("round_3");
                remove_call_out("round_4");
                remove_call_out("round_5");
                remove_call_out("round_6");
                remove_call_out("round_7");
                remove_call_out("round_8");
                remove_call_out("round_9");
                remove_call_out("round_10");
                remove_call_out("round_11");
                remove_call_out("round_12");
                remove_call_out("round_13");
                remove_call_out("round_14");
                remove_call_out("round_15");
                remove_call_out("round_16");
                remove_call_out("round_17");
                remove_call_out("round_18");
     remove_call_out("message");
     remove_call_out("winning");
     call_out("failed",1,who);
     return 1;
   }
}
int failed(object who)
{   
   command("chat* heihei");
   command("chat 果真有不怕死的，可惜还是逃不出俺的手掌心！\n");
   this_object()->delete_temp("SomeonePassing");
   who->move("obj/void");
   who->unconcious();
   this_object()->move("/d/death/youmingdian");
   call_out("remove_all", 3);
   return 1;
}
int remove_all()
{   int i;
        object *list,empty;

        if( !(empty = find_object("/d/death/emptyroom")) )
                empty = load_object("/d/death/emptyroom");
   write("四周刮起一阵阴风。。。\n");
        if( empty = find_object("/d/death/emptyroom") ) {

     list=all_inventory(empty);
     i = sizeof(list);
     while (i--)
     {
        object ob=list[i];
        ob->move("/d/city/wumiao");
     }
   }
   return 1;
}

int winning(object who)
{
   command("chat "+who->query("name")+"，算你走运，下回可没这么便宜了！\n");
   who->add("kar", 10);
   who->add("potential", 5000);
   who->add("combat_exp", 10000);
   tell_object(who,"你得到了五千潜能和一万实战经验。\n");
   who->set("HellZhenPass",1);
   this_object()->move("/d/death/youmingdian");
   this_object()->delete_temp("SomeonePassing");
   call_out("remove_all", 3);
   return 1;
}
int message(object who)
{
   switch(random(5)) {

     case 0:
tell_room(environment(who),"\n你觉得自己不断下降，周围景物如彩蝶翻飞，不可注目。\n");
break;
     case 1:
tell_room(environment(who),"\n你觉得自己不断下降。\n");
break;
     case 2:
tell_room(environment(who),"\n你觉得自己不断下降，天地似乎没了界限。。。\n");
break;
                case 3:
tell_room(environment(who),"\n你觉得自己不断下降，周围一切都在旋转。。。\n");
break;
     case 4:
tell_room(environment(who),"\n你觉得自己不断下降，下降，似乎落向了无尽的深渊。\n");
break;
   }
   return 1;
}
int round_1(object who)
{
   object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/1");
   tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
   tell_room(environment(who),RED"                **************************************\n"NOR);
   tell_room(environment(who),RED"                **               吊筋狱             **\n"NOR);
   tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   call_out("check_status",1,who);
   call_out("message",2,who);
   call_out("round_2", 3, who);
        return 1;
}

int round_2(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/2");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               幽枉狱             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_3", 3, who);
        return 1;
}
int round_3(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/3");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               火坊狱             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_4", 3, who);  
        return 1;
}
int round_4(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/4");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               酆都狱             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_5", 3, who);  
        return 1;
}
int round_5(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/5");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        tell_room(environment(who),MAG"                **               拔舌狱             **\n"NOR);
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_6", 3, who);  
        return 1;
}
int round_6(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/6");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               剥皮狱             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_7", 3, who);  
        return 1;
}
int round_7(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/7");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        tell_room(environment(who),HIR"                **               磨涯狱             **\n"NOR);
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_8", 3, who);  
        return 1;
}
int round_8(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/8");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        tell_room(environment(who),HIG"                **               锥捣狱             **\n"NOR);
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_9", 3, who);  
        return 1;
}
int round_9(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/9");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        tell_room(environment(who),HIY"                **               车崩狱             **\n"NOR);
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_10", 3, who);  
        return 1;
}
int round_10(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/10");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        tell_room(environment(who),HIB"                **               寒冰狱             **\n"NOR);
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_11", 3, who);  
        return 1;
}
int round_11(object who)
{
        object ghost,ghostb;
   seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/11");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        tell_room(environment(who),HIM"                **               脱壳狱             **\n"NOR);
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_12", 3, who);  
        return 1;
}
int round_12(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/11");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/12");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        tell_room(environment(who),HIC"                **               抽肠狱             **\n"NOR);
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_13", 3, who);  
        return 1;
}
int round_13(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");

        seteuid(getuid());
        ghost=new("/d/death/HellZhen/13");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        tell_room(environment(who),HIW"                **               油锅狱             **\n"NOR);
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_14", 3, who);  
        return 1;
}
int round_14(object who)
{
        object ghost,ghostb;
   seteuid(getuid());
        ghostb=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/14");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               黑暗狱             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_15", 3, who);  
        return 1;
}
int round_15(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/15");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               刀山狱             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_16", 3, who);  
        return 1;
}
int round_16(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/16");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               血池狱             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_17", 3, who);  
        return 1;
}
int round_17(object who)
{
        object ghost,ghostb;
   seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               阿鼻狱             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_18", 3, who);  
        return 1;
}
int round_18(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/18");
   seteuid(getuid());
   ghostb=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               秤杆狱             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("winning", 3, who);  
        return 1;
}
