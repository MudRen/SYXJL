// book_paper.c 论语

inherit ITEM;

void create()
{
        set_name("论语", ({ "lun yu", "yu" }));
        set_weight(600);
        set("unique", 1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本孔老夫子写的论语。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "literate",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                 "max_skill": 80,
                ]) );
        }
 
}

