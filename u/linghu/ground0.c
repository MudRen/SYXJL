// create by five
#include <ansi.h>
#include <ground.h>

object my_room = 0;
object this_room ()
{
  if (! my_room)
    my_room = load_object(__DIR__"ground");
  return my_room;
}

void announce (string str)
{
  message("channel:chat",HIC+"�������᡿��ƽ��(gong pingzi): "+str+NOR,users());
}

varargs void inform (object who, string str, string msg)
{
  string *msgs = ({
    "\n��ƽ�Ӷ�$N��ͷ˵�����ã�",
    "\n��ƽ����$Nһ�ݵ���������",
    "\n��ƽ�Ӷ�$N���ͷ���ǣ�",
    "\n��ƽ����æ��$N˵�����У�",
  });
  if (who)
  {
    if (msg)
      message_vision (msg+str,who);
    else
      message_vision (msgs[random(sizeof(msgs))]+str,who);
  }
  else
    tell_room (this_room(),"\n��ƽ�ӵ��ͷ��"+str);  
}

void broadcast_room (object room, string str)
{
  string prefix = HIG"�������ڡ�"NOR;
  string s1 = str, s2 = "";

  reset_eval_cost();

  s1 = replace_string (s1, "\n"+NOR, "");

  while (strsrch(s1,"\n\n") != -1)
    s1 = replace_string(s1,"\n\n","\n");

  if (s1[strlen(s1)-1]=='\n')
  {
    s1 = s1[0..strlen(s1)-2];
    s2 = "\n";
  }
  else s2="\n";
  if (strlen(s1) == 0)
    return;
  s1 = replace_string(s1,"\n","\n"+prefix)+s2;
  if (room)
  {
   tell_room (room, prefix+s1);
  }
}

void broadcast (string str)
{
  broadcast_room(load_object(__DIR__"east"),str);
  broadcast_room(load_object(__DIR__"west"),str);
  broadcast_room(load_object(__DIR__"south"),str);
  broadcast_room(load_object(__DIR__"north"),str);
}

string write_item (string str, int selected)
{
  if (selected)
    return "��"+str;
  else
    return "��"+str;
}

int do_report1();
int do_report2();
int do_report3();

int do_report ()
{
  int step = this_room()->query("match/step");

  switch (step)
  {
    case STEP_PREPARE: 
    {
      do_report1();
      break;
    }
    case STEP_FIGHT: 
    {
      do_report2();
      break;
    }
    case STEP_FINISH: 
    {
      do_report3();
      break;
    }
  }
  return 1;
}

void init0()
{
  add_action ("do_report","?");
  add_action ("do_report","what");
}


