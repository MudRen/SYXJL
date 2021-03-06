//  robot-judge.c
//  By Jpei  Aug 1997

inherit NPC;

int do_answer(string arg);
int ask_judge();
int ask_rejudge();

string *test = ({ "日", "月", "水", "火", "木", "金", "土", "阴", "阳", "机", "器", "人"});

void create()
{
	set_name("机器人法官", ({ "jiqiren faguan", "jiqiren", "faguan", "robot judge", "robot", "judge" }));
	set("shen_type", 0);

	set("gender", "机器");
	set("age", 20);
	set("long", "这是一个专门审判机器人的法官。\n");
	set_skill("dodge", 1000);
	set("max_qi", 10000);
	set("qi", 10000);
	set("max_jing", 10000);
	set("jing", 10000);

	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name": "你还有这闲功夫啊？",
		"rumors": "听说你是个机器人，嘿嘿，我这关可是铁面无情呀。",
		"here": "这里是法庭，没事不准喧哗！",
		"寒雨": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"jpei": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"审判": (: ask_judge :),
		"审讯": (: ask_judge :),
		"上诉": (: ask_rejudge :),
	]) );
	
	setup();
}

void init()
{
	object ob = this_player();
    if (userp(ob) && !wiz_level(ob)) {
	command("chat " + ob->name(1) + "现在接受聆讯，任何时候皆可以要求审判。");
            }
	add_action("do_answer", "answer");
	add_action("do_answer", "huida");
	ob->set_temp("robot_judge", -1);
	call_out("ok", 30, ob);
}

void ok(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	ob->delete_temp("robot_judge");
	tell_object(ob, "法官抬头看了看你，示意你可以开始了。\n");
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现机器人法官根本不理会作战请求。\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say("机器人法官狞笑着说：我是无敌不死版！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

int do_answer(string arg)
{
	object ob = this_player();

	if (!arg) return 0;
	if (ob->query_temp("robot_judge") != 1) return 0;
	if (arg[0..1] == ob->query_temp("key0") && arg[2..3] == ob->query_temp("key1") && arg[4..5] == ob->query_temp("key2")) {
		tell_object(ob, "机器人法官点了点头，说道：OK，你可以走了。\n");
		command("chat 本庭现在宣判：" + ob->name(1) + "被控机器人一案，因控方证据不足，判" + ob->name(1) + "无罪，当庭释放。");
		ob->delete_temp("robot_judge");
		if (ob->query("enter_wuguan")) ob->move("/d/wuguan/dayuan");
		else ob->move("/d/city/kedian");
	}
	else {
		tell_object(ob, "机器人法官叹了口气道：这么简单都答不对？又是一个机器人！\n");
		command("chat 本庭现在宣判：" + ob->name(1) + "，" + ob->query("gender") + "，" + chinese_number(ob->query("age")) + "岁，触犯机器人条例第十七条，判行政拘留，如有不服可以上诉。");
		ob->set_temp("robot_judge", 2);
	}
	return 1;
}

void test_robot(object ob)
{
	int temp, dir;
	string tempstr;

	tell_object(ob, "机器人法官敲了敲桌子，说道：“机器人审判开始，请回答一个小问题。”\n");
	ob->set_temp("robot_judge", 1);
	temp = sizeof(test);
	ob->set_temp("key0", test[random(temp)]);
	ob->set_temp("key1", test[random(temp)]);
	ob->set_temp("key2", test[random(temp)]);
	temp = random(3);
	tempstr = "机器人法官问道：如果第" + chinese_number(temp + 1) + "个字是" + ob->query_temp("key" + temp);
	if (dir = random(2)) {
		temp++;
		if (temp == 3) temp = 0;
	}
	else {
		temp--;
		if (temp == -1) temp = 2;
	}
	tempstr += "，第" + chinese_number(temp + 1) + "个字是" + ob->query_temp("key" + temp);
	if (dir) {
		temp++;
		if (temp == 3) temp = 0;
	}
	else {
		temp--;
		if (temp == -1) temp = 2;
	}
	tempstr += "，第" + chinese_number(temp + 1) + "个字是" + ob->query_temp("key" + temp) + "，那么连在一起是什么？\n";
	tell_object(ob, tempstr);
	tell_object(ob, "请用answer命令回答。\n");
}

int ask_judge()
{
	object ob = this_player();
	int temp;

	if (temp = ob->query_temp("robot_judge")) {
		if (temp < 0) {
			write("请等一会，法官正在看你的资料。\n");
			return 1;
		}
		if (temp > 1) {
			write("你已经被审判过了，如有不服请上诉！\n");
			return 1;
		}
		else {
			write("你正在审判中！\n");
			return 1;
		}
	}
	command("chat 本庭现在审理" + ob->name(1) + "被控为机器人一案。");
	test_robot(ob);
	return 1;
}

int ask_rejudge()
{
	object ob = this_player();
	int temp;

	if (temp = ob->query_temp("robot_judge") < 2) {
		if (temp == 1) {
			write("你正在审判中！\n");
			return 1;
		}
		else {
			write("你还没被审判过，上诉什么？！\n");
			return 1;
		}
	}
	command("chat 本庭现在审理" + ob->name(1) + "被判为机器人一案的上诉案。");
	test_robot(ob);
	return 1;
}
