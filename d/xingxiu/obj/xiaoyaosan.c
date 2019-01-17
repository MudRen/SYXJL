// xiaoyaosan.c ��Ц��ңɢ
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��Ц��ңɢ", ({ "xiaoyao san", "san" }) );
        set("long", "�������Ц��ңɢ����������֮һ��\n" );
        set_weight(10);
        set("unit", "��");
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_take", "take");
        add_action("do_throw", "throw");
}

int do_take(string arg)
{
        object me = this_player();

        if (arg!="xiaoyao san" && arg!="san")
                return notify_fail("ʲô��");

//          if (objectp(present(arg, me)))
//                  return notify_fail("��Ц��ңɢ�����˺�Σ�գ������ϵ����������ðɡ�\n");

        if ((string)me->query("family/family_name") != "������") {
                message_vision("$N����һ����Ц��ңɢ��\n", me);
                me->apply_condition("xys_poison", 2);
                call_out("destruct_ob", 0, present(arg, environment(me)));
        }
        else {
                if(me->query_skill("huagong-dafa", 1) >= 70) {
                        message_vision("$N����һ�������������Ц��ңɢ�Ѿ����������С�\n", me);
                        call_out("move_ob", 0, present(arg, environment(me)), me);
                }
                else return notify_fail("��Ц��ңɢ��Ҳ��������ò��ͷ���ѽ����\n");
        }
        return 1;
}

int do_throw(string arg)
{
  string ob,who;
  object me = this_player();
  object target;
  object obj = this_object();
  
  if(!arg)  
       return notify_fail("�����ʽ:throw <����> at <����>\n");

  if(sscanf(arg,"%s at %s",ob,who)!=2)
       return notify_fail("�����ʽ:throw <����> at <����>\n");
 
  if( !obj = present(ob, me) )
       return notify_fail("����ʹ��ʲô��������\n");

  if( !objectp(target = present(who, environment(me))) || !target->is_character() )
       return notify_fail("�����˭ʹ����Ц��ңɢ��\n");

  if( target == me)
       return notify_fail("����ô�벻���\n");

  if( me->is_busy())
       return notify_fail("����æ����!\n");

//    if( environment(me)->query("no_fight")==1 )
//         return notify_fail("���ﲻ��ս��!\n");

  if( (me->query("family"))["family_name"] != "������" )
       return notify_fail("�㲻�������ɵ��ӣ�����ʹ����Ц��ңɢ��\n");

  if( me->query_skill("throwing", 1) < 110 )
       return notify_fail("�㻹����ѧѧ���������ɡ�\n");
  
  if( (int)me->query("neili",1) < 170 )
       return notify_fail("�����������������ʩ��Ц��ңɢ��\n");

  me->start_busy(3);

  tell_object(me, HIW "�㲻����ɫ������΢�Ǳ��������������ң��Цɢ��������" + target->name() + "��ȥ��\n" NOR );

  if( random( me->query_skill("huagong-dafa",1) + me->query_skill("beiming-zhenqi", 1) )*2/3 + me->query_skill("throwing",1)
    > random( target->query_skill("force", 1) ) + target->query_skill("dodge", 1) ) {
        if( (int)me->query("neili") > (int)target->query("neili") ) {
                target->apply_condition("xys_poison", 2);
                target->start_busy(1 + random(1));
        }
        else {
                me->apply_condition("xys_poison", 2);
                me->start_busy(2);
        }
  }

  me->add("neili", -120);
        
  call_out("destruct_ob", 0, obj);
  
  return 1;
}

void move_ob(object ob, object me)
{
        ob->move(me);
}

void destruct_ob(object ob)
{
        destruct(ob);
}

void owner_is_killed() { destruct(this_object()); }
