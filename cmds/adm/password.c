// password.c
// by ÷�� 1996.10.19
#include <command.h>
#include <login.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if (wizardp(me) && arg) {
            seteuid(ROOT_UID);
            ob = new(LOGIN_OB);
            ob->set("id", arg);
            if( !ob->restore() ) {
                write("û��������: "+arg+" ��\n");
                destruct(ob);
                return 1;
            }
            write("�������µ����룺");
            input_to("get_new_pass", 1, ob );
            return 1;
        }
        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        write("Ϊ�˰�ȫ���������������ԭ�������룺");
        input_to("get_old_pass", 1, ob);
        return 1;
}

void get_old_pass(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("�������\n");
                return;
        }
        write("�������µ����룺");
        input_to("get_new_pass", 1, ob );
}

void get_new_pass(string pass, object ob)
{
        write("\n��������һ���µ����룺");
        this_player()->set_temp("passwd",crypt(pass,0));
        input_to("confirm_new_pass", 1, ob);
        
}

void confirm_new_pass(string pass, object ob)
{                                                   
    string new_pass;
    new_pass=this_player()->query_temp("passwd");
        write("\n");
        if (!pass) write("null\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("�Բ�������������벢����ͬ������ʹ��ԭ�������롣\n");
                return;
        }                       
        if( !ob->set("password", new_pass) ) {
                write("������ʧ�ܣ�\n");
                return;
        }                   
        ob->save();
        write("�������ɹ���\n");
        destruct(ob);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : passwd
 
���ָ������޸�����������롣
 
HELP
    );
    return 1;
}

