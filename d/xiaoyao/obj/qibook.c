//qibook.c ����

inherit ITEM;

void create()
{
        set_name("����", ({ "qi pu", "pu" }));
        set_weight(600); 
        set("unique", 1);        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ң�ɵ����ס�\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "literate",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    30,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                 "max_skill": 31,
                ]) );
        }
 
}

