// designed by Yu Jue

#include <ansi.h>

inherit NPC;

string key="";
string ans=" ";
object ob;
int timer = 0;
string str = "黑暗杀手说道：请用 answer 回答，下面这行英文中出现了正好";

void create()
{
    set_name("黑暗杀手", ({ "blade runner", "runner" }));

    set("gender", "机器");
    set("age", 20);
    set_temp("apply/long", 
        ({ "这是一个专门追缉机器人的机器探员。\n"
           "如果利用机器自动回答问题，档案将被无条件删除。\n"
           "如果回答正确，可以获得五十点经验的补偿。\n"})
    );
    set_skill("dodge", 1000);
    set("max_qi", 10000);
    set("qi", 10000);
    set("max_jing", 10000);
    set("jing", 10000);

    set("combat_exp", 5000000);
	
    set("inquiry", ([
        "name": "你还有这闲功夫啊？专心回答问题吧！",
        "rumors": "听说有机器人混入本MUD，嘿嘿，我可是火眼金睛呀。",
    ]) );
        set("attitude", "friendly");

    setup();
}

void question()
{
    if (!ob) return;
    tell_object(ob, HIW+HIW+str);
    tell_object(ob, key+NOR);
}

void init()
{
    if (this_player() == ob) {
        remove_call_out("question",);
        call_out("question", 1);
        add_action("do_answer", ({ "answer", "da", "huida" }));
        add_action("wait", ({ "quit", "learn", "xue", "study", "du", "sleep", "practice", "lian" }));
    }
}

int wait()
{
	write("对不起，请先回答问题。\n");
	return 1;
}

void kill_ob(object ob)
{
    ob->remove_killer(this_object());
    remove_killer(ob);
    message_vision("$N沮丧地发现黑暗杀手根本不理会作战请求。\n", ob);
}

void unconcious()
{
    reincarnate();
    set("eff_qi", query("max_qi"));
    set("qi", query("max_qi"));
    set("eff_jing", query("max_jing"));
    set("jing", query("max_jing"));
    set("jingli", query("eff_jingli"));
    say("黑暗杀手狞笑着说：我是无敌不死版！\n");
    command("hehe");
}

void die()
{
    unconcious();
}

int do_answer(string arg)
{
    object me = this_object();
    object obj = this_player();

    if (obj != ob) return 0;
    if (!arg || strlen(arg) > 1) return notify_fail("答案是一个字母，再仔细想想。\n");
    if (arg==ans) {
        message_vision("$N点了点头，说道：OK，$n继续忙吧。\n", me, ob);
        message_vision("$N突然消失不见了。\n", me);
        ob->add("combat_exp", 50);
        tell_object(ob, BLINK "你增加了五十点的经验。\n" NOR);
       command("rumor "+ob->short(1)+"通过了机器人抽查。");        
    } else {
        message_vision("$N叹了口气道："+arg+"？"+ans+"才对，这么简单都答不出？去法庭接受聆讯吧！\n", me);
        message_vision("$N把$n带去了法庭。\n", me, ob);
        ob->move("/d/wizard/robot_court");
    }
    destruct(this_object());
    return 1;
}

void test4()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer--;
        if (timer > 0) {
            tell_object(ob, "黑暗杀手警告你：你还有" + chinese_number(timer) + "秒钟的考虑时间。\n");
            call_out("test4", 1);
        } else {
            tell_object(ob, "黑暗杀手叹了口气道：一点反应都没有，又是一个机器人嫌犯，去法庭接受聆讯吧！\n");
            message_vision("$N把$n带去了法庭。\n", me, ob);
            ob->move("/d/wizard/robot_court");
            destruct(me);
        }
    } else destruct(me);
}

void test3()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer -= 10;
        tell_object(ob, "黑暗杀手警告你：你还有" + chinese_number(timer) + "秒钟的考虑时间。\n");
        call_out("question", 1);
        if (timer > 10) call_out("test3", 10);
        else call_out("test4", 1);
    } else destruct(me);
}

void test2()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer -= 30;
        tell_object(ob, "黑暗杀手警告你：你还有" + chinese_number(timer) + "秒钟的考虑时间。\n");
        call_out("question", 1);
        if (timer > 60) call_out("test2", 30);
        else call_out("test3", 10);
    } else destruct(me);
}

void test1()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer -= 60;
        tell_object(ob, "黑暗杀手警告你：你还有" + chinese_number(timer / 60) + "分钟的考虑时间。\n");
        call_out("question", 1);
        if (timer > 120) call_out("test1", 60);
        else call_out("test2", 30);
    } else destruct(me);
}

void test_robot(object obj)
{
    int len, temp, t1, t2, t3;
    object me = this_object();

    ob = obj;
    if (environment(ob)) {
        me->move(environment(ob), 1);
        message_vision("$N忽然出现在$n面前！\n", me, ob);
        set_leader(ob);
        tell_object(ob, "黑暗杀手略带歉意地说：“机器人稽查，例行公事，请回答一个小问题。”\n");
        temp = len = random(5)*2+7;
        t1 = random(26);
        while (temp--) {
            do t2 = random(26); while (t2==t1);
            key += "a";
            key[<1] += t2;
        }
        t1 += 'a';
        ans[0] = t1;
        temp = random(len/2) + len/2 + 1;
        str += chinese_number(temp)+"次的字母是？\n";
        while (temp--) {
            do t3 = random(len); while (key[t3]==t1);
            key[t3] = t1;
        }
        key += "\n";
        timer = 180;
        call_out("test1", 60);
    } else destruct(me);
}

void test_player(string player)
{
    object ob = find_player(player);

    if (ob && interactive(ob))
        test_robot(ob);
}
