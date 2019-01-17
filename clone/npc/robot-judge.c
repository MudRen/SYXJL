//  robot-judge.c
//  By Jpei  Aug 1997

inherit NPC;

int do_answer(string arg);
int ask_judge();
int ask_rejudge();

string *test = ({ "��", "��", "ˮ", "��", "ľ", "��", "��", "��", "��", "��", "��", "��"});

void create()
{
	set_name("�����˷���", ({ "jiqiren faguan", "jiqiren", "faguan", "robot judge", "robot", "judge" }));
	set("shen_type", 0);

	set("gender", "����");
	set("age", 20);
	set("long", "����һ��ר�����л����˵ķ��١�\n");
	set_skill("dodge", 1000);
	set("max_qi", 10000);
	set("qi", 10000);
	set("max_jing", 10000);
	set("jing", 10000);

	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name": "�㻹�����й��򰡣�",
		"rumors": "��˵���Ǹ������ˣ��ٺ٣�����ؿ�����������ѽ��",
		"here": "�����Ƿ�ͥ��û�²�׼������",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"����": (: ask_judge :),
		"��Ѷ": (: ask_judge :),
		"����": (: ask_rejudge :),
	]) );
	
	setup();
}

void init()
{
	object ob = this_player();
    if (userp(ob) && !wiz_level(ob)) {
	command("chat " + ob->name(1) + "���ڽ�����Ѷ���κ�ʱ��Կ���Ҫ�����С�");
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
	tell_object(ob, "����̧ͷ���˿��㣬ʾ������Կ�ʼ�ˡ�\n");
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط��ֻ����˷��ٸ����������ս����\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say("�����˷�����Ц��˵�������޵в����棡\n");
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
		tell_object(ob, "�����˷��ٵ��˵�ͷ��˵����OK����������ˡ�\n");
		command("chat ��ͥ�������У�" + ob->name(1) + "���ػ�����һ������ط�֤�ݲ��㣬��" + ob->name(1) + "�����ͥ�ͷš�");
		ob->delete_temp("robot_judge");
		if (ob->query("enter_wuguan")) ob->move("/d/wuguan/dayuan");
		else ob->move("/d/city/kedian");
	}
	else {
		tell_object(ob, "�����˷���̾�˿���������ô�򵥶��𲻶ԣ�����һ�������ˣ�\n");
		command("chat ��ͥ�������У�" + ob->name(1) + "��" + ob->query("gender") + "��" + chinese_number(ob->query("age")) + "�꣬����������������ʮ���������������������в����������ߡ�");
		ob->set_temp("robot_judge", 2);
	}
	return 1;
}

void test_robot(object ob)
{
	int temp, dir;
	string tempstr;

	tell_object(ob, "�����˷������������ӣ�˵���������������п�ʼ����ش�һ��С���⡣��\n");
	ob->set_temp("robot_judge", 1);
	temp = sizeof(test);
	ob->set_temp("key0", test[random(temp)]);
	ob->set_temp("key1", test[random(temp)]);
	ob->set_temp("key2", test[random(temp)]);
	temp = random(3);
	tempstr = "�����˷����ʵ��������" + chinese_number(temp + 1) + "������" + ob->query_temp("key" + temp);
	if (dir = random(2)) {
		temp++;
		if (temp == 3) temp = 0;
	}
	else {
		temp--;
		if (temp == -1) temp = 2;
	}
	tempstr += "����" + chinese_number(temp + 1) + "������" + ob->query_temp("key" + temp);
	if (dir) {
		temp++;
		if (temp == 3) temp = 0;
	}
	else {
		temp--;
		if (temp == -1) temp = 2;
	}
	tempstr += "����" + chinese_number(temp + 1) + "������" + ob->query_temp("key" + temp) + "����ô����һ����ʲô��\n";
	tell_object(ob, tempstr);
	tell_object(ob, "����answer����ش�\n");
}

int ask_judge()
{
	object ob = this_player();
	int temp;

	if (temp = ob->query_temp("robot_judge")) {
		if (temp < 0) {
			write("���һ�ᣬ�������ڿ�������ϡ�\n");
			return 1;
		}
		if (temp > 1) {
			write("���Ѿ������й��ˣ����в��������ߣ�\n");
			return 1;
		}
		else {
			write("�����������У�\n");
			return 1;
		}
	}
	command("chat ��ͥ��������" + ob->name(1) + "����Ϊ������һ����");
	test_robot(ob);
	return 1;
}

int ask_rejudge()
{
	object ob = this_player();
	int temp;

	if (temp = ob->query_temp("robot_judge") < 2) {
		if (temp == 1) {
			write("�����������У�\n");
			return 1;
		}
		else {
			write("�㻹û�����й�������ʲô����\n");
			return 1;
		}
	}
	command("chat ��ͥ��������" + ob->name(1) + "����Ϊ������һ�������߰���");
	test_robot(ob);
	return 1;
}
