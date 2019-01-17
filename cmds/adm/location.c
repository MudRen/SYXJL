/*
it generates a file "location" in /task

"location" is being renamed to dynamic_location
*/

inherit F_CLEAN_UP;

#define SYNTAX	"ָ���ʽ��location <dir>\n"

int do_one_object(object obj);

int main(object me, string arg)
{
	int i;
	string direc,*dir, roomname;
	string status;
	object room;

	status = wizhood(me);
	if( me!=this_player() || wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
	if( !arg ) return notify_fail(SYNTAX);
	if( sscanf(arg, "%s", direc)!=1 )
		return notify_fail(SYNTAX);
	seteuid(getuid(me));
	dir = get_dir(arg+"/");
        for(i=0; i<sizeof(dir); i++) {
		if( sscanf(dir[i],"%s.c", roomname) != 1) continue;
		if( !(room = find_object(arg+"/"+roomname+".c")))
			room = load_object(arg+"/"+roomname+".c");
		write("working on "+roomname+"\n");
		do_one_object(room);
	}

	return 1;
}

int do_one_object(object room)
{
	if(room->query("coor") && !room->query("no_fight"))
		write_file("/task/location", sprintf("%s\n", base_name(room)+".c"));

	return 1;
}