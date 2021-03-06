// by Yu Jue 98/7

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object *enemy;
        int i,j;
        float h, k, o, p;
        object weapon = me->query_temp("weapon");

       if ( me->query("gender")!="女性") return notify_fail("你使用的技能不对。\n");
        if( !target || target == me) return notify_fail("你要和谁合壁？\n");

        if (me->query_temp("hebi")) return notify_fail("你已经在合壁了。\n");
        if (target->query_temp("hebi")) return notify_fail("你已经在合壁了。\n");
        if (me->query("jingli") < 200) return notify_fail("你的精力不够了。\n");
        if (target->query("jingli") < 200) return notify_fail("对方的精力不够了。\n");
        if(!me->is_fighting()) return notify_fail("合壁只能在战斗中使用。\n");
        if (me->is_fighting(target)) return notify_fail("你正在和对方打架，合壁干什么？\n");

        if( (int)me->query_skill("yunu-jianfa", 1) < 60 )
                return notify_fail("你的玉女剑法不够娴熟，不会使用合壁。\n");
        if( (int)me->query_skill("yunu-xinjing", 1) < 80 )
                return notify_fail("你的玉女素心功未到火候，如何会有合壁的威力？\n");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunu-jianfa")
                return notify_fail("你现在无法合壁。\n");
        
        enemy = me->query_enemy();
        i = sizeof(enemy);
        while (i--) if (target->is_fighting(enemy[i])) break;
        if (i<0) return notify_fail(target->name()+"并没有和你的对手在交战。\n");

        if( (int)target->query_skill("quanzhen-jianfa", 1) < 60 )
                return notify_fail("对方的全真剑法不够娴熟，不会使用合壁。\n");
         if( (int)target->query_skill("yunu-xinjing", 1) < 80 )
                  return notify_fail("对方的玉女素心功不够纯熟，无法发挥合壁威力。\n");
        weapon = target->query_temp("weapon");
        if (target->is_busy() || !weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("对方现在无法合壁。\n");
       
        message_vision(HIY "\n$N和$n双剑一交，威力陡增。\n" NOR, me, target);
        me->set_temp("hebi", 1);
        target->set_temp("hebi", 1);
        me->receive_damage("jingli", 100);
        target->receive_damage("jingli", 100);
        me->start_busy(1);
        target->start_busy(1);
          i = (int)me->query_skill("yunu-jianfa", 1);
          j =(int)target->query_skill("quanzhen-jianfa", 1);
          h = (int)(me->query_skill("yunu-xinjing", 1) /80);
          k = (int)(target->query_skill("yunu-xinjing", 1) /80);
          o = me->query("combat_exp", 1);
        p = target->query("combat_exp", 1);
        me->add_temp("apply/attack", i/5);
        me->add_temp("apply/dodge", i/5);
        target->add_temp("apply/attack", j/5);
        target->add_temp("apply/dodge", j/5);
        if (me->query("marry/id") == target->querry("id"))
  {
           me->set_skill("yunu-jianfa", i*h);
           target->set_skill("quanzhen-jianfa", j*k);
         me->set("combat_exp", o*h);
         target->set_skill("combat_exp", p*k);
          }
        call_out("hebi", 1, me, target, environment(me), i, j, h, k, o, p,(i+j)/25);
        return 1;
}

void hebi()
{
        object me, target, env;
        int i, j, o, p,count;
        object weapon;

        if (!me && !target) return;
        if (!me && target) {
                tell_room(env, HIY "\n合壁自动瓦解。\n" NOR);
                target->add_temp("apply/attack", -j/5);
                target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                   target->set_skill("quanzhen-jianfa", j);
                 target->set("combat_exp", p);
                return;
        }
        if (me && !target) {
                tell_room(env, HIY "\n合壁自动瓦解。\n" NOR);
                 me->add_temp("apply/attack", -i/5);
               me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                  me->set_skill("yunu-jianfa", i);
                me->set("combat_exp", o);
                return;
        }

        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunu-jianfa") {
                tell_room(env, HIY "合壁自动瓦解。\n" NOR);
                me->add_temp("apply/attack", -i/5);
               me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunu-jianfa", i);
                me->set("combat_exp", o);
                target->add_temp("apply/attack", -j/5);
               target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                  target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);
                return;
        }

        weapon = target->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "quanzhen-jianfa") {
                tell_room(env, HIY "合壁自动瓦解。\n" NOR);
                me->add_temp("apply/attack", -i/5);
                me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunu-jianfa", i);
                me->set("combat_exp", o);
                target->add_temp("apply/attack", -j/5);
                target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);

                return;
        }

        if (environment(me) != env || environment(target) != env) {
                tell_room(env, HIY "合壁自动瓦解。\n" NOR);
                me->add_temp("apply/attack", -i/5);
               me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunu-jianfa", i);
                me->set("combat_exp", o);
                 target->add_temp("apply/attack", -j/5);
               target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);

                return;
        }
        if (!me->is_fighting() || !target->is_fighting() || count < 1) {
                message_vision(HIY "\n$N和$n相视一笑，各自收招。\n" NOR, me, target);
                me->add_temp("apply/attack", -i/5);
                me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunu-jianfa", i);
                me->set("combat_exp", o);
                 target->add_temp("apply/attack", -j/5);
               target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);
                return;
        }
        call_out("hebi", 1, me, target, env, i, j, o, p, count - 1);
}

