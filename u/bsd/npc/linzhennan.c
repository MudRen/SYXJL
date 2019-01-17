// linzhennan.c ������
// modified by Jay 4/7/96
#include <ansi.h>
string do_quest();
inherit NPC;
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();
void create()
{
	set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
	set("gender", "����");
	set("title", "�����ھ�����ͷ");        set("age", 45);
	set("long", "�����ǡ������ھ֡�������ͷ���������ϡ�\n");
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);
	set_skill("force", 40);
	set("per",19);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set("inquiry", ([
		"������լ" : "������˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
		"�����ھ�" : (: ask_fuwei :),
		"Զͼ��" : (: ask_yuantu :),
		"��Զͼ" : "�����ϴ�ŭ��С������ôû��ò��ֱ���������䣡\n",
		"��а����" : (: ask_pixie:),
		"ͭǮ" : (: ask_tong:),
		"ͭ��" : (: ask_tong:),
		"����":(:do_quest:),
		"��": (:do_quest:),
	]) );
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_fuwei()
{
	say("��������ҫ��˵�������ּ��������ڣ�һ����������Զͼ�����괳�µ���������\n"
	"�����������ּҼҴ������ն����㺬��������н��յľ��棬��Ϊ����������\n"
	"һָ�Ĵ��ھ֡��������ᵽ�������ھ֡����֣�˭��Ҫ�����Ĵָ��˵һ������\n"
	"�ø����������磡��������������\n");
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int ask_yuantu()
{
	if ((int)this_player()->query_temp("marks/��1")) {
		say("�����Ͽ�һ���̶���˵����Զͼ�����ҵ��游�������ھ�����һ�ִ���ġ�����\n"
		"�游����ʮ��·��а���������ھ֣������Ǵ��ڵ��޵��֡���ʱ�׵���Ӣ�ۼ�\n"
		"��̫�����磬Ҳ��ȥ�����������յģ�����������������ʦ������������֮ʱ\n"
		"��������а���������˼��С�\n");
		this_player()->set_temp("marks/��2", 1);
		return 1;
	}
	else {
		say("������˵����Զͼ�����ҵ��游��\n");
		return 1;
	}
}

int ask_pixie()
{
	int p1, p2, p3, p4;
	if ((int)this_player()->query("passwd")) {
		say("�����ϲ��õ�˵�����Ҳ��Ƕ������������ҵĽ����������档\n");
	}
	else if ((int)this_player()->query_temp("marks/��2")) {
		say("������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ��ˣ����µĹ�������\n"
		"��֪��ϸ����ʵ���������档��\n");
		write("�����϶�һ�٣����Ŷ������˵������ȥ��ǰ�������Ҹ�����");
		p1=random(4)+1;
		p2=random(4)+1;
		p3=random(4)+1;
		p4=random(4)+1;
		this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
		write(CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
			"��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4));
		write("��\nͭǮ����һֱδ�����а��ء�\n");
	}
	else {
		message("vision", HIY "�����ϲ�Ȼ��ŭ���ȵ�����Ҳ���������ּҵı�а���ף����Ҹ���ƴ�ˣ�\n"
			NOR, environment(), this_object() );
		kill_ob(this_player());
	}
	this_player()->delete_temp("marks/��1");
	this_player()->delete_temp("marks/��2");
	return 1;
}

int ask_tong()
{
	int p, p1, p2, p3, p4;
	if (!(p=(int)this_player()->query("passwd"))) {
		say("������һ����Ц�����ӣ�˵����ô�쵽��һ���˵���ҪǮ��\n");
	}
	else {
		write("�����ϵ���˵������ȥ��ǰ�������Ҹ�����");
		p1=(int)p/1000;
		p2=(int)(p-p1*1000)/100;
		p3=(int)(p-p1*1000-p2*100)/10;
		p4=(int)(p-p1*1000-p2*100-p3*10);
		write(CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
			"��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4));
		write("��\nͭǮ����һֱδ�����а��ء�\n");
	}
	return 1;
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
/*	"tang nan":		"�����ϰ� ���",
	"ping yizhi":		"ҩ���ϰ� ƽһָ",
	"xu zhu":		"���չ������ˡ����ɡ�����",
	"ning zhongze":		"��ɽ�ɵ�ʮ�������� ������",
	"yu lianzhou":		"�䵱�ɵڶ������ӡ��䵱������������",
	"song yuanqiao":	"�䵱�ɵڶ������ӡ��䵱��������Զ��",
	"li lishi":		"������",
	"guan anji":		"����ϰ塸�ط��ӡ��ذ���",
	"lazhang huofo":	"��� ���»��",
	"jia laoliu":		"�����ϰ� ������",
	"ouyang feng":		"�϶��������ŷ����",
	"ding chunqiu":		"�����ɿ�ɽ��ʦ�������Ϲ֡�������",
	"jiang baisheng":	"����ʤ",
	"wei yixiao":		"������������ ΤһЦ",
	"ouye zi":		"�����ɿ�ɽ��ʦ�����Ľ�����ŷұ��",
	"ban shuxian":		"���������ŷ��� �����",
	"gu yanwu":		"������",
	"xiao meng":		"佻����ɵ��������ӡ���������",
	"xiao gang":		"佻����ɵ��������ӡ���������",
	"xiao xilou":		"佻����ɿ�ɽ��ʦ ����¥",
	"xiao ren":		"佻����ɵ��������ӡ�ӥ������",
	"gongye gan":		"��ϼׯׯ�� ��ұǬ",
	"deng baichuan":	"����ׯׯ�� �˰ٴ�",
	"feng boe":		"��˪ׯׯ����һ��硹�粨��",
	"bao butong":		"���ׯׯ������������������ͬ",
	"dao fengleng":		"ɱ��¥��ɽ��ʦ������Ц��������",
	"heibai zi":		"ɱ��¥�ͷ�ʹ�����桹�ڰ���",
	"xiao bai":		"ɱ��¥������ɱ�֡�Ц���졹С��",
	"xiao hei":		"ɱ��¥������ɱ�֡���˫����С��",
        "wenyue shitai":        "�����ɵ�������� ����ʦ̫",
        "wenxin shitai":        "�����ɵ�������� ����ʦ̫",       */
         "wenyue shitai":        "�����ɵ�������� ����ʦ̫",
        "xiao ren":             "佻����ɵ��������ӡ�ӥ������",
        "dao fengleng":         "ɱ��¥��ɽ��ʦ������Ц��������",
        "yu lianzhou":          "�䵱�ɵڶ������ӡ��䵱������������",
        "wenxin shitai":        "�����ɵ�������� ����ʦ̫",
        "song yuanqiao":        "�䵱�ɵڶ������ӡ��䵱��������Զ��",
        "xu zhu":               "���չ������ˡ����ɡ�����",
        "xiao meng":            "佻����ɵ��������ӡ���������",
        "bao butong":           "���ׯׯ������������������ͬ",
        "lazhang huofo":        "��� ���»��",
        "jiang baisheng":       "����ʤ",
        "ouyang feng":          "�϶��������ŷ����",
        "fan ye":               "�����Ա��˾����ү",
        "zhu wanli":            "���������������� ������",
        "wei yixiao":           "������������ ΤһЦ",
        "xiao bai":             "ɱ��¥������ɱ�֡�Ц���졹С��",
        "heibai zi":            "ɱ��¥�ͷ�ʹ�����桹�ڰ���",
        "xing yun":             "�����µڰ˴����� ����",
        "ban shuxian":          "���������ŷ��� �����",
        "ding chunqiu":         "�����ɿ�ɽ��ʦ�������Ϲ֡�������",
        "ouye zi":              "�����ɿ�ɽ��ʦ�����Ľ�����ŷұ��",
        "xing feng":            "�з�",
        "xiao hei":             "ɱ��¥������ɱ�֡���˫����С��",
        "ba tianshi":           "�����Ա��˾�ա�����ʯ",
        "gu yanwu":             "������",
        "xiao xilou":           "佻����ɿ�ɽ��ʦ ����¥",
        "fu sigui":             "���������������� ��˼��",
        "xiao gang":            "佻����ɵ��������ӡ���������",
        "gao shengtai":         "�����Ա���Ʋ������̩",
        "gongye gan":           "��ϼׯׯ�� ��ұǬ",
        "daizu shouling":       "��Դ������ ��������",
        "feng boe":             "��˪ׯׯ����һ��硹�粨��",
        "deng baichuan":        "����ׯׯ�� �˰ٴ�",
        "li lishi":             "������",
        "jia laoliu":           "�����ϰ� ������",
        "guan anji":            "����ϰ塸�ط��ӡ��ذ���",
        "xu xueting":           "����������ʹ����Ѫ��������ѩͤ",
        "ning zhongze":         "��ɽ�ɵ�ʮ�������� ������",
        "bosi shangren":        "��˹����",
        "hai gonggong":         "����ǧ�� ������",
        "wenxu shitai":         "�����ɵ�������� ����ʦ̫",
        "wuchen daozhang":      "�컨��ڶ������� �޳�����",
        "chen sahan":           "�컨���ܹ� ���ؽ",
        "shi daizi":            "��ɽ�ɵ�ʮ�Ĵ����� ʩ����",
        "alamuhan":             "������� ����ľ��",
        "master zhao":          "ȫ��̵��������� ��־��",
        "xiang wentian":        "������̹�����ʹ ������",
        "huansu seng":          "�����ɵ���ʮ������ ����ɮ",
        "qingfa biqiu":         "�����ɵ���ʮ������ �巨����",
        "snaker":               "�����������߼��¡�������",
        "maimaiti":             "�ӻ����ϰ� ������",
        "lu guanying":          "����ׯ��ׯ�� ½��Ӣ",
        "lao denuo":            "��ɽ�ɵ�ʮ�Ĵ����ӡ��Ϻ��ˡ��͵�ŵ",
	]);     		
	int ran, t, time;
	string *str;
	object ob, who;
	ob=this_object();
	if ( environment(this_object())->query("short")!="����" )
		return "���ﲻ���ھ֣������»��ھ���˵�ɣ�";
	who = this_player();

        if (who->query("combat_exp") > 2500000)
		return("��λ"+RANK_D->query_respect(who)+"�Ĵ�����������˭�˲�֪���ĸ����������ٱξ֣�������ң�\n");
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
	return ("���������ã�����һ�������͵�" + target[str[ran]] + "�����\n"+"�㻹��" + chinese_time(t)+ "��ʱ�䡣��춯��ɣ�\n");
}
