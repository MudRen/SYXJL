inherit ROOM;
#include <ansi.h>

void create()
{
   set("short", HIC"����"NOR);
   set("long", @LONG

�����ǹ�ѺΥ�������������õģ��㵽�����
����ȥ��ϣ���ͺ�С�ˡ����ܺںڵģ���ʲô
Ҳ�����壬��Լ����Զ����������޺�����
LONG
   );
   
   set("valid_startroom", 1);

   setup();
   
}

void init()
{   
   if (!wizardp(this_player())) {
          this_player()->set("startroom","/d/wizard/punish");
     this_player()->save();
     add_action("block_cmd","",1);      
   }
   call_out("hehe", 2, this_player());
}

int block_cmd()
{
        string verb = query_verb();
   
        if (verb=="say") return 0; 
   if (verb=="help") return 0;
   if (verb=="look") return 0;
   return 1;
}

void hehe()
{
        tell_room(environment(this_player()), "\n"+
     "�����������˫�ֲ����۾����ڶ����㿴��\n"+
     "�㿴�˿�����ǽ�Ϲҵ��̾ߣ��������˸���ս��\n"+
     "������ԼԼ����Զ������һ����ҵĽ�����\n"+
     "һ����������������վ�������ֵ����ˣ���������һ�������ò��Ǻ��㡣\n"+
     "������ԼԼ��������˵�������������������\n"+
     "������ԼԼ����Զ���и����ں�������������й���������ˣ���\n");
        return;
}
