// yangrou.c ����
// by QingP

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"yang rou", "rou"}));
        set_weight(700);
        set("long", "һ�����ʵ����⡣\n");
        set("unit", "��");
        set("value", 3000);
        set("food_remaining", 7);
        set("food_supply", 200);
}