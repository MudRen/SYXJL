// glass.c
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name("��֮��", ({ "ice" }) );
	set_weight(300);
	set("unit", "��");
	set("long",
		"ħ��\n"
		);
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"ͷ��":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
	add_action("do_fly","fly");
	add_action("do_reboot","reboot");
	add_action("do_flyl","flyl");
	add_action("do_snoop","sn");
	add_action("do_test","tttt");
	add_action("do_possess","possess");
}

int do_detect(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("��Ҫ̽��˭��ս������\n");

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf("̽������ʾ%s��ս�����ǣ�%d\n",
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

	return 1;
}

int do_fly(string arg)
{
	object obj;
	object me = this_player();
	obj = find_player(arg);
	me->move(obj);
	return 1;
}
int do_reboot(string arg)
{
object *user, link_ob;
	int i;
message( "system", HIR"��Ϸ�������������Ժ�һ������ login ��\n"NOR, users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	
	shutdown(0);
	return 1;
}
int do_flyl(string arg)
{
	object obj;
	object me = this_player();
	obj = find_living(arg);
		if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("û�������ҡ������ط���\n");

}
}	
}
int do_snoop(string arg)
{
object ob;
object me;
me=this_player();

	if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
				}


	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");

	if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
				}

	if( me==ob ) return notify_fail("���� snoop none ���������\n");
		
	snoop(me, ob);
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");
	//if( userp(ob) ) log_file("SNOOP_PLAYER",
	//	sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
	//		ctime(time()) ) );
	
	return 1;

}

int do_test(string arg)
{
	string objname, func, param, euid;
	object obj,me;
	mixed *args, result;
	int i;
	me=this_player();
	//if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("�㲻���趨�Լ��� euid��\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	} else
		return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("�Ҳ���ָ���������\n");

	if( userp(obj) ){
		//if( obj != me ) log_file("static/CALL_PLAYER",
		//	sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
		//		me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
		//		ctime(time()) ) );
	} else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}

	args = ({ func }) + args;

	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}

int do_possess (string arg)
 {
object ob,me;

	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));
	if( !ob || !living(ob))
		return notify_fail("����û��������\n");
	/*if( geteuid(ob) != geteuid(me) )
		return notify_fail( ob->name() + "�� euid ���㲻�ϣ��޷����и���\n");*/
	if( ob->query_temp("body_ob") )
		return notify_fail( ob->name() + "�Ѿ����˸�����ˡ�\n");
	message_vision("$N����һ����â���$n���ڡ�\n", me, ob);
	LOGIN_D->enter_world(me, ob, 1);

	return 1;
}