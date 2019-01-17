// dodge_book.c 天南秘籍

inherit ITEM;

void create()
{
        set_name("天南秘籍", ({ "shu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "册");
                set("long", "这是一本线装书，里面密密麻麻画了许多小人。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "tiannan-bufa", // name of the skill
                        "exp_required": 0,   // minimum combat experience required
                        "jing_cost":    25,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    100,    // the maximum level you can learn
                ]) );
        }
}
