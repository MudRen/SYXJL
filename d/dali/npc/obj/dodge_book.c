inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("天南秘籍", ({ "shu", "book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
             set("long",
         "这是一本线装书，里面密密麻麻画了许多小人。”\n"
        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "tiannan-bufa",
   "exp_required" :100000,
                        "jing_cost":  60,
                        "difficulty": 20,
                        "max_skill":  100
                ]) );
        }
}
