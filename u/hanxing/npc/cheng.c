inherit NPC;
#include "/u/hanxing/name.h";
#include "/u/hanxing/location.h",
#include <ansi.h>;

mapping userskills;
string username;

int give_quests();
int accountguaiexp(int turn,object who);
int guaif(int turn,object who);
int guaim(int turn,object who);
int set_guai_qi_jing(int turn,object guai);
int getexp(int turn,int level,object who);
string setguaititle(int number,object guaiob);
string randomlocation(int i1);

void create()
{
  set_temp("username","macrohard");
  set_temp("level",200);
  set_name("��ҩ��", ({"cheng yaofa", "cheng", "yaofa"}));
  set("long", "�����ǳ�ҩ�������ݳ�����֪����\n");
  set("gender", "����");
  set("age", 40);
  set("attitude", "friendly");
  set("per", 100);
  set("str", 3000);
  set("int", 40);
  set("dex",500);
  set("con",500);
  set("max_qi", 30000);
  set("max_jing", 30000);
  set("neili", 88888);
  set("max_neili", 4000);
  set("max_jingli", 4000);
  set("jingli", 8000);
  set("combat_exp", 5000000);
  set_skill("unarmed", 300);
  set_skill("dodge", 300);
  set_skill("sword", 300);
  set_skill("blade", 300);
  set_skill("parry", 300);
  set_skill("force", 300);
  set("inquiry",([   "job":(:give_quests():),]));
    setup();
        carry_object("/d/city/npc/obj/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

}
void init()
{
        object who;

        ::init();

        if( interactive(who = this_player()) && !who->is_fighting() ) 
       {
                remove_
call_out("greeting");
                call_out("greeting", 1, who);
        }
}
void greeting(object who)
{
        if( !who || environment(who) != environment() ) return;
        if ((int)who->query("combat_exp")<1000)
        {
           switch(random(4))
           {
                case 0:command("hehe "+(string)who->query("id"));break;
                case 1:command("welcome "+(string)who->query("id"));break;
                case 2:command("bow "+(string)who->query("id"));break;
                case 3:command("whisper "+(string)who->query("id")+" Ҫ������? ���Ҵ���job����Ϣ�Ϳ�����!");break;
           }
     
        }
           say("��ҩ����"+who->query("name")+"˵��:��λ"+RANK_D->query_respect(who)+
               ",����������\n");
           if(random(40)>20)
           command("heihei "+(string)who->query("id"));
        return;
}
int max_skill_level(object ob)
{  

   int s,i=0,maxlevel=1;
   string *str;
   userskills=ob->query_skills();
   if (!mapp(userskills)) {maxlevel=3;return maxlevel;}
   str=keys(userskills);

   s=sizeof(str);
   if (s<2) return userskills[str[0]]; 
   while (s>0)
     {
       s-=1;
       i=userskills[str[s]];
       if (i>maxlevel) maxlevel=i;
     }
   return maxlevel;
}

int accountlevel(int turn,object ob)
{
   int level;
   level=max_skill_level(ob);
   level=(int)level*(70+turn*4)/100;
   if(level==0) level = 1;
   return level;
}

string randomlocation(int i1)
{
   string *str1,*str2,loca;
   int i2,temp;
   str1=keys(allloca);
   str2=allloca[str1[i1]];
   i2=sizeof(str2);
   temp=random(i2);
   if (temp==0 || temp==i2) temp=1;
   loca=str2[0]+str2[temp];
   return loca;
}
      
int give_quests()
{
   object guaiob;
   object me,who,tempob;
   int chooseguai,rewardpot,rewardexp,turn;
   int questbusytime,giveuptime,guailevel;
   int temp,i1;
   string *strtemp,locastr;
   me=this_object();
   who=this_player();

   giveuptime=who->query_temp("questtime2");
   questbusytime=who->query_temp("questtime1");
   turn=who->query_temp("turn");
   if(who->query("combat_exp")>150000){
        write("�����������ָ��֣�������Ĺ������ܲ����ʺ�����!\n");
        return 1;
        }
   if (who->query_temp("kill"))
     {
       if (time()<giveuptime)
        {      
         message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)
          +"�����²�������ȥɱ��"+who->query_temp("guainame")+"��\n",me,who);
          return 1;
        }
        else turn-=2;
     }
   else
     {
       if (time()<questbusytime) 
        {
        message_vision ("$N���˿���,���΢Ц�Ķ�$n˵����\n"
        +"��λ"+RANK_D->query_respect(who)+",�����Ѿ�������������ȥЪϢ��\n"
        ,me,who);
        return 1;
        }
      }
     
