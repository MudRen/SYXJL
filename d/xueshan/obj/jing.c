// �����ľ�

inherit ITEM;

void create()
{
        set_name( "�����ľ�", ({ "jing" , "shu", "book" }));
        set_weight(200);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ľ�,�����ŷ�ѧ��Ҫּ��\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "mizong-xinfa",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost": 30+random(20),// jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    50,     // the maximum level you can learn
                ]) );
        }
}

