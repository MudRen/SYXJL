inherit ITEM;

void create()
{
        set_name( "����" , ({ "daopu" }));
        set_weight(200);
        set("unique", 1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               set("long", "����һ�����ڻ����������顣\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "blade",        
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost": 30,        // jing cost every time study this
                        "difficulty":   30,     // the base int to learn this skill
                        "max_skill":    101,    // the maximum level you can learn
                ]) );
        }
}