//ÿʮ������һ�֣���turn ������
   
   if (!turn || turn>9) 
      {
        who->set_temp("turn",0);
        turn=0;
      }
   turn=turn+1;
   who->set_temp("turn",turn);
   guailevel=accountlevel(turn,who);
   guaiob=new("/u/hanxing/questguai_n"); 
   
   guaiob->set_heart_beat(1);
   guaiob->set_temp("killername",(string)who->query("id"));

   

//���ùֵ�jingli,neili,exp,

   set_guai_qi_jing(turn,who);
   guaiob->set("max_neili",guaif(turn,who));
   guaiob->set("neili",(int)(guaif(turn,who)*6/5));
   guaiob->set("max_jingli",guaim(turn,who));
   guaiob->set("jingli",(int)(guaim(turn,who)*6/5));
   guaiob->set("combat_exp",accountguaiexp(turn,who));
   guaiob->set("neili_factor",(int)(guailevel/2));
   guaiob->set("jiali",(int)who->query_skill("force")/4);
   guaiob->set("jingli_factor",(int)(guailevel/2));
   set_guai_qi_jing(turn,guaiob);

//set guai's "long" and "title" 
   switch (random(3))
    {
     case 1 :
     if(guaiob->query("combat_exp")>100000)
      { guaiob->set("long","һ�����ָ���,��˵��ʦ�������ɣ���"HIR+who->query("name")+NOR"��Ŀ��\n");break;}
       else 
     { guaiob->set("long","��������"+guaiob->query("name")
                +",��˵�������ɵĸ��֣�����Щ���졣\n");break;}
     case 2 :
      if(guaiob->query("combat_exp")>100000)
    {   guaiob->set("long","һ���ڵ�����,��˵������һ�����ص���֯����"HIR+who->query("name")+NOR"��Ŀ��\n");break;}
       else
     { guaiob->set("long","�ڵ�����"+guaiob->query("name")
              +"��ȫ��ɢ����һ˿а����\n");break;}
      default :
      guaiob->set("long","�䵱��ͽ"+guaiob->query("name")
              +"������������ɱ�����ˡ�\n");
    }
   chooseguai=random(14);
   setguaititle(chooseguai,guaiob);   

//rewardexp and rewardpot ��ɱ�ֺ�õ���qn and exp
   
   rewardexp=getexp(turn,guailevel,who)*2/3;
   rewardpot=rewardexp/6;
   guaiob->set_temp("killrewardpot",rewardpot);
   guaiob->set_temp("killrewardexp",rewardexp);
   guaiob->set_temp("player",who);
   guaiob->setguaiskill(chooseguai,guailevel,guaiob);
   guaiob->check_time();  

//ȷ���ֵ�λ�� 
   strtemp=keys(allloca);
   i1=sizeof(strtemp);
   temp=random(i1);
   if (temp==i1) temp=0;
   locastr=randomlocation(temp);  
   tempob=load_object(locastr);

//if we get a wrong path,these can help us 
   if (!tempob) 
     {
     message_vision(HIR"���ں��ǹ���ʧ��,$N���ֺ���û��:"+locastr+"������䣬����֪ͨ���ǣ�����Ҫһ������\n"NOR,who);
      return 1;
     }
   guaiob->move(tempob);

