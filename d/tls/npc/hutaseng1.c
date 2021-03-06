inherit NPC;

void create()
{
	set_name("护塔僧", ({ "huta seng","seng"}) );
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 20);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 100);
	set_skill("kurong-changong", 100);
	set_skill("dodge", 100);
	set_skill("duanjia-shenfa", 100);
	set_skill("parry", 100);
	set_skill("finger", 100);
	set_skill("yiyang-zhi", 100);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "duanjia-shenfa");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");	
	set("inquiry" ,([
	"舍利子" : "“那是我寺之宝，原来供奉在塔顶，施主想上去看看吗？”\n",
	"上塔" : "“施主也该知道我们的清苦生活啦。难道不意思意思一下？”\n",
	]));

	setup();
}

int accept_object(object who, object ob)
{
        who = this_player();
        if (ob->query("money_id") && ob->value() >= 10000) 
		{
		message_vision("护塔僧悄悄地把$N带上了塔顶。\n", who);
               who->move("/d/tls/tading");
		return 1;
		}
	else
		{
		message_vision("护塔僧双手合十，朗声道：“阿弥陀佛！”\n");
		return 0;
		}
	return 0;
}
