#include <ansi.h>
#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name(HIY"十三龙象袈裟"NOR, ({ "longxiang jiasha" }) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "雪山至宝龙象袈裟，质地轻柔，却刀枪不入。\n");
                set("unit", "件");
                set("unique", 1);
                set("longxiangli",1);
         set("wear_msg", HIY "只听「哗」的一声，$N展开一件金光闪闪的袈裟披在身上。瞬时间日月为之失色，瑞气千条，祥云朵朵，一派庄严气象。\n" NOR);
               set("remove_msg", HIY "$N将$n"HIY"从身上脱了下来，折叠成小小的一团。\n" NOR);
                set("armor_prop/armor", 500);
        }
        setup();
}

void init()
{
        add_action("zhu", "zhu");
        add_action("zhu", "guan");
}
int do_zhu(string arg)
{
        int lxl;
        object me,target;
        lxl=this_object()->query("longxiangli");
        me = this_player();
        if (!arg) 
                  return notify_fail("你要干什么？\n");
       if (lxl>14) return notify_fail("龙象袈裟只承受得道十三道龙象力!\n"); 
        if (arg=="longxiang jiasha")
{
                tell_object(me,"你摩拳擦掌,催运内力,准备将龙象袈裟注入龙象之力!\n"); 
       {
message_vision(HIR"$N拿起龙象袈裟,将双掌紧贴其上,暗自猛催内力,在龙象袈裟上注入了第"+ chinese_number(lxl)+"道龙象之力!\n"NOR,me, target);
             this_object()->add("longxiangli",1);
     me->add("neili",-500);
       }
                  return 1;     
}
}
