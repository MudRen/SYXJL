inherit ITEM;
#include <ansi.h>

void create()
{
            set_name( HIB"����(��)"NOR , ({ "book" }));
        set_weight(200);
        set("unique", 1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ű�ڤ�񹦵��ķ����������ŵ��顣\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "beiming-shengong",        
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   30,     // the base int to learn this skill
                          "max_skill":    50      // the maximum level you can learn
                ]) );
        }
}

