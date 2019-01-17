// challenge.c

#include <ansi.h>
#include <command.h>

inherit NPC;

void competition_with(object ob)
{
        NPC_D->set_from_me(this_object(), ob);
        ::competition_with(ob);
}

int accept_fight(object ob)
{
        if (query_temp("competition") == ob)
                return 1;

        if (ob->is_fightint())
                return notify_fail("�˼����ڱ����أ�����ô���ֲ�̫�׵��ɣ�\n");

        if (query("finished"))
                return notify_fail("�˼Ҹձ����䣬����ȥ�����ʲô��\n");

        return ACCEPT_CMD->main(ob);
}

int accept_hit(object ob)
{
        return accept_fight(ob);
}

int accept_kill(object ob)
{
        return notify_fail("�ҿ����ֶ���ԭ�������������㻹�Ǳ����ˡ�\n");
}

void lost()
{
        object ob;
        object story;
        int expi, poti, weiwangi, scorei;

        if (! objectp(ob = query_temp("competition")))
                return;

        if (! objectp(story = STORY_D->query_running_story()))
                return;

        story->stop_story();
        command("chat ���д�����ô... ��ô���ܻ�������");
/*
        CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                "��˵" + ob->name() + "�����" + name() + "����������ԭ���ֵ����ϡ�");
*/
        scorei = random(query("combat_exp") / 500) + 500;
        weiwangi = random(query("combat_exp") / 800) + 200;
        expi = random(NPC_D->check_level(this_object()) * 1000) + 10;
        poti = random(200) + 50;
       ob->add("combat_exp", scorei);
       ob->add("potential", weiwangi);
        tell_object(ob, sprintf(HIG "������%s�㾭�顢%s��Ǳ�ܡ�\n" NOR,
                     chinese_number(scorei),
                     chinese_number(weiwangi)));
        set("finished", 1);
        call_out("destruct", 0, this_object());
        ::lost();
}

void win()
{
        object ob;
        object story;

        if (! objectp(ob = query_temp("competition")))
                return;

        if (! objectp(story = STORY_D->query_running_story()))
                return;

        story->stop_story();
        command("chat* haha");
        command("chat ��ԭ���֣�����һ����");
/*
        CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                "��˵" + ob->name() + "�����" + name() + "����������ԭ���ֵ����档");
*/
        set("finished", 1);
        call_out("destruct", 0, this_object());
        ::win();
}
