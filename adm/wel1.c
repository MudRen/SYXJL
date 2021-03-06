#include <mudlib.h>
#include <ansi.h>

inherit REGROOM;

void create()
{
    set("short",  "〖剑.花.烟雨.江南〗注册处" );
    set("long", 
    NOR"欢迎进入"+HIG"〖剑.花.烟雨.江南〗"NOR+"的传奇世界， 为了能够更好并及时的\n"+
    "为您提供服务和相关信息，在您步入江湖之前，我们希望您能够注册您的\n"+
    "电子邮件地址，您的电子邮件地址将是我们唯一与您保持联系的途径，也\n"+
    "是您忘记密码后唯一能够验证身份的方式。因此请务必正确的注册您的邮\n"+
    "件地址。注册前您可以先输入"+CYN"〖"+HIR"read notes"NOR+CYN"〗"NOR+"来阅读注册须知，您也可以\n"+
    "输入"+CYN"〖"+HIR"read rules"NOR+CYN"〗"NOR"来仔细阅读江湖规则。如果您一切准备就绪并且同意\n"+
    "江湖规则，请注册您的电子邮箱地址。 注册方式如下：\n"
    
    CYN"〖"HIR"register "NOR GRN"电子信箱地址"CYN"〗\n"+
    CYN"〖"HIR"zhuce "NOR GRN "   电子信箱地址"CYN"〗\n\n"+
    "如果你不愿留下你的电子邮件地址，请输入"HIR"leave"NOR+CYN"离开此地。\n"+
    "\t\t\t\t"+HIG"〖剑.花.烟雨.江南〗"NOR+"巫师协会\n"+
    "\t\t\t\t"+"   二零零零年二月二十二日\n"
        );
        set("no_fight", 1);
        setup();
}

void init()
{       object ob;
        ::init();
        add_action("do_read","read");
        add_action("do_leave","leave");
        if( interactive(ob = this_player()) ) 
       {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
    write(HIR BLINK"\nHi!"NOR+HIC"这位"HIW+RANK_D->query_respect(ob)+HIC", 欢迎光临"+CHINESE_MUD_NAME+",这里是注册处。\n"+"    请一定要仔细阅读这里的通知哟!\n\n"NOR);
        return;
}
int do_read(string arg)
{
        switch(arg)
        {
                case "notes":
                        write(
                                "请务必输入正确的电子信箱地址，以确保注册信件能正确送到你手里。\n"+
                                "如果你没有得到注册密码，请以原来的密码登录重新注册。\n"+
                                "有问题请与巫师联系，并尽量到主页上留言。\n"+
                                GRN"jzbyt@sina.com\n"NOR
                                );
                        break;
                case "rules":
                        write(
                                "请输入help 来获取详细的游戏规则。请勿违反，违反必究。\n"+
                                "如果你不同意规则，请与巫师联系或输入 leave 退出江湖。\n"
                                );
                        break;
                default:
                        return 0;
        }
        return 1;
}

int do_leave(object ob, object link_ob)
{
    ob=this_player();
    if(wizardp(ob)||ob->query("registered"))
    {
        ob->move("/d/city/wumiao");
        tell_room(environment(ob),ob->name()+"匆匆忙忙的离开了注册大厅\n");
        return 1;
    }
    else {
    link_ob = ob->query_temp("link_ob");
    if( !link_ob ) return 0;   
    seteuid(getuid());
    rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
    rm( ob->query_save_file() + __SAVE_EXTENSION__ );
    write("好吧，再见! ^&^。\n");
    destruct(ob);
    return 0;
    }
}

