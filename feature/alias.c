// alias.c
// From ES2
// Modified for XKX by Xiang (12/15/95)
#include <ansi.h>
#define MAX_REPEAT 30
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;

string process_input(string str)
{
        string *args, cmd, argstr;
        int i, j;
        object ob = this_player();
        if( ob->query_temp("disable_inputs") )   return "ʲ�᣿\n";

        if( str==last_input && str != "" && str != "read new") {
                repeat_cnt++;
                if( repeat_cnt > MAX_REPEAT ) {
                        tell_object( this_object(),
                                "\n��ϵͳ����������ָ�\n\n"
                                HIG"\n\n��һ�����������ָͬ��̫���ˡ�\n\n"NOR
                                "\n\n\nͻȻ����������ܲ���һ����ɫ�������������������㣡\n\n");
                        command("quit");
                }
        } else {
                repeat_cnt = 0;
                last_input = str;
        }

        if(this_object()->query_temp("disable_inputs"))
                return "ʲ�᣿\n";

//      str = CONVERT_D->input(str,this_object());

        if( this_object()->query_encoding() )
                str = LANGUAGE_D->toGB(str);

        if( str[0]=='!' ) {
                if( pointerp(history) && sizeof(history) ) {
                        if( sscanf(str, "!%d", i) )
                                str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
                        else
                                str = history[last_cmd];
                } else
                        return "";
        } else {
                if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
                last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
                history[last_cmd] = str;
        }

        if( mapp(alias) ) {

                if( !undefinedp(alias[str]) )
                        return replace_string( alias[str], "$*", "" );

                if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
                        cmd = replace_string( alias[cmd], "$*", argstr );
                        args = explode(argstr, " ");
                        if( (j = sizeof(args)) )
                                for(i=0; i<j; i++)
                                        cmd = replace_string( cmd, "$" + (i+1), args[i] );
                        return cmd;
                }
        }

        return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
        if( !replace ) {
                if( mapp(alias) ) map_delete(alias, verb);
                return 1;
        } else {
                if( !mapp(alias) ) alias = ([ verb:replace ]);
                else if( sizeof(alias) > MAX_ALIASES )
                        return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
                else alias[verb] = replace;
                return 1;
        }
}

mapping query_all_alias()
{
        return alias;
}


