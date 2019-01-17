/* grep.c
 * 98-10-26
 * modify name to femote.c
 * make code less
 * by ken@XAJH
 */

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
        mapping emote;
        string *e, *loop;
        string result="", msg;
        int i,count=0;

        loop = ({ "others_target", "others_self", "others" });
        if( !arg )
                return help(me);

        e = sort_array( EMOTE_D->query_all_emote(), 1);

        for(i=0; i<sizeof(e); i++) {
                emote = EMOTE_D->query_emote(e[i]);
                for( int j=0; j<sizeof(loop); j++ ) {
                        msg = emote[ loop[j] ];
                        if( msg && strsrch(msg, arg) >=0 ) {
                                result += sprintf("emote ��: %s\n����: %s\n", e[i], msg);
                                count ++;
                        }
                }
        }

        if(  result == "" )
                return notify_fail(MUD_NAME" ���޷��ϲ�ѯ������ emote.\n");
        else
                result = "\n��ѯ���"
                                "\n------------------------------------------------------------\n"
                                + result;
        result = replace_string(result, "$n", "(�Է�)");
        result = replace_string(result, "$N", me->name(1));
        result = replace_string(result, "$P", "��");
        result = replace_string(result, "$p", "(��/��)");
        result = replace_string(result, "$S", RANK_D->query_self(me));
        result = replace_string(result, "$s", RANK_D->query_self_rude(me));
        result = replace_string(result, "$R", "(�Է������)");
        result = replace_string(result, "$r", "(�Է������)");
        result = replace_string(result, "$C", "(�Լ����س�)");
        result = replace_string(result, "$c", "(�Է����س�)");

        result += "------------------------------------------------------------\n";
        result += sprintf("��%s�У�������%s���� emote ���� %d ����\n",
                                        MUD_NAME, arg, count );
        me->start_more(result);
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : femote �ؼ���
���ܣ��г�Ŀǰ���к�ָ���ؼ��ֵ� emote.

Dean, ken@XAJH
HELP
    );
    return 1;
}
