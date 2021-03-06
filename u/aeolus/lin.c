// linzhennan.c 林平之
// modified by aeolus /12/27/2000
#include <ansi.h>
string do_quest();
inherit NPC;
void create()
{
        set_name("林平之", ({ "lin pingzhi", "lin", "pingzhi" }));
        set("gender", "男性");
        set("title", "福威镖局少当家");
        set("age", 20);
        set("long", "他就是「福威镖局」的少当家－－林平之。\n");
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
                "向阳老宅" : "林平之说道：那是我从前在福建时住的家院，已经破败了。\n",
                "远图公" : "林平之说道：远图公是我的曾祖父。\n",
                "林远图" : "林平之哼了一声，不理你。\n",
                "运镖":(:do_quest:),
                "镖": (:do_quest:),
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
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return time;
}

string do_quest()
{
        mapping target=([
        "tang nan":             "当铺老板 唐楠",
        "ping yizhi":           "药铺老板 平一指",
        "xu zhu":               "灵鹫宫掌门人「梦郎」虚竹",
        "ning zhongze":         "华山派第十三代弟子 宁中则",
        "yu lianzhou":          "武当派第二代弟子「武当二侠」俞莲舟",
        "song yuanqiao":        "武当派第二代弟子「武当首侠」宋远桥",
        "li lishi":             "李力世",
        "guan anji":            "茶馆老板「关夫子」关安基",
        "lazhang huofo":        "活佛 拉章活佛",
        "jia laoliu":           "当铺老板 贾老六",
        "ouyang feng":          "老毒物「西毒」欧阳锋",
        "ding chunqiu":         "星宿派开山祖师「星宿老怪」丁春秋",
        "jiang baisheng":       "江百胜",
        "wei yixiao":           "明教青翼蝠王 韦一笑",
        "ouye zi":              "玄天派开山祖师「赤心剑胆」欧冶子",
        "ban shuxian":          "昆仑派掌门夫人 班淑娴",
        "gu yanwu":             "顾炎武",
        "xiao meng":            "浣花剑派第三代弟子「龙」萧猛",
        "xiao gang":            "浣花剑派第三代弟子「虎」萧刚",
        "xiao xilou":           "浣花剑派开山祖师 萧西楼",
        "xiao ren":             "浣花剑派第三代弟子「鹰」萧韧",
        "gongye gan":           "赤霞庄庄主 公冶乾",
        "deng baichuan":        "青云庄庄主 邓百川",
        "feng boe":             "玄霜庄庄主「一阵风」风波恶",
        "bao butong":           "金凤庄庄主「包三先生」包不同",
        "dao fengleng":         "杀手楼开山祖师「刀剑笑」刀锋冷",
        "heibai zi":            "杀手楼赏罚使「冷面」黑白子",
        "xiao bai":             "杀手楼第三代杀手「笑苍天」小白",
        "xiao hei":             "杀手楼第三代杀手「无双剑」小黑",
        "wenyue shitai":        "峨嵋派第五代弟子 文月师太",
        "wenxin shitai":        "峨嵋派第五代弟子 文心师太",
        ]);                     
        int ran, t, time;
        string *str;
        object ob, who;
        ob=this_object();
        if ( environment(this_object())->query("short")!="福威镖局" )
                return "这里不是镖局，你有事回镖局再说吧？";
        who = this_player();

        if (who->query("combat_exp") > 1000000)
                return("这位"+RANK_D->query_respect(who)+"的大名，江湖上谁人不知，哪个不晓？光临蔽局，深感荣幸
！\n");
        t = time()-who->query("biao_start");
        time = who->query("biao_time");
        if( t <= time )
                return  RANK_D->query_respect(who)+ "似乎还有任务在身吧？\n";
        if( t > time && t < (time + 300) ) {
                if( ob = present("biao yin", who) ) destruct(ob);
                who->set("biao_failed",1);
        }
        if( t >= (time + 300) )
                who->delete("biao_failed");
        if(who->query("biao_failed") ) {
                command("hehe " + who->query("id"));
                return this_player()->name() + "，你印堂发黑，流年失利，我看还是不适宜运镖了。\n";
        }
        t = ( 20 + random(10) ) * 10;
        str=keys(target);
        ran = random(sizeof(str));
        ob = new("/clone/misc/biaoyin");
        ob->set("target", str[ran]);
        who->set("biao_start", time());
        who->set("biao_time", t);
        ob->move(who);
        return ("你来得正好，我有一箱镖银送到" + target[str[ran]] + "的手里。\n"+"你还有" + chinese_time(t)+ "
的时间。快快动身吧！\n");
}
