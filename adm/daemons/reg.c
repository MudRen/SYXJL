#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

inherit ITEM;

int my_socket,socket1,socket2;
object me;
int status=0;
string smtp_ip="10.162.10.2 25";
string smtp_domain="mail.yn.cninfo.net";
string sender="Cctx";
string rcpt,msg;
int write_message(string);
void tell_me(string arg)
{
        tell_object(environment(this_object()),arg);
}
void chat(string arg)
{
	CHANNEL_D->do_channel(this_object(),"sys",arg);
	tell_me(arg);
	return;
}

void create()
{
        set_name("["+CHINESE_MUD_NAME+"]"+"注册器", ({ "register","smtp", "telnet" }) );
        set("long",
                "注册工具。\n");
                set_weight(3000);
                set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "个");
                        set("material", "unknow");
                }
        setup();
}

void init()
{       
        object ob;

        if( interactive(ob = this_player()) ) {
                add_action("close_socket","close");
                add_action("write_message","/");
                add_action("do_register","register");
                me = ob;
        }
}

int do_telnet(string arg)
{
        int err;
        if( query("connected") )        socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 ) {
//                tell_me( "Failed to create socket.\n" );
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS ) {
//                      tell_me("Connect to " + arg + "\n");
                        set("connected",1);
        }
        else
//                        tell_me("Can't connect to " + arg + "\n");
        return 1;
}

int close_socket()
{
        if( query("connected") )  {
                        if( socket_close(my_socket) ) {
                                tell_me("Closed telnet socket.\n");
                                delete("connected");
                        }
                        else
                                tell_me("Close telnet socket fail.\n");
                }
        else
                tell_me("Not connected.\n");
        return 1;
}

void read_callback(int fd, mixed message)
{
    tell_me( BOLD + "→" + NOR + message );
    switch(status)
    {
    	case 0:
    		if(sscanf(message,"220%*s"))
    		{
    			status++;
  			write_message("HELO " +smtp_domain );
    			//chat("发出HELO命令");
    			return;
    		}
    		break;
    	case 1:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("MAIL FROM:<CCTX>");
    			//chat("发出MAIL FROM命令");
    			return ;
    		}
			break;
    	case 2:
    		if(rcpt&&sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("RCPT TO:<"+rcpt+">");
    			//chat("发出RCPT TO命令");
    			return ;
    		}
    		break;
    	case 3:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("DATA");
    			//chat("发送DATA命令");
    			return;
    		}
    		break;
    	case 4:
    		if(sscanf(message,"354%*s"))
    		{
    			status++;
    			if(sscanf(msg,"%*s\r\n.\r\n%*s"))
    				chat("包含非法数据，可能会无法发送。\n");
    			log_file("sendmail","\n试图发送数据:\n"+msg);
    			write_message(msg+"\n.\n");
    			//chat("发送数据");
    			return;
    		}
    		break;
    	case 5:
    		if(sscanf(message,"451%*s"))
    			chat("Smtp Server接收数据出错！请另选服务器。\n");
    		else
    			chat("注册信件已经正确发送了，请过几分钟后再打开你的信箱查收。\n");
    		break;    			
    }
    if(status!=5||!sscanf(message,"250%*s"))
    	chat("发送出错");
    status=0;
	write_message("QUIT");
	chat("恢复断线状态");
	close_socket();
	return ;        			
}

void write_callback(int fd)
{
        int res;
        if(query("connect"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
                set("connected",1);
        }
}

int write_message(string arg)
{
        if( !arg ) arg="";
        socket_write(my_socket,arg+"\n");
        return 1;
}

string make_password(string arg,string id)
{
	return id;
}

int do_register(string dest)
{
	object me,linkob;

	me=this_player(1);
	if( !dest||!sscanf(dest,"%*s@%*s.%*s") )
		return notify_fail("电子邮件地址错误。\n");
	rcpt=dest;
	status=0;
	if(!my_socket&&do_telnet(smtp_ip)==0)
		return notify_fail("无法连接邮件服务器。\n");
	//设置玩家的注册信息
	linkob=me->query_temp("link_ob");
	linkob->set("password", crypt(make_password(dest,me->query("id")),0) );
	linkob->set("email",lower_case(dest));
	me->set("startroom","/d/welcome/wel1_1");
	//发出注册信件
	msg="\n你好！欢迎光临"+CHINESE_MUD_NAME+"！\n"+
		"你已经成功地在本游戏注册，请使用下面提供的密码登录完成注册。\n你的注册密码是："+
		make_password(dest,me->query("id"))+"\n"
		"如果你丢失此信，请用原来的临时密码进入，并重新注册。\n";
	msg="TO:"+dest+"\n"+
		"SUBJECT:"+CHINESE_MUD_NAME+"注册信件！\n"+
		"FROM:"+me->query("id")+"@"+INTERMUD_MUD_NAME+"\n"+
		"MIME-Version:1.0\n"+
		"DATE:"+time()+"\n"+
		"X-MAILER:Lpc Smtp client v0.1\n"+"\n"+
		msg;
		
//下面的这些操作移动到read_callback里了		
/*	msg="HELO " + smtp_domain + "\n" +
        "MAIL FROM: <" + sender + ">\n" + 
        "RCPT TO: <" + dest + ">\n" +
        "DATA\n" + msg + "\n.\n" +
        "QUIT\n";
	write_message(msg);
	*/
	return 1;
}
