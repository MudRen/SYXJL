#include <ansi.h>

inherit NPC;
int work_me();
void create()
{
       set_name("������", ({"yan wang"}));
       set("long", "��������ۣ�ͷ���ڳ����
������ף��������룬�������������\n");
       set("title", "ڤ��");
       set("gender", "����");
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
     "ʮ�˲����" : (: work_me :),

"name": "�ߣ����Ϸ򶼲��ϵã������ǻ��̫���ˣ�\n",
"here": "��������޵ظ���������һ̸���ٺ٣�û�˲��£�\n",
"����": "�������ף�Ҫ��������ʧ�����ˣ�\n",
]) );

setup();

        carry_object("/clone/misc/cloth.c")->wear();
}

int accept_fight(object me)
{
        command("say " + "�������������У��Լ����ţ�\n");
        return 1;
}

int work_me()
{
   object who;
   who=this_player();

   if( (int)who->query("combat_exp") < 300000 ) {
     message_vision("$N��$nһ���֣��������鲻����ǿ��������Ȼ��\n", this_object(),who);
     return 1;
   }
   if( who->query("HellZhenPass") ) {

message_vision("$N��$nһ���֣����������书��ǿ���ҵ�������ǣ��⡣�����������˰ɣ�\n",this_object(),who);
   return 1;
   }
   if( this_object()->query_temp("SomeonePassing") ) {
     message_vision("$N��$nһ���֣�������ʱ��Ե���ɣ����������ɡ�\n",this_object(),who);
     return 1;
   }


message_vision("$N��$n������Ц�˼�����˵��������·�㲻�ߣ����������㴳������\n",this_object(),who);
   this_object()->set_temp("SomeonePassing");
   command("chat "+who->query("name")+"Ҫ������ڤ�ظ�ʮ�˲�������ߣ�������ʬ�ɣ�\n");

   message_vision("$N˫������һ�£�$n����ͻȻ������ȥ������\n", this_object(),who);
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
   command("chat �����в������ģ���ϧ�����Ӳ������������ģ�\n");
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
   write("���ܹ���һ�����硣����\n");
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
   command("chat "+who->query("name")+"���������ˣ��»ؿ�û��ô�����ˣ�\n");
   who->add("kar", 10);
   who->add("potential", 5000);
   who->add("combat_exp", 10000);
   tell_object(who,"��õ�����ǧǱ�ܺ�һ��ʵս���顣\n");
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
tell_room(environment(who),"\n������Լ������½�����Χ������ʵ����ɣ�����עĿ��\n");
break;
     case 1:
tell_room(environment(who),"\n������Լ������½���\n");
break;
     case 2:
tell_room(environment(who),"\n������Լ������½�������ƺ�û�˽��ޡ�����\n");
break;
                case 3:
tell_room(environment(who),"\n������Լ������½�����Χһ�ж�����ת������\n");
break;
     case 4:
tell_room(environment(who),"\n������Լ������½����½����ƺ��������޾�����Ԩ��\n");
break;
   }
   return 1;
}
int round_1(object who)
{
   object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/1");
   tell_room(environment(who),"\nͻȻ��һ������������\n\n");
   tell_room(environment(who),RED"                **************************************\n"NOR);
   tell_room(environment(who),RED"                **               ������             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               ������             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               ����             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               ۺ����             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        tell_room(environment(who),MAG"                **               ������             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               ��Ƥ��             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        tell_room(environment(who),HIR"                **               ĥ����             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        tell_room(environment(who),HIG"                **               ׶����             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        tell_room(environment(who),HIY"                **               ������             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        tell_room(environment(who),HIB"                **               ������             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        tell_room(environment(who),HIM"                **               �ѿ���             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        tell_room(environment(who),HIC"                **               �鳦��             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        tell_room(environment(who),HIW"                **               �͹���             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               �ڰ���             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               ��ɽ��             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               Ѫ����             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               ������             **\n"NOR);
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
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               �Ӹ���             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
   ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("winning", 3, who);  
        return 1;
}
