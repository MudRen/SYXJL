// designed by Yu Jue

#include <ansi.h>

inherit NPC;

string key="";
string ans=" ";
object ob;
int timer = 0;
string str = "�ڰ�ɱ��˵�������� answer �ش���������Ӣ���г���������";

void create()
{
    set_name("�ڰ�ɱ��", ({ "blade runner", "runner" }));

    set("gender", "����");
    set("age", 20);
    set_temp("apply/long", 
        ({ "����һ��ר��׷�������˵Ļ���̽Ա��\n"
           "������û����Զ��ش����⣬��������������ɾ����\n"
           "����ش���ȷ�����Ի����ʮ�㾭��Ĳ�����\n"})
    );
    set_skill("dodge", 1000);
    set("max_qi", 10000);
    set("qi", 10000);
    set("max_jing", 10000);
    set("jing", 10000);

    set("combat_exp", 5000000);
	
    set("inquiry", ([
        "name": "�㻹�����й��򰡣�ר�Ļش�����ɣ�",
        "rumors": "��˵�л����˻��뱾MUD���ٺ٣��ҿ��ǻ��۽�ѽ��",
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
	write("�Բ������Ȼش����⡣\n");
	return 1;
}

void kill_ob(object ob)
{
    ob->remove_killer(this_object());
    remove_killer(ob);
    message_vision("$N��ɥ�ط��ֺڰ�ɱ�ָ����������ս����\n", ob);
}

void unconcious()
{
    reincarnate();
    set("eff_qi", query("max_qi"));
    set("qi", query("max_qi"));
    set("eff_jing", query("max_jing"));
    set("jing", query("max_jing"));
    set("jingli", query("eff_jingli"));
    say("�ڰ�ɱ����Ц��˵�������޵в����棡\n");
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
    if (!arg || strlen(arg) > 1) return notify_fail("����һ����ĸ������ϸ���롣\n");
    if (arg==ans) {
        message_vision("$N���˵�ͷ��˵����OK��$n����æ�ɡ�\n", me, ob);
        message_vision("$NͻȻ��ʧ�����ˡ�\n", me);
        ob->add("combat_exp", 50);
        tell_object(ob, BLINK "����������ʮ��ľ��顣\n" NOR);
       command("rumor "+ob->short(1)+"ͨ���˻����˳�顣");        
    } else {
        message_vision("$N̾�˿�������"+arg+"��"+ans+"�Ŷԣ���ô�򵥶��𲻳���ȥ��ͥ������Ѷ�ɣ�\n", me);
        message_vision("$N��$n��ȥ�˷�ͥ��\n", me, ob);
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
            tell_object(ob, "�ڰ�ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n");
            call_out("test4", 1);
        } else {
            tell_object(ob, "�ڰ�ɱ��̾�˿�������һ�㷴Ӧ��û�У�����һ���������ӷ���ȥ��ͥ������Ѷ�ɣ�\n");
            message_vision("$N��$n��ȥ�˷�ͥ��\n", me, ob);
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
        tell_object(ob, "�ڰ�ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n");
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
        tell_object(ob, "�ڰ�ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n");
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
        tell_object(ob, "�ڰ�ɱ�־����㣺�㻹��" + chinese_number(timer / 60) + "���ӵĿ���ʱ�䡣\n");
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
        message_vision("$N��Ȼ������$n��ǰ��\n", me, ob);
        set_leader(ob);
        tell_object(ob, "�ڰ�ɱ���Դ�Ǹ���˵���������˻��飬���й��£���ش�һ��С���⡣��\n");
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
        str += chinese_number(temp)+"�ε���ĸ�ǣ�\n";
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
