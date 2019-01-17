// kuli.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "zhao liu", "liu", "zhao" }));
        set("title", "�̲�����");
        set("nickname", "ˮ���");
        set("shen_type", -1);

        set("str", 37);
        set("gender", "����");
        set("age", 35);
        set("long",
                "�����̲�������һ��ֵ���С�����ٲ��󣬿�Ȩ��ȴ��С\n");
        set("combat_exp", 1500);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "Ҫ�����ȵý�Ǯ��",   //��Ҫ30���ƽ�
        ]));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
//      carry_object("/d/shaolin/obj/qimeigun")->wield();
}

void init()
{
        object ob; 
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_betray","decide");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("����Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "���������Ъ�����ɡ�\n");
                break;
        case 1 :
                say("����˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰�����Ҫ���������ʦ��¼��\n");
                break;
        }
}

int accept_object(object who, object ob)
{      
        object me;
        me = this_player();                if ((int)me->query("betrayer") <= 0) 
        {
                tell_object(who, "�����ٺ�һЦ���ɻ��˵���������������Ǯ�������ʲô����û���й�ʦ�
����Ǯ�����Ҿ������ˣ� ��\n");
                return 1;
        } 
        if (ob->query("money_id") && ob->value() >= 300000)
        {
tell_object(who,"����Ц���е�˵�����ðɣ�ÿ���һ����ʦ��¼Ҫ��ȥ50%�ľ��顢���Ҹ��Ź���20����\n");
                tell_object(who, "�㿼������˾������������ɡ�(decide)\n");
                who->set_temp("fee_paid",1);
                return 1;
        }
         if (ob->query("money_id") && ob->value() < 300000) 
        {
                tell_object(who, "�����ٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
                return 1;
        }        return 0;
}

int do_betray()
{
        int i, level, exper;
        object me;
        mapping skill_status;
        string *sname;

        me = this_player();

        if( !me->query_temp("fee_paid") ) 
                return notify_fail("���������˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");

        exper = me->query("combat_exp");
        exper -= exper * 50 / 100;
        if(exper <= 0)
                exper = 0;

        if ( !(skill_status = me->query_skills()) )
        {
                me->set("combat_exp", exper);
                me->delete_temp("fee_paid");
                if( (int)me->query("betrayer") >= 1)
                        me->add("betrayer", -1);
                tell_object(me, "����Ц���е�˵������������ʦ��¼�����һ�Ρ�\n");
                me->unconcious();
                return 1;
        }

        sname  = keys(skill_status);

        for(i = 0; i < sizeof(skill_status); i++) 
        {
                 level = skill_status[sname[i]] - 20;
                if(level <= 0)
                        me->delete_skill(sname[i]);
                else
                        me->set_skill(sname[i], level);
        }

        me->set("combat_exp", exper);
        me->delete_temp("fee_paid");
        if( (int)me->query("betrayer") >= 1)
                me->add("betrayer", -1);

        tell_object(me, "����Ц���е�˵������������ʦ��¼�����һ�Ρ�\n");
        me->unconcious();

        return 1;
}


