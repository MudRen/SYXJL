// force_book.c �ڹ��ķ�

inherit ITEM;

void create()
{
        set_name("�컨�ķ�", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����װ�飬�����ź컨����ڹ��ķ���\n");
                set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
         "exp_required": 15000,      // minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
                        "max_skill":    150      // the maximum level you can learn
		]) );
	}
}
