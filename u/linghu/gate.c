// create by five
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

һ���ɵ���̴ľ���������Ĵ��Ÿ߸����ض�������������
�������͸������䱦ʯ���������Ǵ��᳡��������������
��ǧ��������û�о��б�����ʱ�����˲����������ڡ�

LONG);

  set("exits", ([
        "south"   : __DIR__"north",
        "east"   : "/d/city/wumiao",
      ]));

  setup();
     "/clone/board/biwu_b"->foo();
}
void init()
{ object me;
  me=this_player();
  if (wizardp(me))
   { add_action("do_open","break");
     add_action("do_close","feng");
   }
}
int do_open(string arg)
{
  object me;
  string name;
  me=this_player();
  name=(string)me->query("name");

  if (!wizardp(me)) return notify_fail("�Բ�������Ҫ��ʦ���������ܿ���.\n");
  
  if(!arg ||arg!="here")
    return notify_fail("��Ҫ��������Ľ��?\n");

  environment(me)->set("break",1);
  message_vision(HIW "$N���һ�������䡱��类������!\n"NOR,me);
  return 1;
}

int do_close(string arg)
{
  object me;
  string name;
  me=this_player();
  name=(string)me->query("name");

  if (!wizardp(me)) return notify_fail("�Բ�������Ҫ��ʦ�����������趨.\n");
  
  if(!arg ||arg!="here")
    return notify_fail("��Ҫ����������?\n");
  if(!environment(me)->query("break"))
    return notify_fail("�����Ѿ����˽����!\n");

  environment(me)->delete("break");
  message_vision( HIW "$N���������д�һ���׹�������γ���!\n"NOR,me);
  return 1;
}
int valid_leave (object who, string dir)
{
  if (wizardp(who))
    return ::valid_leave(who, dir);

  if ( dir == "south" && !environment(who)->query("break"))
    return notify_fail (HIY "�㷢����ǰһ����ڵ�סȥ·��\n" NOR);

  return ::valid_leave(who, dir);
}


