#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��ü����", ({"emei ling", "lingpai", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ü���ƣ��Ƕ�ü����ͬ�Լ�ʦ���Ȼ�����������
���\n");
                set("material", "steel");
                set("no_give_user", 1);
        }
}
