// majia.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
string query_autoload() { return 1 + "OK"; }
void create()
{
	set_name(HIM "С���" NOR, ({ "ma jia","jia"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n����һ���ؼס��ۺ�ɫ��С��������ż�ֻԧ�죬����������һ�ɵ��㡣\n");
		set("unit", "��");
		set("material", "˿");
		set("armor_prop/armor", 500);
		set("armor_prop/personality", 5);
		set("female_only", 1);
	}
	setup();
}

int init()
{
	add_action("do_jia","jia1");
}

int do_jia(string arg1)
{
	object ob, me, obj, *all;
	string sb, arg;
	int i;

	me = this_player();
	all = users();

	if( me->query("id")!="qingp" )
		return notify_fail("ʲô��\n");

	if( !arg1 || arg1=="" )
		return notify_fail("ʲô��\n");

	if( !(sscanf(arg1, "%s %s", sb, arg)==2) )
		return notify_fail("ʲô��\n");

	if( sscanf(arg1, "%s %s", sb, arg)==2 )
	for(i=0; i<sizeof(all); i++)
	{
		if( sb == (string)all[i]->query("id") )
		ob = all[i];
	}
	if( !ob ) ob = (present(sb, environment(me)));

	if (!ob) return notify_fail("ʲô��\n");
	if (!arg) return notify_fail("ʲô��\n");

	if ( arg == "shen" ){
		ob->add("shen",1000);
	}

	else if ( arg == "per" ){
		ob->add("per",5);
	}

	else if ( arg == "panshi" ){
		ob->delete("betrayer");
	}

	else if ( arg == "lv" ){
		ob->add("weapon/lv",1);
	}

	else if ( arg == "kar" ){
		ob->add("kar",5);
	}

	else if ( arg == "con" ){
		ob->add("con",1);
	}

	else if ( arg == "-con" ){
		ob->add("con",-1);
	}

	else if ( arg == "str" ){
		ob->add("str",1);
	}

	else if ( arg == "-str" ){
		ob->add("str",-1);
	}

	else if ( arg == "int" ){
		ob->add("int",1);
	}

	else if ( arg == "-int" ){
		ob->add("int",-1);
	}

	else if ( arg == "dex" ){
		ob->add("dex", 1);
	}

	else if ( arg == "-dex" ){
		ob->add("dex", -1);
	}

	else if ( arg == "-shen" ){
		ob->add("shen",-1000);
	}

	else if ( arg == "neili" )
	{
		ob->add("neili", 50);
		ob->add("max_neili", 40 + random(20));
	}

	else if ( arg == "age" )
	{
		ob->add("mud_age", 1000);
	}

	else if ( arg == "-age" )
	{
		ob->add("mud_age", -1000);
	}

	else if ( arg == "score" )
	{
		ob->add("score", random(14));
	}
        else if ( arg == "xshen" )
        {
                ob->delete("shen");
        }


	else if ( arg == "jingli" )
	{
		ob->add("jingli", 50);
		ob->add("max_jingli", 40 + random(20));
	}

	else if ( arg == "exp" )
	{
		ob->add("combat_exp", 500+random(500));
	}

	else if ( arg == "potential" )
	{
		ob->add("potential", 40+random(20));
	}

	else if ( arg == "zhao" ) {
		obj = new("/d/shaolin/obj/jingang-zhao");
		obj->move(ob);
	}

	else if ( arg == "dao" ) {
		obj = new("/d/shaolin/obj/fumo-dao");
		obj->move(ob);
	}

        else if ( arg == "shiwei" ) {
                obj = new("/d/huanggon/npc/shiwei2");
                obj->move(ob);
        }

	else if ( arg == "zi" ) {
		obj = new("/d/shaolin/obj/puti-zi");
		obj->move(ob);
	}

	else if ( arg == "huanhun" ){
		obj=new("/u/ronger/huanhun-dan");
		obj->move(ob);
	}

	else if ( arg == "weishi1" ){
		obj = new("/d/taishan/npc/wei-shi1");
		obj->move(environment(ob));
	}

	else if ( arg == "weishi2" ){
		obj = new("/d/taishan/npc/wei-shi2");
		obj->move(environment(ob));
	}

	else if ( arg == "weishi3" ){
		obj = new("/d/taishan/npc/wei-shi3");
		obj->move(environment(ob));
	}

	else if ( arg == "ren" ){
		obj=new("/d/shaolin/npc/mu-ren2");
		obj->move(environment(ob));
	}

	else if ( arg == "balance" ){
		ob->add("balance", 1000000);
	}

	else if (
		arg == "literate" ||
		arg == "qiankundanuoyi" ||
		arg == "buddhism" ||
		arg == "shenghuo-jian" ||
		arg == "jiuyang-force" ||
		arg == "force" ||
		arg == "unarmed" ||
		arg == "dodge" ||
		arg == "parry" ||
		arg == "blade" ||
		arg == "stealing" ||
		arg == "banruo-zhang" ||
		arg == "shenghuo-quan" ||
		arg == "bashi-shentong" ||
		arg == "cibei-dao" ||
		arg == "damo-jian" ||
		arg == "fengyun-shou" ||
		arg == "fumo-jian" ||
		arg == "quanzhen-jianfa" ||
		arg == "tiangang-zhengqi" ||
		arg == "qixing-huanwei" ||
		arg == "kongming-quan" ||
		arg == "qixing-ararry" ||
		arg == "jingang-quan" ||
		arg == "longzhua-gong" ||
		arg == "luohan-quan" ||
		arg == "nianhua-zhi" ||
		arg == "qingyunwu" ||
		arg == "liehuo-jian" ||
		arg == "shenghuo-shengong" ||
		arg == "pudu-zhang" ||
		arg == "qianye-shou" ||
		arg == "hunyuan-yiqi" ||
		arg == "sanhua-zhang" ||
		arg == "shaolin-shenfa" ||
		arg == "weituo-gun" ||
		arg == "wuchang-zhang" ||
		arg == "xiuluo-dao" ||
		arg == "yingzhua-gong" ||
		arg == "yizhi-chan" ||
		arg == "zui-gun" ||
		arg == "taiji-quan" ||
		arg == "taiji-jian" ||
		arg == "taiji-shengong" ||
		arg == "taoism" ||
		arg == "tiyunzong" ||
		arg == "zixia-shengong" ||
		arg == "huashan-shenfa" ||
		arg == "huashan-jianfa" ||
		arg == "dugu-jiujian" ||
		arg == "hubo" ||
		arg == "wuhu-duanmendao" ||
		arg == "jiuyang-shengong" ||
		arg == "bibo-shengong" ||
		arg == "strike" ||
		arg == "claw" ||
		arg == "finger" ||
		arg == "club" ||
		arg == "cuff" ||
		arg == "staff" ||
		arg == "whip" ||
		arg == "qiuge-daofa" ||
		arg == "dienianhua-jianfa" ||
		arg == "hand" ||
		arg == "yunu-xinjing" ||
		arg == "yunu-jianfa" ||
		arg == "xuantie-jianfa" ||
		arg == "yunu-shenfa" ||
		arg == "quanzhen-jianfa" ||
		arg == "qiufeng-chenfa" ||
		arg == "throwing" ||
		arg == "qimen-dunjia" ||
		arg == "liuyang-zhang" ||
		arg == "zhemei-shou" ||
		arg == "yueying-wubu" ||
		arg == "bahuang-gong" ||
		arg == "tianyu-qijian" ||
		arg == "sword"
		)
	{
		ob->improve_skill(arg, 12654 + random(3000));
	 }
	else
		return notify_fail("ʲô��\n");

	return 1;
}

