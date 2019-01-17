inherit ITEM;

void create()
{
	set_name( "五罗清烟掌法上册", ({ "zhangfa tu", "tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是五罗清烟掌法上册，上面画着一些纷繁复杂的招式及修练法门。\n");
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
