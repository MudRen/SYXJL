// sword_book.c ����Ҫ��

inherit ITEM;

void create()
{
        set_name("����Ҫ��", ({ "shu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����װ�飬������������Ļ����˸�ʽ������С�ˡ�\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "sword",        // name of the skill
                        "exp_required": 1000,   // minimum combat experience required
                        "jing_cost":    30,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    60      // the maximum level you can learn
                ]) );
        }
}
