// kaoya.c ��Ѽ

inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name("�ϵü�", ({"kendeji"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�����벻���ϰ�����\n");
          set("unit", "��");
           set("value", 0);
           set("food_remaining", 10000000);
         set("food_supply", 10000000);
        }
}

