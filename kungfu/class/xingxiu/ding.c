// ding.c ������
// by QingP

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        seteuid(getuid());
        set_name("������", ({ "ding chunqiu", "ding" }));
        set("nickname", HIR "�����Ϲ�" NOR);
        set("long", 
                "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
                "����ɫ������ͷ�׷�������������ף�ͯ�պ׷����������ͼ���е���������һ�㡣\n"
                "����������ò���棬�ɷ���ǣ�����Ӻ�ݣ����ٲȻ��\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 29);
        set("dex", 29);
        
        set("max_qi", 4700);
        set("max_jing", 3700);
        set("neili", 4100);
        set("max_neili", 4100);
        set("jiali", 100);
        set("combat_exp", 1700000);
        set("score", 700000);

             set_skill("force",300);
             set_skill("dodge",300);
             set_skill("strike",300);
             set_skill("claw",300);
             set_skill("poison",300);
             set_skill("throwing",200);
             set_skill("parry",290);
             set_skill("beiming-zhenqi",300);
             set_skill("staff",200);
             set_skill("literate",200);
             set_skill("zhaixinggong",200);
             set_skill("xingchen-zhang",300);
          set_skill("dodge", 200);
          set_skill("strike", 200);
          set_skill("claw", 200);
          set_skill("poison",200);
          set_skill("throwing",150);
          set_skill("staff", 170);
          set_skill("parry", 190);
          set_skill("literate", 130);
        set_skill("beiming-zhenqi", 200);
        set_skill("zhaixinggong", 170);
        set_skill("xingchen-zhang", 200);
          set_skill("wugong-zhao",270);
        set_skill("huagong-dafa", 190);
          set_skill("tianshan-zhang",270);

        map_skill("force", "beiming-zhenqi");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingchen-zhang");
        map_skill("claw", "wugong-zhao");
        map_skill("poison", "huagong-dafa");
        map_skill("parry", "xingchen-zhang");
        map_skill("staff", "tianshan-zhang");
        
        prepare_skill("strike", "xingchen-zhang");
        prepare_skill("claw", "wugong-zhao");

        create_family("������", 1, "��ɽ��ʦ");
        set("class", "taoist");

/*      set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "strike.du" :),
                (: perform_action, "strike.zhen" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.hua" :),
        }) );*/

        set("inquiry", 
        ([
                "���޶���" : (: ask_me :),
        ]));

        set("book_count", 1);
        set("no_get",1);

        setup();

        carry_object("/d/xingxiu/obj/xiaoyaosan");
        carry_object("/d/xingxiu/obj/bilinxing");
        carry_object("/d/xingxiu/obj/bilinxing");
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "������") {
                command("say �����������֮ͽ������͵�챾�ɱ��䣡");
                for(int i=0; i<4; i++) {
                        if( objectp( ob = present("dizi " + (i+1), environment(this_object())) ) ){
                                message_vision("�����ɵ���Ⱥ���$N����������\n", this_player());
                                ob->kill_ob(this_player());
                        }
                        else command("throw xiaoyao san at " + (string)this_player()->query("id"));
                }
        return "�ߣ�";
        }

        if (query("book_count") < 1)
                return "�������ˣ����ɱ����Ѳ�������ˡ�";
        add("book_count", -1);
        ob = new("/d/xingxiu/obj/dujing_2");
        ob->move(this_player());
        return "�Ȿ�����޶������²᡽�����Ҫ�úñ��ܣ�Ī��������������С�";
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
        if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="ding chunqiu") {
                command("chat "+ob->query("name")+"!װʲô������ʿ�����ҹ��������ɡ�\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }

        add_action("do_flatter", "flatter");
        add_action("do_kill", "kill");
        add_action("do_hit", "hit");
}

void do_kill(string arg)
{
        object me = this_player();
        object obj;

        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "ding chunqiu" || arg == "ding") {
                command("grin");
                command("throw xiaoyao san at "+me->query("id"));
        }
}

void do_hit(string arg)
{
        object me = this_player();
        object obj;

        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "ding chunqiu" || arg == "ding") {
                remove_call_out("checking");
                call_out("checking", 1, obj, me);
        }
}

void attempt_apprentice(object me)
{
        if ((int)me->query("betrayer")) {
                command("say ��Խ����Խ�������Ե׵ġ�");
                return;
        }

        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        }
        else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        string name,new_name; 
        object me = this_player();      
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
        ||  strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say ������ѧ��Դ�����ޣ����Ҫ�ú���ϰѽ��\n");
                command("recruit " + this_player()->query("id"));
                name = me->query("name");
                new_name = name[0..3] + "��";
                me->set("name", new_name);
                command("say �����ڿ�ʼ��" + new_name + ",��������ɵڶ���������!");    
                command("recruit " + me->query("id"));        
        }
        else command("say ����˲������ɷ�����������������㣿");

        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

/*int prevent_learn(object me, string skill)
{
        object ob = this_object();

        if(skill == "huagong-dafa")
        {
                message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ���������ǰ���˱����������� ...��\n", ob, me );
                message_vision("$N����һ�ɣ��ȵ������У�\n", ob, me );
                tell_object(me, "�������˶�����Ĳ���֮��������ѧ��������ѽ����\n");
                return 1;
        }
        return 0;
}*/
        
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 ) {
                        message_vision(HIG"\n���������˺�Ȼȡ�������ۧ������������û򴵣��ò����֣�\n" NOR, me);
                        switch( random(2) ) {
                                case 0:
                                        say(GRN "\n����˵�����������������֣��Ҷ�ʦ�����޵У�\n" NOR);
                                        say(GRN "\n����˵�����������ɺ�ʩ�󷨣�����������ħС��\n" NOR);
                                        say(GRN "\n����˵�����������ɾ������ᣬ�񹦸��������ս�����۽磡\n" NOR);
                                break;
                                case 1:
                                        say(HIY "\n���Ӷ���˵�������ȵ���֮�𣬾�ȻҲ�Һ��������⣬����������־��ܣ�\n" NOR);
                                        say(HIY "\n���Ӷ���˵�������۵������Բ���������Ц����Ц��\n" NOR);
                                        say(HIY "\n�ڵ��������������������ɣ������أ��������Ž��ޱȣ�\n" NOR);
                                break;
                                case 2:
                                        say(HIB "\n����˵����ʦ�������˼�̸Ц֮�䣬�㽫һ����ħС���������أ�\n"
                                        "��˴߿��������ȫʤ��ͽ����������δ������������δ�š�\n" NOR);
                                        say(HIB "\n����˵�����������´���δ�еķṦΰ����������ʦ�����˼�¶����һ�֣�\n"
                                        "������֪��������ȹ���\n" NOR);
                                        say(HIB "\n����˵�������������������ܼ��������ɣ���˭�����۵�����������ȡ�������ѡ�\n" NOR);
                                break;
                        }
                        message_vision(HIY "\n��ʱ��ñ����ƨ��ɣ����ݹ����ͬ�졣��Щ�޳ܸ���֮�����������ϹֵĹ�����\n��ȻҲ�����Ʋ�����֮����\n" NOR, me);

                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                else if ( (int)ob->query("qi")*100 / his_max_qi < 50 ) {
                        say(GRN "\n ������˵����������ɶ���С�ӣ��㻹�����أ�\n"
                                        + "�����������������£������ɽ��㼸���ϳ��񹦣�\n");
                        return 1;
                }

                if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}

