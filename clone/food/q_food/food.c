inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���˭������÷", ({"food"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������˫ζ���ޱȵ����ˡ�\n");
                set("unit", "��");
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
