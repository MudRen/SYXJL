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

        return (month?month + "月":"") + (day?day + "日":"") + 

        (hour?hour + "时":"") + min + "分";

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

                                query_idle(ob[i]) + "秒");

                }

                return "◎ 鹿鼎记\n" + 

                "——————————————————\n"

                + "姓名          帐号          发呆\n" +

                "——————————————————\n"

                + msg +

                "——————————————————\n";

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

                                query_idle(ob[i]) + "秒", tip);

                }

                cnts=sprintf("%4d\n",total-cnt);

                return "◎ 鹿鼎记\n" + 

                "—————————————————————————————————————\n"

                + "姓名          帐号          年龄          发呆   连线\n" +

                "—————————————————————————————————————\n"

                + msg +

                "—————————————————————————————————————\n"

                +"按不同IP计算，实际登录人数为："+ cnts + "\n";

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

                return "网路指令传送过程可能需要一些时间，请稍候。\n";

        }

*/

        ob = new(LOGIN_OB);

        ob->set("id", name);

        if( !ob->restore() ) return "没有这个玩家。\n";

        

        

        if ( !wizardp(this_player()) )  // player finger

        {

        

                if( objectp(body = find_player(name)) && geteuid(body)==name )

                {

                        public_flag = body->query("env/public")?1:0;

                } else 

                {

                        body = LOGIN_D->make_body(ob);

                        if( !body->restore() ) return "没有这个玩家。\n";

                        public_flag = body->query("env/public")?1:0;

                        destruct(body);

                }               

                

                msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"

                        "电子邮件地址：\t%s\n上次连线：\t%s\n\n",

                        ob->query("id"),

                        ob->query("name"),

                        SECURITY_D->get_status(name),

                        public_flag?ob->query("email"):"不告诉你",

                        ctime(ob->query("last_on"))

                );

                if( objectp(body = find_player(name)) && geteuid(body)==name ) {

                        msg += sprintf("\n%s目前正在连线中。\n", body->name(1));

                }

        } else          // wizard finger

        {

                msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"

                        "电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",

                        ob->query("id"),

                        ob->query("name"),

                        SECURITY_D->get_status(name),

                        ob->query("email"),

                        ob->query("last_from"),

                        ctime(ob->query("last_on"))

                );

                if( objectp(body = find_player(name)) && geteuid(body)==name ) {

                        msg += sprintf("\n%s目前正在从 %s 连线中。\n", body->name(1),

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

                return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";

        if( chinese_flag ) msg =  sprintf(

                "\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"

                "电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",

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

                                ("\n" + ob->query("name") + "目前正在线上。\n"):

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

                return "本城治安良好。\n";

        else

                return "现在本城正在缉拿以下人犯：\n\n" + msg;

}



