inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Сţ����", ({"yao zi"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ѫ����ʵ�Сţ���ӡ�\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
