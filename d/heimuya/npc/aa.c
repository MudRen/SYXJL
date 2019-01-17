#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("��������", ({
                "shen zhao",
                "shen",
                "zhao",
        }));
        set("long",
                "����һλͺ����ɮ����һϮ��ɫ������ġ�������Ըߣ�\n"
                "̫��Ѩ΢͹��˫Ŀ��������\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");
       set("title", RED "�ҷ�ȱ�" NOR);
        set("age", 50);
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 450);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 50000);
        set("score", 100);
        set("env/wimpy", 100); 
        set("inquiry", ([
                "����": "��������°�, �һ����ô���! \n",
        ]) );

        set_skill("force", 70);
        set_skill("hunyuan-yiqi", 70);
        set_skill("dodge", 70);
        set_skill("shaolin-shenfa", 70);
        set_skill("cuff", 75);
        set_skill("jingang-quan", 75);
        set_skill("staff", 76);
        set_skill("parry", 70);
        set_skill("buddhism", 70);
        set_skill("literate", 70);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");

        prepare_skill("cuff", "jingang-quan");

        setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
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

if(combatexp < 10)
        {
                message_vision("�������˶�$N����һ����: ��ľ���̫����....\n", me);
                return 1;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() )
                        return 0;
                else
                {
                        message_vision("�������˶�$N����һ����: �Բ�����, �ߣ����ٸ���һ�λ������ԡ�\n", me);
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

        while(quest["quest_type"] == "Ѱ")
        {
                quest = QUEST_D(tag)->query_quest();
                timep = quest["time"];
        }

        time_period(timep, me);
        tell_object(me, "ɱ�ˡ�" + quest["quest"] + "���Ҿ͸���һЩ�ô���\n" NOR);
        quest["exp_bonus"] = quest["exp_bonus"]*8;
        quest["pot_bonus"] = quest["pot_bonus"]*3;
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
                time = chinese_number(d) + "��";
        else
                time = "";

        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me, HIW "��������˵����\n��" + time + "��");
                return 1;
}
