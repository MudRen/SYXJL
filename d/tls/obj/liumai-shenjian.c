inherit ITEM;

void create()
{
	set_name( "六脉神剑谱", ({ "pu", "jian pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "\n这是用来学习六脉神剑的图谱。\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"liumai-shenjian",	
			"exp_required":	1000000,	
			"jing_cost": 20+random(20), 	
			"difficulty":	40,	
			"max_skill":	250,	
		]) );
		set("no_drop", "这样东西不能离开你。\n");
                set("no_give", "这样东西不能给人。\n");
	}
}
