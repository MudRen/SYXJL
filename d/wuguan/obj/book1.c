// force-book.c

inherit ITEM;

string* titles = ({
                 "ȭ������",
});

void create()
{
                  set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
                  set_weight(200);
                  set("unique", 1); 
                  if( clonep() )
                                         set_default_object(__FILE__);
                  else {
                  set("unit", "��");
                  set("long", "����һ����������ȭ���ĵ����Ž̡̳�\n");
                  set("value", 500);
                  set("material", "paper");
                  set("skill", ([
                   "name": "cuff",     // name of the skill
                  "exp_required": 1000,      // minimum combat experience required
                  "jing_cost":    15,     // jing cost every time study this
                  "difficulty":   20,     // the base int to learn this skill
                  "max_skill":    31      // the maximum level you learn
                                         ]) );
                  }
}

