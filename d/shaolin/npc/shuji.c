// shuji.c �������

inherit NPC;
int check_legal_name(string arg);

string *banned_name = ({
        "��", "��", "��", "��", "��", "�Լ�"
        });
void create()
{
        set_name("�����", ({ "liu shuji", "liu", "shuji" }));
        set("title", "������Ʒ�Ĺ�");
        set("nickname", "ȫ��һ֧��");
        set("shen_type", 1);

        set("str", 50);
        set("gender", "����");
        set("age", 35);
        set("long",
                "���������ǻ�������С��һ����Ա���ƹ���ҵĻ��ڡ�\n");
        set("combat_exp", 1500);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "Ҫ�����ȵý�Ǯ��",
        ]));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_name","��");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("�����Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "���������Ъ�����ɡ�\n");
                break;
        case 1 :
                say("�����˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰�����Ҫ������\n");
                break;
        }
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 1000000)
        {
                tell_object(who, "�����Ц���е�˵�����ðɣ������ǿ�������ȡ��ʲô���������֡�\n");
                tell_object(who, "����룺�� �µ���������\n");
                who->set_temp("fee_paid",1);
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 1000000) 
        {
                tell_object(who, "����Ǻٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
                return 1;
        }

        return 0;
}

int do_name(string target)
{
        object me;
        string old_name;
        string arg;        
        me = this_player();
        old_name = me->query("name");

        if( !me->query_temp("fee_paid") ) 
                return notify_fail("����������˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");

        if( !target || target==" ") 
                return notify_fail("������Ի󲻽��˵��������������µ�����ѽ��\n");

        if( old_name == target )
                return notify_fail("�������ֵض���˵��������Ǯ�ǲ�������̫�����ˣ�\n");

        if( strlen(target) > 10 )
                return notify_fail("�������̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
        if( !check_legal_name(arg) ) 
        {       
        command("chat " + old_name + "�����ڿ�ʼ����Ϊ��" + target + "������Ժ���ϴ����ˣ�\n");
        me->delete_temp("fee_paid");
        me->set("name", target);
        return 1;
        }
}


int check_legal_name(string name)
{
        int i;

        i = strlen(name);

        if( (strlen(name) < 2) || (strlen(name) > 8 ) ) {
                write("�Բ�������������ֱ����� 1 �� 4 �������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }

        if ( file_size(CONFIG_DIR + "banned_name") >=0 )
        {
                banned_name = explode(read_file(CONFIG_DIR + "banned_name"), "\n");
        }
        else
        {
                i = sizeof(banned_name);
                while(i--)
                {
                        write_file(CONFIG_DIR + "banned_name", banned_name[i] + "\n", 0);
                }
        }

        if( member_array(name, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }

        return 1;
}
