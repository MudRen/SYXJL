// linzhennan.c ��ƽ֮
// modified by aeolus /12/27/2000
#include <ansi.h>
string do_quest();
inherit NPC;
void create()
{
        set_name("��ƽ֮", ({ "lin pingzhi", "lin", "pingzhi" }));
        set("gender", "����");
        set("title", "�����ھ��ٵ���");
        set("age", 20);
        set("long", "�����ǡ������ھ֡����ٵ��ң�����ƽ֮��\n");
        set("combat_exp", 10000);
        set("shen_type", 1);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);
        set_skill("force", 40);
        set("per",25);
        set_skill("sword", 40);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set("inquiry", ([
                "������լ" : "��ƽ֮˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
                "Զͼ��" : "��ƽ֮˵����Զͼ�����ҵ����游��\n",
                "��Զͼ" : "��ƽ֮����һ���������㡣\n",
                "����":(:do_quest:),
                "��": (:do_quest:),
        ]) );

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 10);

        setup();
	this_player()->carry_object(__DIR__"obj/changjian")->wield();
	this_player()->carry_object(__DIR__"obj/cloth")->wear();
}

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return time;
}

string do_quest()
{
        mapping target=([
        "tang nan":             "�����ϰ� ���",
        "ping yizhi":           "ҩ���ϰ� ƽһָ",
        "xu zhu":               "���չ������ˡ����ɡ�����",
        "ning zhongze":         "��ɽ�ɵ�ʮ�������� ������",
        "yu lianzhou":          "�䵱�ɵڶ������ӡ��䵱������������",
        "song yuanqiao":        "�䵱�ɵڶ������ӡ��䵱��������Զ��",
        "li lishi":             "������",
        "guan anji":            "����ϰ塸�ط��ӡ��ذ���",
        "lazhang huofo":        "��� ���»��",
        "jia laoliu":           "�����ϰ� ������",
        "ouyang feng":          "�϶��������ŷ����",
        "ding chunqiu":         "�����ɿ�ɽ��ʦ�������Ϲ֡�������",
        "jiang baisheng":       "����ʤ",
        "wei yixiao":           "������������ ΤһЦ",
        "ouye zi":              "�����ɿ�ɽ��ʦ�����Ľ�����ŷұ��",
        "ban shuxian":          "���������ŷ��� �����",
        "gu yanwu":             "������",
        "xiao meng":            "佻����ɵ��������ӡ���������",
        "xiao gang":            "佻����ɵ��������ӡ���������",
        "xiao xilou":           "佻����ɿ�ɽ��ʦ ����¥",
        "xiao ren":             "佻����ɵ��������ӡ�ӥ������",
        "gongye gan":           "��ϼׯׯ�� ��ұǬ",
        "deng baichuan":        "����ׯׯ�� �˰ٴ�",
        "feng boe":             "��˪ׯׯ����һ��硹�粨��",
        "bao butong":           "���ׯׯ������������������ͬ",
        "dao fengleng":         "ɱ��¥��ɽ��ʦ������Ц��������",
        "heibai zi":            "ɱ��¥�ͷ�ʹ�����桹�ڰ���",
        "xiao bai":             "ɱ��¥������ɱ�֡�Ц���졹С��",
        "xiao hei":             "ɱ��¥������ɱ�֡���˫����С��",
        "wenyue shitai":        "�����ɵ�������� ����ʦ̫",
        "wenxin shitai":        "�����ɵ�������� ����ʦ̫",
        ]);                     
        int ran, t, time;
        string *str;
        object ob, who;
        ob=this_object();
        if ( environment(this_object())->query("short")!="�����ھ�" )
                return "���ﲻ���ھ֣������»��ھ���˵�ɣ�";
        who = this_player();

        if (who->query("combat_exp") > 1000000)
                return("��λ"+RANK_D->query_respect(who)+"�Ĵ�����������˭�˲�֪���ĸ����������ٱξ֣��������
��\n");
        t = time()-who->query("biao_start");
        time = who->query("biao_time");
        if( t <= time )
                return  RANK_D->query_respect(who)+ "�ƺ�������������ɣ�\n";
        if( t > time && t < (time + 300) ) {
                if( ob = present("biao yin", who) ) destruct(ob);
                who->set("biao_failed",1);
        }
        if( t >= (time + 300) )
                who->delete("biao_failed");
        if(who->query("biao_failed") ) {
                command("hehe " + who->query("id"));
                return this_player()->name() + "����ӡ�÷��ڣ�����ʧ�����ҿ����ǲ����������ˡ�\n";
        }
        t = ( 20 + random(10) ) * 10;
        str=keys(target);
        ran = random(sizeof(str));
        ob = new("/clone/misc/biaoyin");
        ob->set("target", str[ran]);
        who->set("biao_start", time());
        who->set("biao_time", t);
        ob->move(who);
        return ("���������ã�����һ�������͵�" + target[str[ran]] + "�����\n"+"�㻹��" + chinese_time(t)+ "
��ʱ�䡣��춯��ɣ�\n");
}
