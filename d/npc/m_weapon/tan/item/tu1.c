//tu1.c
inherit ITEM;
void create()
{
        set_name( "tu1", ({ "tu1"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һС����ƾɵ���Ƥƴ�����ĵ�ͼ��\n");
                set("value", 0);
                set("material", "bamboo");
              }
}

