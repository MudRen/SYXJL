//tianlong-jing by mop because no need jing
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("һ���ؼ�", ({ "tianlong-jing", "shu" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����װ�飬������������Ļ��˲��ٴ������ŵ����ơ�\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name":       "finger",
   "exp_required" :100000,
                        "jing_cost":  60,
                        "difficulty": 20,
                        "max_skill":  100
                ]) );
        }
}

