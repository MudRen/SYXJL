inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("�����ؼ�", ({ "shu", "book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             set("long",
         "����һ����װ�飬�����������黭�����С�ˡ���\n"
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
