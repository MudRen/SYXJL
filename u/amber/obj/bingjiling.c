#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        string *order = ({HIM "��ݮ" NOR,YEL "�ɿ���" NOR, HIY "����" NOR, HIR "����" NOR, HIG "ƻ��" NOR});
        set_name( (order[random(5)]), ({ "bingjiling" }) );
        set_weight(80);
        set("value", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ˮ��ʥ����\n");
                set("unit", "��");
                set("food_remaining", 10);
                set("food_supply", 100);

        }
}
