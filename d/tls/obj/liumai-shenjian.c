inherit ITEM;

void create()
{
	set_name( "��������", ({ "pu", "jian pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "\n��������ѧϰ�����񽣵�ͼ�ס�\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"liumai-shenjian",	
			"exp_required":	1000000,	
			"jing_cost": 20+random(20), 	
			"difficulty":	40,	
			"max_skill":	250,	
		]) );
		set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�����������ܸ��ˡ�\n");
	}
}