//������ҵ���ʱ����
   who->set_temp("questtime1",time()+60+random(200)); 
   who->set_temp("questtime2",time()+600);
   who->set_temp("guainame",guaiob->query("name"));
   who->set_temp("turn",turn);
   who->set_temp("kill",1);
   message_vision("$N΢Ц�Ŷ�$n˵��������λ"+RANK_D->query_respect(who)+"���ҳ�����"+strtemp[temp]+"��û��"+
   guaiob->query("title")+YEL+guaiob->query("name")+"("+
        guaiob->query("id")+")"+NOR", �Ϸ������л��\n",me,who); 
   return 1;
}
// accountguaiexp ����ֵľ���ֵ
int accountguaiexp(int turn,object who)
{ 
   int userexp,guaiexp;
   userexp=who->query("combat_exp");
   guaiexp=userexp*(70+turn*6)/100;
   return guaiexp;
}
// guaif ����ֵ�����
int guaif(int turn,object who)
{
   int userneili,guaineili;
   userneili=who->query("max_neili");
   guaineili=userneili*(70+turn*5)/80;
   return guaineili;
}
int guaim(int turn,object who)
{
   int userjingli,guaijingli; 
   userjingli=who->query("max_jingli");
   guaijingli=userjingli*(70+turn*5)/80;
   return guaijingli;
}
int set_guai_qi_jing(int turn,object guai)
{
   int maxqi,maxjing;
   maxqi=200+(int)guai->query("max_neili")*(100+turn*20)/200;
   maxjing=200+(int)guai->query("max_jingli")*(100+turn*8)*4/1000;
   guai->set_temp("maxqi",maxqi);
   guai->set("max_qi",maxqi);
   guai->set("eff_qi",maxqi);   return 1;
}
//ɱ�ֵõ���exp,����ҵ�skills ,exp,turn �й�
int getexp(int turn,int level,object who)
{
   int exp,userexp;
   userexp=who->query("combat_exp");
   if(turn<1) turn =1;
   exp=random(30)+turn*30+(userexp/50000)*turn+(level*level/2000)*turn;
   return exp;
}

string setguaititle(int number,object guaiob)
{
   if (random(10)>7)
      {
       if (guaiob->query("combat_exp")>2000000)
             guaiob->set("title","ɱ�˿�ħ");
       else if (guaiob->query("combat_exp")>1000000)
             guaiob->set("title","�����ӯ");
       else if (guaiob->query("combat_exp")>500000)
             guaiob->set("title","������");
       else if (guaiob->query("combat_exp")>100000)
             guaiob->set("title","���");
        else if (guaiob->query("combat_exp")>50000)
             guaiob->set("title","�ɻ���");     
         else if (guaiob->query("combat_exp")>10000)
             guaiob->set("title","��åͷ");  
        else if (guaiob->query("combat_exp")>5000)
             guaiob->set("title","��å");
       else  guaiob->set("title","С��å");
      }
   else 
      {
        switch (number)
        {
         case 0 :guaiob->set("title","�嶾��ħŮ");break;
         case 1 :guaiob->set("title","���Ҷ���");break;
         case 2 :guaiob->set("title","ȫ����");break;
         case 3 :guaiob->set("title","�䵱����");break;
         case 4 :guaiob->set("title","���ֶ�ɮ");break;
         case 5 :guaiob->set("title","��������");break;
         case 6 :guaiob->set("title","ؤ����ͽ");break;
         case 7 :guaiob->set("title","��ɽ����");break;
         case 8 :guaiob->set("title","������ħ");break;
         case 9 :guaiob->set("title","���̱�ͽ");break;
         case 10 :guaiob->set("title","������ͽ");break;
         case 11 :guaiob->set("title","�һ�����ͽ");break;
         case 12 :guaiob->set("title","��ң�ɼ���");break;
         case 13 :guaiob->set("title","��Ĺ����ͽ");break;
         
         default :guaiob->set("title","С��");break;
}
}
}

   guai->set("qi",maxqi)
   guai->set("max_jing",maxjing)
   guai->set("eff_jing",maxjing)
   guai->set("jing",maxjing)
