// bilinxing.c ������
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("������", ({ "bilin xing", "xing" }) );
	set("long", 
		"����һ������ɫ��С���裬�������������ۣ��ƺ������������֮���ƳɵĻ𵯡�\n" );
	set_weight(15);
	set("unit", "��");
	set("value", 30000);

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
       return notify_fail("�����˭ʹ�ñ����ǣ�\n");

  if( target == me)
       return notify_fail("����ô�벻���\n");

  if( me->is_busy())
       return notify_fail("����æ����!\n");

  if( environment(me)->query("no_fight")==1 )
       return notify_fail("���ﲻ��ս��!\n");

  if( (me->query("family"))["family_name"] != "������" )
       return notify_fail("�㲻�������ɵ��ӣ�����ʹ�ñ����ǡ�\n");

  if( me->query_skill("throwing", 1) < 70 )
       return notify_fail("�㻹����ѧѧ���������ɡ�\n");
  
  if( (int)me->query("neili",1) < 55 )
       return notify_fail("�����������������ʩ�����ǡ�\n");

  me->start_busy(3);

  message_vision( HIB "$N���ж�Ȼ�ų�������â����������һ����һ��"
	+ HIG "�����͵��׻�" + HIB "����$n���ϣ�\n"
	+ HIY "��������ǻ��졣\n" NOR, me, target);

  if( random( me->query_skill("beiming-zhenqi",1) )*2/3 + me->query_skill("throwing",1)
  > random( target->query_skill("dodge",1) ) )
  {
	message_vision( CYN "$p��Ҫ���ܣ�ȴ�������ü����͵�һ���죬$pȫ���·������˻�\n" NOR, me, target);

	target->receive_damage("qi",me->query("jiali") + me->query_skill("throwing", 1) * 3 / 2 );
	target->receive_wound("qi",40 + random(20));
	target->receive_wound("jing", 30);
	target->start_busy(4 + random(5));

        COMBAT_D->report_status(target, 1);
  }
  else {
	message_vision(HIY "$Nһ������"+(string)obj->query("name")+"���˹�ȥ��\n" NOR,target);
	write((string)obj->query("name")+"���͡�һ����֪���ɵ�����ȥ�ˡ�\n");
	me->start_busy(2);
  }
  
  me->add("neili", -40);
  if( !target->is_killing(me) ) target->kill_ob(me);
  
  destruct(obj);
  
  return 1;
}