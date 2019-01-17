// lianxindan.c ���ĵ�
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("���ĵ�", ({ "lianxin dan", "dan" }) );
	set("long", 
		"����һ���������С���裬�������������ۣ��ƺ������������֮���ƳɵĻ𵯡�\n" );
	set_weight(20);
	set("unit", "��");
	set("value", 10000);

	setup();
}

void init()
{
	add_action("do_throw", "throw");
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
 
  if( obj != present(ob, me) )
       return notify_fail("����ʹ��ʲô��������\n");

  if( !objectp(target = present(who, environment(me))) || !target->is_character() )
       return notify_fail("�����˭ʹ�����ĵ���\n");

  if( target == me)
       return notify_fail("����ô�벻���\n");

  if( me->is_busy())
       return notify_fail("����æ����!\n");

  if( environment(me)->query("no_fight")==1 )
       return notify_fail("���ﲻ��ս��!\n");

  if( (me->query("family"))["family_name"] != "������" )
       return notify_fail("�㲻�������ɵ��ӣ�����ʹ�����ĵ�\n");

  if( me->query_skill("throwing", 1) < 50 )
       return notify_fail("�㻹����ѧѧ���������ɡ�\n");
  
  if( (int)me->query("neili",1) < 15 )
       return notify_fail("�����������������ʩ���ĵ���\n");

  me->start_busy(2);

  if( random( me->query_skill("beiming-zhenqi",1) )/2 + me->query_skill("throwing",1)
  > random( target->query_skill("dodge",1) )*2 )
  {
	message_vision(HIG "$NͻȻ����һ������зɳ�����"
		+ HIC "���װ�" + HIG "�Ļ𻨣�������ֻ��Ө���˳�\n����$n�����ϡ�\n"
		+ HIR "�漴�������͵����졣\n"NOR, me, target);


	target->receive_damage("qi",me->query("jiali") + me->query_skill("throwing", 1) );
	target->receive_wound("qi",15 + random(10));
	target->receive_wound("jing", 10);
	target->start_busy(2 + random(4));
	
        COMBAT_D->report_status(target, 1);
  }
  else {
	message_vision( HIG "$NͻȻ����һ������зɳ�����"
		+ HIC "���װ�" + HIG "�Ļ𻨣�������ֻ��Ө����$n�˳���\n"NOR, me, target);
	message_vision(HIY "$Nһ������"+(string)obj->query("name")+"���˹�ȥ��\n" NOR,target);
	write((string)obj->query("name")+"���͡�һ����֪���ɵ�����ȥ�ˡ�\n");
	me->start_busy(1);
  }
  
  me->add("neili", -10);
  if( !target->is_killing(me) ) target->kill_ob(me);
  
  destruct(obj);
  
  return 1;
}