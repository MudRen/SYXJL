#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "���" NOR, ({ "shu jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר�������Ÿ����鱾�ļ��ӡ�
�����У�
       �������(book)��        
       ����ȭ��(quan pu)�� 
       �����(jian pu)�� 

\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("�����ʽ: get <�鱾����> from jia��\n");
  if (arg2!="jia")
     return notify_fail("�����ʽ: get <�鱾����> from jia��\n");
  if(present(arg1, me) || present(arg1, environment()))
     return notify_fail("�Ѿ������������ˡ�\n");
    switch (arg1){
          case "book": ob=new("/d/quanzhen/obj/force_book"); break;             
          case "quan pu": ob=new("/d/quanzhen/obj/unarmed_book"); break;   
          case "jian pu": ob=new("/d/quanzhen/obj/sword_book"); break;         
          default :
                 return notify_fail("û���Ȿ�顣\n");
          }
     if(ob) ob->move(me);
       message_vision("$N��������ó�һ��$n��\n",me, ob);  
       return 1;
}