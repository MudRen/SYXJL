//amber 1999.10.18
#include <ansi.h>
#include <weapon.h>
inherit THROWING;
// inherit COMBINED_ITEM;

void create()
{
        set_name(HIY"����׶"NOR, ({ "jinshe zhui", "zhui" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����׶�ǻƽ��������������⡣��Լ����˷֣���ɰ����������
�Σ������˷ֳ�˫�棬ÿһ�涼��һ�����̡�\n");
                set("value", 0);
                set("base_value", 100);
                set("material", "steel");
                set("treasure",1); 
                set("base_unit", "ö");
                set("base_weight", 10);              
    
              }
        set_amount(20);
        init_throwing(50);
        setup();
}

int init()
{
   add_action("do_throw", "she");
}

int do_throw(string arg)
{
       object me, ob;
       int i, damage;
       string msg;

       me = this_player();
       if (!arg) return notify_fail("��Ҫ��˭���֣�\n");       
       ob = present(arg, environment(me)); 
       if (!ob) return notify_fail("�Ҳ���������\n");       i = ob->query_skill("dodge", 1) + ob->query_skill("parry", 1);
       i = random(i/2) - 10;
       damage = me->query_skill("throwing", 1)+me->query_str()*2;
       if( environment(me)->query("no_fight") )
                return notify_fail("�㲻�������ﶯ�֡�\n");
       if(me->is_busy())
                return notify_fail("����æ���ء�\n");
       if(me->query("neili") < 500)
                return notify_fail("������������������֡�\n");
//       if(me->query("family/master_name") != "����")
//             return notify_fail("�㲻�ǿ����ĵ��ӣ���ô���н���׶��\n"); 
       msg = HIY"\n$N����һ�ӣ�һö����׶����׷ɳ�ֱ��$n���ʺ����ȥ��\n\n"NOR;       
       me->start_busy(2);
       me->add("neili", -50);
       me->add("jing", -20);
       if(me->query_skill("throwing", 1) > i && random(ob->query("kar")) < 10 &&
          me->query("combat_exp") > (int)ob->query("combat_exp")/2 ) {
          msg += HIR"$n�ͼ����һ������æ�����ܣ�����һ���ҽУ�������Ǳ�����׶���У�\n"NOR;
//          ob->apply_condition("bee_poison", 70);
          ob->receive_wound("jing", damage/2);
          ob->receive_damage("qi", damage+random(damage));
          ob->receive_wound("qi", damage); 
//          p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
//          msg += "( $n"+eff_status_msg(p)+" )\n";
//          ob->set_temp("last_damage_from", "��"+me->name()+"ɱ");
          }
       else {
          msg +=HIY"$n��æ�����Ծ��ֻ����һ�����죬����׶����$p��ǰ������֮�С�\n"NOR;
          ob->add("jing", -20);
          }              
       message_vision(msg, me, ob);
       if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
       destruct(this_object());
       return 1; 
}
