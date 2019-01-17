//  羊皮书

inherit ITEM;

void create()
{
        set_name( "羊皮书", ({ "skin" , "shu", "book" }));
        set_weight(200);
        set("unique", 1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一张羊皮,上面画着舞剑的小人。\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "sword",        // name of the skill
                        "exp_required": 10000,      // minimum combat experience required
                        "jing_cost":  60,// jing cost every time study this
                        "difficulty":   42,     // the base int to learn this skill
                        "max_skill":    150,     // the maximum level you can learn
                ]) );
        }
}


