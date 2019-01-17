//amber 1999.10.18
#include <ansi.h>
#include <weapon.h>
inherit THROWING;
// inherit COMBINED_ITEM;

void create()
{
        set_name(HIY"金蛇锥"NOR, ({ "jinshe zhui", "zhui" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "束");
                set("long", "金蛇锥是黄金所铸，灿烂生光。长约二寸八分，打成昂首吐舌的蛇
形，蛇舌尖端分成双叉，每一叉都是一个倒刺。\n");
                set("value", 0);
                set("base_value", 100);
                set("material", "steel");
                set("treasure",1); 
                set("base_unit", "枚");
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
       if (!arg) return notify_fail("你要对谁下手？\n");       
       ob = present(arg, environment(me)); 
       if (!ob) return notify_fail("找不到这个生物。\n");       i = ob->query_skill("dodge", 1) + ob->query_skill("parry", 1);
       i = random(i/2) - 10;
       damage = me->query_skill("throwing", 1)+me->query_str()*2;
       if( environment(me)->query("no_fight") )
                return notify_fail("你不能在这里动手。\n");
       if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
       if(me->query("neili") < 500)
                return notify_fail("你的内力不够用来动手。\n");
//       if(me->query("family/master_name") != "酷龙")
//             return notify_fail("你不是酷龙的弟子，怎么会有金蛇锥？\n"); 
       msg = HIY"\n$N袖袍一挥，一枚金蛇锥从袖底飞出直向$n的咽喉急射而去！\n\n"NOR;       
       me->start_busy(2);
       me->add("neili", -50);
       me->add("jing", -20);
       if(me->query_skill("throwing", 1) > i && random(ob->query("kar")) < 10 &&
          me->query("combat_exp") > (int)ob->query("combat_exp")/2 ) {
          msg += HIR"$n猛见金光一闪，急忙闪身躲避，但听一声惨叫，结果仍是被金蛇锥射中！\n"NOR;
//          ob->apply_condition("bee_poison", 70);
          ob->receive_wound("jing", damage/2);
          ob->receive_damage("qi", damage+random(damage));
          ob->receive_wound("qi", damage); 
//          p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
//          msg += "( $n"+eff_status_msg(p)+" )\n";
//          ob->set_temp("last_damage_from", "被"+me->name()+"杀");
          }
       else {
          msg +=HIY"$n急忙飞身后跃，只听嗤一声轻响，金蛇锥射在$p身前的泥土之中。\n"NOR;
          ob->add("jing", -20);
          }              
       message_vision(msg, me, ob);
       if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
       destruct(this_object());
       return 1; 
}
