inherit ITEM;

void create()
{
        set_name("¶À¹Â¾Å½£", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±¾");
                set("long", "ÕâÊÇÁîºü³åÐ´µÄÒ»±¾¶À¹Â¾Å½£ÃØ¼®¡£\n");
                set("material", "paper");
                set("skill", ([
                        "name": "dugu-jiujian", // name of the skill
                        "exp_required": 100000,      // minimum combat experience required
                        "jing_cost":    50,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    150     // the maximum level you can learn
                ]) );
        }
}
