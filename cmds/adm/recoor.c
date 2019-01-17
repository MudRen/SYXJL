inherit F_CLEAN_UP;

int doOneRoom(object room);

int main(object me, string arg)
{
	seteuid(getuid(me));
	doOneRoom(environment(me));

	return 1;
}

int doOneRoom(object room)
{
	mapping exits;
	string *directions;
	string dir;
	string file;
	object nextroom;
	int x,y,z,j;

	if(!room->query("coor")) return 1;
	if(room->query("already_coordinated")) return 1;
	reset_eval_cost();
	x=(int)room->query("coor/x");
	y=(int)room->query("coor/y");
	z=(int)room->query("coor/z");
	file = read_file(base_name(room)+".c");
	file = replace_string(file,"setup();",
	sprintf("set(\"coor/x\",%d);\n	set(\"coor/y\",%d);\n	set(\"coor/z\",%d);\n	setup();",x,y,z));
	if(write_file(base_name(room)+".c",file,1)) {
		write("Finished room "+ base_name(room) +"\n");
		room->set("already_coordinated",1);
	}
	exits = room->query("exits");
	if(!mapp(exits) || !sizeof(exits)) return 1;
	directions = keys(exits);
	for(j=0;j<sizeof(directions);j++) {
		dir = directions[j];
                if(!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);
		call_out("doOneRoom", 0, nextroom);
	}
	return 1;
}
