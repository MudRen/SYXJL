#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        string *order = ({HIM "��ݮʥ��" NOR,YEL "�ɿ���ʥ��" NOR, HIY "����ʥ��" NOR, HIR "����ʥ��" NOR, HIG "ƻ��ʥ��" NOR});
        set_name( (order[random(5)]), ({ "shengdai" }) );
        set_weight(80);
        set("value", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������衣\n");
                set("unit", "��");
                set("food_remaining", 10);
                set("food_supply", 100);

        }
}
