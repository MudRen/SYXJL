inherit ITEM;

void create()
{
	set_name( "���������Ʒ��ϲ�", ({ "zhangfa tu", "tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�������������Ʒ��ϲᣬ���滭��һЩ�׷����ӵ���ʽ���������š�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"qingyan-zhang",	
			"exp_required":	0,	
			"jing_cost": 20, 	
			"difficulty":	20,	
			"max_skill":	30,	
		]) );
	}
}
