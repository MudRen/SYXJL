// paper.c 手令

// writed by shadow
//Ronger 10/98
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
#define BOARD "/clone/board/towiz_b"
void auto_report(string author,string title,string text,string body);

void create() 
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
        object ob,*all;
        string report_title,body;
        all=users();
       
	if(!arg || arg =="")
	return notify_fail("你要把谁关押起来？\n");

      	for(i=0; i<sizeof(all); i++)
	{
		if( arg == all[i]->query("id"))
			ob = all[i];
	}

	if (!ob)
	return notify_fail("没有这个玩家。\n");
     
        ob->set("startroom", "/u/brave/laofang");
        ob->set("block_time",time());
        ob->move("/d/city/laofang");
        write(ob->query("name")+"已被关到忏悔室了。\n");
			call_out("do_rumor",1,ob);
        report_title = sprintf("%s(%s)的处理报告 ",ob->query("name"),ob->query("id") );
        me->edit((: auto_report,
                      sprintf("%s(%s)",
                                me->query("name"),
                                me->query("id")
                        ), // author of report
                        report_title,
                        body
                :));
		ob->set("block_time",time());
		ob->save();
                
        return 1;

}


void auto_report(string author,string title,string text,string body) {

        mapping note;
        object report;
        text="将于十日后获释。";

        if( sizeof(body) < 2 ) return;

        if( objectp(report=load_object(BOARD)) )
        {
                note=([]);
                note["title"] = title;;
                note["author"] = author;
                note["time"] = time();
              report->done_post(this_player(),note,body+text);
        }
        return;
}

void do_rumor(object ob)
{
        if (!ob)    return;
        if (!userp(ob)) return;
                CHANNEL_D->do_channel(this_player(),"rumor",ob->name()+"已被关到忏悔室了。\n");
}
