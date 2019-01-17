inherit ITEM;
#include <ansi.h>

void init();
int do_read(string arg);

void create()
{
        set_name(HIG"���������顽"NOR, ({"wumu yishu","yishu","book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
   set("long",
   "����һ�����������µ��о��ñ����ĵã����������Ľ�������������ʿ��������ĺö�����\n");
        set("material", "paper");
        set("value", 500);   
        }
}

void init()
{
  add_action("do_read", "yanjiu");
}

int do_read(string arg)
{
   object me;
   int jing_cost, gain;
   
   me=this_player();

       if( !this_object()->id(arg) ) return 0;
       if( me->is_busy() )
             return notify_fail("������æ���أ�û�տ����顣\n");
      if( me->is_fighting() )
             return notify_fail("��û�и�����ʱ����ʱ�䷭����...\n");
   
   if( (int)me->query_skill("literate",1)<200 )
     return notify_fail("��������������ҡͷ���Եغ��˼��䣬����û������ɶ��˼��\n");
   if( (int)me->query_skill("literate",1)>250 )
     return notify_fail("�������ַ����Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");
   if( (int)me->query_skill("shen",1)<20000 )
     return notify_fail("����������������˼��䣬����û����Ϊʲô������ʿҪ���Ȿ��������µ��顣\n");

   jing_cost = 10 + (50-(int)me->query("int"));
   if( (int)me->query("jing")<jing_cost )
     return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");   
   me->receive_damage("jing", jing_cost);

   gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")+1;
   me->improve_skill("literate", gain);

       message_vision("$N��ϸѧϰ��Ħ�������������ص����ݣ��ƺ��е�����\n", me);
     
   return 1;
}
