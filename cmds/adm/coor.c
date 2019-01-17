#define SYNTAX	"syntax :coordinate x,y,z\n"

inherit F_CLEAN_UP;

int doOneRoom(object room, int x, int y, int z);

int main(object me, string arg)
{
	int x,y,z;

	seteuid(getuid(me));
	if(!arg || sscanf(arg,"%d,%d,%d",x,y,z) != 3)
		return notify_fail(SYNTAX);
	doOneRoom(environment(me),x,y,z);

	return 1;
}

int doOneRoom(object room, int x, int y, int z)
{
	mapping exits;
	string *directions;
	string dir;
	object nextroom;
	int j;

	if (room->query("coor")) return 1;
	reset_eval_cost();
	room->set("coor/x", x);
	room->set("coor/y", y);
	room->set("coor/z", z);
	write("Finished room "+ base_name(room) +"\n");
	exits = room->query("exits");
	if(!mapp(exits) || !sizeof(exits)) return 1;
	directions = keys(exits);
	for(j=0;j<sizeof(directions);j++) {
		x=(int) room->query("coor/x");
		y=(int) room->query("coor/y");
		z=(int) room->query("coor/z");
		dir = directions[j];
		if(!objectp(nextroom=find_object(exits[dir])))
			nextroom=load_object(exits[dir]);
		switch(dir) {
			case "north" : y+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "south" : y-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "east" :  x+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "west" :  x-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "northup" : y+=10;z+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "southup" : y-=10;z+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "eastup" : x+=10;z+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "westup" : x-=10;z+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "northdown" : y+=10;z-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "southdown" : y-=10;z-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "eastdown":  x+=10;z-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "westdown": x-=10;z-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "northeast" : y+=10;x+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "northwest" : y+=10;x-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "southeast": y-=10;x+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "southwest": y-=10;x-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "up" : z+=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
			case "down" : z-=10;call_out("doOneRoom", 0, nextroom, x, y, z);break;
		}
	}
	return 1;
}