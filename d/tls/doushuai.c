inherit ROOM;

void create()
{
        set("short", "���ʴ�ʿԺ");
        set("long",@LONG
����һ��ΰ������ܵ�����Զ�ĵط���������ԶԶ���Կ�����������
����ɮ����֮������Ĳ���á����ǳ��˲������״���ĵط�������ò�Ҫ
���Դ��롣������ȷ���ܸ���ɮ�Ǵ�ȥ����Ϣ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"shengdian",
                "southup" : __DIR__"banruotai",
                "southdown" : __DIR__"wuchang",
                ]));
//      set("objects",([
//                __DIR__"obj/xianglu" : 1,
//        ]));
        set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}


void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"munitang")) )
        room = load_object(__DIR__"munitang");
    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
        room->delete("exits/east");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/west"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"munitiang")) )
        room = load_object(__DIR__"munitang");
        
         
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/west"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!(room = find_object(__DIR__"munitang")))
        room = load_object(__DIR__"munitang");
        
    if(objectp(room))
    {
                if((int)room->query_temp("person_inside")<=0)
                {
                        room->delete_temp("person_inside");
                        set("exits/west", __DIR__"munitang");
                        message_vision("$N����ذ����ƿ���\n", this_player());
                        room->set("exits/east", __FILE__);
                        remove_call_out("close_men");
                        call_out("close_men", 10);
                }
                else 
                {
                        message_vision("$N������ƿ���ȴ�����ű��˴����������ˡ�\n",this_player());
                }
        }

    return 1;
}

string look_men()
{
    object room;

    if (query("exits/east"))
                return ("���Ϲ��˸����ӣ�Ĳ���á�����������\n");

    if(!( room = find_object(__DIR__"munitang")) )
        room = load_object(__DIR__"munitang");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
                return ("���Ϲ��˸����ӣ�����һ�Ρ���������!\n");
    } 
    
    return ("���Ϲ��˸����ӣ������³��Ͻ���֮����\n");
}

int valid_leave(object me, string dir)
{
        object room;
        
        if(!( room = find_object(__DIR__"munitang")) )
                room = load_object(__DIR__"munitang");

        if(objectp(room) && dir == "west")
        {
                room->add_temp("person_inside", 1);
                remove_call_out("force_open");
                call_out("force_open", 299, room);
        }               

        return ::valid_leave(me, dir);
}

int force_open(object room)
{
        if(!objectp(room))
                return 0;
    if((int)room->query_temp("person_inside") <= 0)
                return 0;
    
        room->delete_temp("person_inside");
    set("exits/west", __DIR__"munitang");
    room->set("exits/east", __FILE__);
    message("vision", "����ͻȻ������صĽŲ�������Զ����������ǰͣ������������\n"
        "��  ž�ذ��Ŵ򿪣����ͷ������һ�����ɣ���������˻�����ȥ�����ų��������ˣ�\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}

