// �����

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", "�����");
        set("long", @LONG
��������ͼ�����ߵ��η����������ǳ���ȥ�ˡ��ú÷�˼����ɵ��£�
��һ��������Υ�������������Σ�û�˻�������ˡ����й��������мҹ棬
��MUDҲ���������ٶ��� help rules �ɣ����WIZS����ԭ���㣬�����ֻ��
ѡ����ɱ suicide -f �ˡ����ס��������ǹ��е����硣
LONG
);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1); 
        set("no_yun", 1);
        set("title",HIR"�ڹ���... "NOR);        set("valid_startroom", 1);

        setup();
//        "/clone/board/huiguo_b.c"->foo();
}
void init()
{ 
	object ob;
	ob = this_player();
        //::init();	
	call_out("do_check",1,ob);
        add_action("do_action", "");                             
}


int do_action(string arg)
{
       string action = query_verb();

       switch (action) { 
               case "suicide -f":
               case "edit":
               case "wiz":
               case "dun" :               
               case "move":
               case "dazuo": 
               case "more":
               case "cat" :
               case "update" :               
               case "chat":
               case "chat*":
               case "cha":
               case "skills":
               case "goto":
               case "home":
               case "music":
               case "music*":
               case "rumor":
               case "rumor*":
               case "to":
               case "ldj":
               case "ldj*":               
               case "du":
               case "read":
               case "ask":
               case "tell":
               case "reply":
               case "exercise": 
               case "lian":
               case "tuna":       
               case "quit":
               case "dazuo" : 
               case "practice":
               case "es":
               case "es*":               
               case "bidd":
               case "bidd*":               
  write(HIW"������רΪ������ҷ�˼֮�õĻڹ���\n"NOR);
  write(HBRED"һ��ħ��������������书�ͷ���! \n"NOR);
  write(HBRED"�������ħ��������ʲô���ɲ�����! \n"NOR);
  write(HBRED"��ڰ�! \n"NOR);
                       return 1;
      }
      return 0;
}

int do_check(object ob)
{
 
        if(time()-(int)ob->query("block_time") < 24000)
        {
		call_out("do_check",1,ob);
        	return 1;
        }
        else
        ob->move("/d/city/kedian");
        ob->save();
        return 1;
}        
