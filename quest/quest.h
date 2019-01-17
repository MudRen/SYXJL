#include <ansi.h>

int time_period(int timep, object me,object obj);
int give_quest();
int dest(object ob);

void init()
{
        add_action("give_quest", "mpquest");
}

int give_quest()
{
        mapping quest ;
        object me,obj,xin;
        int j, combatexp, timep,num;
        string tag = "1000000";
        string pai ;
        int score;
        string *menpai = ({
                "�������",
                "佻�����",
                "ɱ��¥",
                "ѩɽ��",
                "�컨��",
                "������",
                "����Ľ��",
                "��ң��",
                "������",
                "������",
                "������",
                "�䵱��",
                "ؤ��",
                "��ɽ��",
                "����",
                "������",
                "�һ���",
                "ȫ���",
                "����ɽ��",
                "������",
                "��Ĺ��",
                "���չ�", 
                "�嶾��", 
                "��������",        });
        string *dirfile = ({
                "riyue",
                "huanhua",
                "shashou",
                "xueshan",
                "honghua",
                "yunlong",
                "murong",
                "xiaoyao",
                "emei",
                "kunlun",
                "shaolin",
                "wudang",
                "gaibang",
                "huashan",
                "mingjiao",
                "xingxiu",
                "taohua",
                "quanzhen",
                "baituo",
                "tianlong",
                "gumu",
                "lingjiu",
                "wudujiao",
                "dali",
        });

        string *levels = ({
                        "0",
                        "5000",
                        "50000",
                        "500000",
        });
        me = this_player();
        obj= this_object();

        if(me->query("family/family_name")!=obj->query("family/family_name"))
        {
                command("? "+me->query("id"));
                command("say "+RANK_D->query_respect(me)+"�뱾�������������˻��Ӻ�˵��");
                return 1;
        }

        if( me->query_temp("mpquest_finish"))
        {
                if (((int) me->query("task_time")) < time() )
                {
                        tell_object(me,obj->query("name")+"˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        me->delete_temp("mpquest_finish");
                        return 1;
                }
                else me->delete_temp("mpquest_finish");
        }
        else if ( mapp(quest = me->query("mpquest")) )
        {
                if( ((int) me->query("task_time")) > time() )
                        return notify_fail("�����Ȱ����������ɰɡ�\n");
                else
                {
                        message_vision(obj->query("name")+"��$N̾�˿�����˵�������ˣ������Ҳ�Ӧ������ȥ������¡�\n", me);
                        score=1+random(quest["score"]/2);
                        tell_object(me,"���"+me->query("family/family_name")+"���ҳ϶Ƚ�����"+chinese_number(score)+"�㡣\n");
                        if(!me->query("score"))
                        me->set("score",0);
                        me->add("score",-score);
                        me->delete("mpquest");
                        return 1;
                }
        }

        if( ((int) me->query("task_time")) > time() )
        {
                message_vision(obj->query("name")+"��$N���˻��֣�˵������ʱû��ʲô��Ҫ���ˣ�������ȥ�ɡ�\n", me);
                return 1;
        }

        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                 num=j;
                                 break;
                        }
        }
        pai=me->query("family/family_name");
        for(j= 0;j<sizeof(menpai);j++)
        {
                if(pai == menpai[j])
                        break;
        }
        pai=dirfile[j];
        tag=levels[num];
        quest = ((string)"/quest/"+pai+"/qlist"+num)->query_quest();
        timep = quest["time"];
      tell_object(me,HIW" "+obj->query("name")+"��˼��һ�����˵����\n");
        if (!undefinedp(quest["reason"]))
                tell_object(me ,HIW" "+quest["reason"]);
        time_period(timep, me , obj);
        if (quest["quest_type"] == "Ѱ")
        {
        tell_object(me,"�һء�"+quest["quest"]+"�����ҡ�\n" NOR);
        }
        else if (quest["quest_type"] == "ɱ")
        {
        tell_object(me,"����ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
        }
        else if (quest["quest_type"] == "ɨ")
        {
        tell_object(me,"ȥ�ѡ�"+quest["quest"]+"����ɨһ�°ɡ�\n" NOR);
        }
        else if (quest["quest_type"] == "��")
        {
        tell_object(me,"��������͸���"+quest["quest"]+"���ɡ�\n" NOR);
        xin=new("/u/ronger/xin");
        xin->move(me);
        }
        quest["score"]=quest["score"];

        me->set("mpquest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        return 1;
}

int time_period(int timep, object me,object obj)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW" "+"����" + time + "��");

        return 1;
}

int accept_object(object who, object ob)
{
        int score;
        mapping quest;
        object obj=this_object();

        if( ob->is_character())
        {
        tell_object(who,obj->query("name")+"˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if(userp(ob) || !(quest =  who->query("mpquest")))
        {
        tell_object(who,obj->query("name")+"˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,obj->query("name")+"˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        remove_call_out("dest");
        call_out("dest",1,ob);
        who->delete("mpquest");
        who->set_temp("mpquest_finish",1);
        if ((int) who->query("task_time") < time() )
        {
                tell_object(who,obj->query("name")+"˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                return 1;
        }
        else
        {
                tell_object(who,obj->query("name")+"˵������ϲ�㣡���������һ������\n");
                score=quest["score"]+random(quest["score"]);
                tell_object(who,"���"+who->query("family/family_name")+"���ҳ϶������"+chinese_number(score)+"�㡣\n");
                if(!who->query("score"))
                who->set("score",0);
                who->add("score",score);
                return 1;
        }
}

int dest(object ob)
{
        destruct(ob);
        return 1;
}
