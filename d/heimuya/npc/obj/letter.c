// paper.c
inherit ITEM;

void create()
{
        set_name("��ֽ", ({"letter paper", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"��������ͨ����ֽ����������ӯӯд���������ţ�����д�ã�����\n"
"�������ʵʵ�ġ�\n");
                set("material", "paper");
        }
}

