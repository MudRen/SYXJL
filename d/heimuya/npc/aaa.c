inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
string join_me(object me);

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈", "刘","林" }); 
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠", "孝","雄","益","添","金",
"辉","长","盛","胜","进","安","福","同","满", "富","万","龙","隆","祥","栋","国","亿","寿","杨" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"}); 
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *rnd_say = ({ 
"我是日月新弟子，你是谁？", 
"为什麽我好象没见过你？", 
"能给我一些钱吗？", 
"你不理我？", 
"可不可以告诉我哪里有吃喝？", 
"hi", "hello", "hmm", "wa...",
"waley", "wait...", "hohoho", "hehe",
"ah..", 
});

varargs void drool(string msg, string who);
void create() 
{ 
        string name, id;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
        if( random(10) > 2 ) 
                name += name_words[random(sizeof(name_words))];
        id = rnd_id[random(sizeof(rnd_id))]; 
        if( random(10) > 4 ) 
                id += rnd_id[random(sizeof(rnd_id))]; 
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        set_name(name, ({ id, "drooler"
}) ); 
set("title",HIG"日月神教青龙堂弟子"NOR);
        set("gender", "男性"); 
        set("age", 14); 
        set("attitude", "friendly"); 
        set("combat_exp", 100); 
        set("env/wimpy", 100); 
        set("inquiry", ([
                "任务": "你帮我做事吧, 我会给你好处的! \n",
        ]) );

        setup(); 
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
//     add_action("give_quest", "quest");
}


int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep, factor, num;
        string tag = "10000";
        string *levels = ({
                "1000",
        });
        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

if(combatexp < 100)
        {
                message_vision("守卫对$N哼了一声道: 你能为我做什么？去去去....\n", me);
                return 1;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() )
                        return 0;
                else
                {
                        message_vision("守卫对$N哼了一声道: 真给我丢脸, 羞羞羞！就再给你一次机会试试。\n", me);
                        me->set("qi", (int)(me->query("qi")/2+10));
                }
        }

        for(j = sizeof(levels) - 1 ; j >= 0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                {
                        num = j;
                        factor = 10;
                        break;
                }
        }
        if(num > 0)
        {
                if (random(50) > 45)
                {
                        num = num - 1;
                }
        }
        else
        {
                if ((num < sizeof(levels) - 1) && (random(100) > 95))
                {
                        num = num + 1;
                        factor = 15;
                }
        }
        tag = levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];

        while(quest["quest_type"] == "寻")
        {
                quest = QUEST_D(tag)->query_quest();
                timep = quest["time"];
        }

        time_period(timep, me);
        tell_object(me, "杀了『" + quest["quest"] + "』我就给你一些好处，嘻嘻。\n" NOR);
        quest["exp_bonus"] = quest["exp_bonus"];
        quest["pot_bonus"] = quest["pot_bonus"];
        quest["score"] = quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int)time() + (int)quest["time"]);
        me->set("quest_factor", factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";

        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "守卫说道：\n在" + time + "内");
                return 1;
}

