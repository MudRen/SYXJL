// fingerd.c



#include <net/dns.h>

#include <ansi.h>



void create() { seteuid( getuid() ); }



string age_string(int time)

{

        int month, day, hour, min, sec;



        sec = time % 60;

        time /= 60;

        min = time % 60;

        time /= 60;

        hour = time % 24;

        time /= 24;

        day = time % 30;

        month = time / 30;

        return (month?month + "��":"") + (day?day + "��":"") + 

        (hour?hour + "ʱ":"") + min + "��";

}



string finger_all()

{

        object *ob;

        string msg,tip,cnts;
        int i,j,cnt,flag,total;



        ob = users();

        msg = "";

        if ( !wizardp(this_player()) )  // player finger

        {

                for(i=0; i<sizeof(ob); i++) {

                        if( this_player() && !this_player()->visible(ob[i]) ) continue;

                        msg = sprintf("%s%-14s%-14s%-14s\n",

                                msg, ob[i]->query("name"), ob[i]->query("id"),

                                query_idle(ob[i]) + "��");

                }

                return "�� ¹����\n" + 

                "������������������������������������\n"

                + "����          �ʺ�          ����\n" +

                "������������������������������������\n"

                + msg +

                "������������������������������������\n";

        } else          

        {

                cnt=0;

                total=sizeof(ob);    

                for(i=0; i<sizeof(ob); i++) {

                        flag=0;

                        tip=query_ip_name(ob[i]);

                        if( this_player() && !this_player()->visible(ob[i]) ) continue;

                        for(j=0; j<sizeof(ob); j++) {

                           if(j==i) continue;

                           if(tip==query_ip_name(ob[j]) && j<i)

                             {cnt=cnt+1;

                              flag=1;

                              break;    

                                }

                        }

                        if(flag==1) tip= RED+tip+NOR;

                        msg = sprintf("%s%-14s%-14s%-14s%-7s%s\n",

                                msg, ob[i]->query("name"), ob[i]->query("id"),

                                age_string( (int)ob[i]->query("mud_age")), 

                                query_idle(ob[i]) + "��", tip);

                }

                cnts=sprintf("%4d\n",total-cnt);

                return "�� ¹����\n" + 

                "��������������������������������������������������������������������������\n"

                + "����          �ʺ�          ����          ����   ����\n" +

                "��������������������������������������������������������������������������\n"

                + msg +

                "��������������������������������������������������������������������������\n"

                +"����ͬIP���㣬ʵ�ʵ�¼����Ϊ��"+ cnts + "\n";

                // end of modification

        }

}

        

string finger_user(string name)

{

        object ob, body;

        string msg;
        int public_flag;



/*      if( sscanf(name, "%s@%s", name, mud)==2 ) {

                GFINGER_Q->send_finger_q(mud, name, this_player(1));

                return "��·ָ��͹��̿�����ҪһЩʱ�䣬���Ժ�\n";

        }

*/

        ob = new(LOGIN_OB);

        ob->set("id", name);

        if( !ob->restore() ) return "û�������ҡ�\n";

        

        

        if ( !wizardp(this_player()) )  // player finger

        {

        

                if( objectp(body = find_player(name)) && geteuid(body)==name )

                {

                        public_flag = body->query("env/public")?1:0;

                } else 

                {

                        body = LOGIN_D->make_body(ob);

                        if( !body->restore() ) return "û�������ҡ�\n";

                        public_flag = body->query("env/public")?1:0;

                        destruct(body);

                }               

                

                msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"

                        "�����ʼ���ַ��\t%s\n�ϴ����ߣ�\t%s\n\n",

                        ob->query("id"),

                        ob->query("name"),

                        SECURITY_D->get_status(name),

                        public_flag?ob->query("email"):"��������",

                        ctime(ob->query("last_on"))

                );

                if( objectp(body = find_player(name)) && geteuid(body)==name ) {

                        msg += sprintf("\n%sĿǰ���������С�\n", body->name(1));

                }

        } else          // wizard finger

        {

                msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"

                        "�����ʼ���ַ��\t%s\n�ϴ����ߵ�ַ��\t%s( %s )\n\n",

                        ob->query("id"),

                        ob->query("name"),

                        SECURITY_D->get_status(name),

                        ob->query("email"),

                        ob->query("last_from"),

                        ctime(ob->query("last_on"))

                );

                if( objectp(body = find_player(name)) && geteuid(body)==name ) {

                        msg += sprintf("\n%sĿǰ���ڴ� %s �����С�\n", body->name(1),

                                query_ip_name(body));

                }

        }       

        

        destruct(ob);

        return msg;

}



varargs string remote_finger_user(string name, int chinese_flag)

{

        object ob, body;

        string msg;



        ob = new(LOGIN_OB);

        ob->set("id", name);

        if( !ob->restore() )

                return chinese_flag ? "û�������ҡ�\n" : "No such user.\n";

        if( chinese_flag ) msg =  sprintf(

                "\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"

                "�����ʼ���ַ��\t%s\n�ϴ����ߵ�ַ��\t%s( %s )\n\n",

                ob->query("id"),

                ob->query("name"),

                SECURITY_D->get_status(name),

                ob->query("email"),

                ob->query("last_from"),

                ctime(ob->query("last_on"))

        );

        else msg =  sprintf(

                "\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",

                capitalize(ob->query("id")),

                SECURITY_D->get_status(name),

                ob->query("email"),

                ob->query("last_from"),

                ctime(ob->query("last_on"))

        );

        if( body = find_player(name) ) {

                if( !this_player() || this_player()->visible(body) )

                        msg += chinese_flag ?

                                ("\n" + ob->query("name") + "Ŀǰ�������ϡ�\n"):

                                ("\n" + capitalize(name) + " is currently connected.\n");

        }



        destruct(ob);

        return msg;

}



object acquire_login_ob(string id)

{

        object ob;



        if( ob = find_player(id) ) {

                // Check if the player is linkdead

                if( ob->query_temp("link_ob") )

                        return ob->query_temp("link_ob");

        }

        ob = new(LOGIN_OB);

        ob->set("id", id);

        return ob->restore() ? ob : 0;

}



string get_killer()

{

        int i;

        string msg;

        object *ob = users();



        msg = "";

        for (i = 0; i < sizeof(ob); i++)

                if ((int)ob[i]->query_condition("killer"))

                        msg += (ob[i]->short() + "\n");

        if (msg == "")

                return "�����ΰ����á�\n";

        else

                return "���ڱ������ڼ��������˷���\n\n" + msg;

}



