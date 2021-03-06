// help.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;
void selete_main(string num,object ob);
void help_new(string num,object ob);
void help_map(string num,object ob);
void quit_help(object ob);

int main(object me, string arg)
{
        int i;
        string file, *search;
        object ob;
        ob = this_player();

        if( !arg ) {
                write(CLR);
                cat("/doc/main");
                input_to("selete_main", ob);
                ob->set_temp("block_msg/all",1);
                return 1;
        }
        else if ( arg=="-old" )
        {
                cat("/help/help/topics");
                return 1;
        }
        else if ( arg=="-new" )
        {
                write(CLR);
                cat("/help/help/topics1");
                ob->set_temp("block_msg/all");
                input_to("help_new",ob);
                return 1;
        }

        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
                return file->help(me);
        }

        // Search the individual search path first.
        if( pointerp(search = me->query("help_search_path")) ) {
                i = sizeof(search);
                while(i--) if( file_size(search[i] + arg)>0 ) {
                        me->start_more( read_file(search[i] + arg) );
                        return 1;
                }
        }

        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        sscanf(arg, "%s()", arg);

        // Finally, search the default search paths.
        if( pointerp(default_search) ) {
                i = sizeof(default_search);
                while(i--) if( file_size(default_search[i] + arg)>0 ) {
                        me->start_more( read_file(default_search[i] + arg) );
                        return 1;
                }
        }

        return notify_fail("没有针对这项主题的说明文件。\n");
}

void selete_main(string num,object ob)
{
        if( num == "1" )
        {
                ob->delete_temp("block_msg/all");
                write(CLR);
                cat("/help/help/topics");
        }
        else if( num == "2" )
        {
                ob->delete_temp("block_msg/all");
                write(CLR);
                cat("/help/help/topics1");
                ob->set_temp("block_msg/all");
                input_to("help_new",ob);
        }
        else if( num == "q" || num == "Q" ) quit_help(ob);
        else
        {
                ob->delete_temp("block_msg/all");
                write(HIR"\n    对不起，没有这个选项！您可以选择：\n"NOR);
                write(CYN"  　１、自选模式目录　　２、向导模式目录　　３、退出帮助\n"NOR);
                write(CYN"\n    请输入选择项（1 or 2 or 3）："NOR);
                ob->set_temp("block_msg/all");
                input_to("selete_main", ob);
        }
}

void help_new(string num,object ob)
{
        if( num == "1" )
        {
                write(CLR);
                cat("/doc/help/intro");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "2" )
        {
                write(CLR);
                cat("/doc/help/rules");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "3" )
        {
                write(CLR);
                cat("/doc/help/newbie");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "4" )
        {
                write(CLR);
                cat("/doc/help/kungfu");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "5" )
        {
                write(CLR);
                cat("/doc/help/family");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "6" )
        {
                write(CLR);
                cat("/doc/help/commands");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "7" )
        {
                ob->delete_temp("block_msg/all");
                write(CLR);
                cat("/doc/help/map");
                ob->set_temp("block_msg/all");
                input_to("help_map",ob);
        }
        else if( num == "8" )
        {
                write(CLR);
                cat("/doc/help/settings");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "9" )
        {
                write(CLR);
                cat("/doc/help/renwu");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "q" || num == "Q" ) quit_help(ob);
        else
        {
                ob->delete_temp("block_msg/all");
                write(HIR"\n 对不起，没有这个选项！\n"NOR);
                write(CYN"\n 请输入选择项（1-9选择相应项目，10退出帮助系统）："NOR);
                ob->set_temp("block_msg/all");
                input_to("help_new", ob);
        }
}
/*
void help_map(string num,object ob)
{
        if( num == "1" )
        {
                write(CLR);
                cat("/doc/map/");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "2" )
        {
                write(CLR);
                cat("/doc/topics2");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "3" )
        {
                write(CLR);
                cat("/doc/topics1");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "4" )
        {
                write(CLR);
                cat("/doc/topics1");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "5" )
        {
                write(CLR);
                cat("/doc/topics1");
                ob->delete_temp("block_msg/all");
        }
        else if( num == "q" || num == "Q" ) quit_help(ob);
        else
        {
                ob->delete_temp("block_msg/all");
                write(HIR"\n 对不起，没有这个选项！\n"NOR);
                write(CYN"\n 请输入选择项（1-9选择相应项目，10退出帮助系统）："NOR);
                ob->set_temp("block_msg/all");
                input_to("help_new", ob);
        }
}
*/
void quit_help(object ob)
{
        ob->delete_temp("block_msg/all");
        write(HIC"\n 谢谢使用帮助系统，祝您在鹿鼎记里快乐！\n\n"NOR);
        return;
}

int help(object me)
{
        write(@HELP
指令格式：help <主题>              例如：> help cmds
          help <函数名称>()        例如：> help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
        );
        return 1;
}

