// edit.c

// writed by shadow



#include "/doc/help.h"



inherit F_CLEAN_UP;


inherit F_DBASE;
void create()
{
        seteuid(getuid());
        set("name", "�༭ָ��");
        set("id", "edit");
         set("channel_id","���߱༭");
}
int main(object me, string file)

{

	if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");



	if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");



	seteuid(geteuid(me));

	ed(resolve_path(me->query("cwd"), file));
    CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+"("+me->query("id")+")"+"��д��"+resolve_path(me->query("cwd"),file)+"��");

	log_file("static/editfile", sprintf("%s%s edit %s (%s)\n",

		me->query("name"),

		"(" + me->query("id") + ")" ,

		resolve_path(me->query("cwd"), file),

		ctime(time())

		) );

	return 1;

}



int help(object me)

{

  write(@HELP

ָ���ʽ : edit <����>, edit here



���ô�һָ���ֱ�������ϱ༭������

HELP

    );

    return 1;

}

